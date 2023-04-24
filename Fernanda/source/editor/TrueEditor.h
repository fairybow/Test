#pragma once

#include "LineNumberArea.h"

#include <QPainter>
#include <QPlainTextEdit>
#include <QTextBlock>

class TrueEditor : public QPlainTextEdit
{
	Q_OBJECT

public:
	inline TrueEditor(QWidget* parent = nullptr)
		: QPlainTextEdit(parent), m_lineNumberArea(nullptr)
	{
		connect(this, &TrueEditor::blockCountChanged, this, [&](int newBlockCount) {
				if (m_lineNumberArea == nullptr) return;
				updateLineNumberAreaWidth(newBlockCount);
			});
		connect(this, &TrueEditor::updateRequest, this, [&](const QRect& rect, int dy) {
				if (m_lineNumberArea == nullptr) return;
				updateLineNumberArea(rect, dy);
			});
		connect(this, &TrueEditor::cursorPositionChanged, this, [&]() {
				if (m_lineNumberArea == nullptr) return;
				highlightCurrentLine();
			});
		updateLineNumberAreaWidth(0);
		highlightCurrentLine();
	}

	inline void setLineNumberArea(LineNumberArea* lineNumberArea)
	{
		m_lineNumberArea = lineNumberArea;
	}

	inline void lineNumberAreaPaintEvent(QPaintEvent* event)
	{
		QPainter painter(m_lineNumberArea);
		auto block = firstVisibleBlock();
		auto block_number = block.blockNumber();
		auto top = qRound(blockBoundingGeometry(block).translated(contentOffset()).top());
		auto bottom = top + qRound(blockBoundingRect(block).height());
		while (block.isValid() && top <= event->rect().bottom()) {
			if (block.isVisible() && bottom >= event->rect().top()) {
				auto number = QString::number(block_number + 1);
				painter.drawText(0, top, m_lineNumberArea->width(), fontMetrics().height(), Qt::AlignRight, number);
			}
			block = block.next();
			top = bottom;
			bottom = top + qRound(blockBoundingRect(block).height());
			++block_number;
		}
	}

	inline int lineNumberAreaWidth()
	{
		return (m_lineNumberArea == nullptr || !m_lineNumberArea->isVisible()) ? 0 : [&] {
			auto digits = 1;
			auto max = qMax(1, blockCount());
			while (max >= 10) {
				max /= 10;
				++digits;
			}
			auto space = 3 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;
			return space;
		}();
	}

protected:
	inline virtual void resizeEvent(QResizeEvent* event) override
	{
		QPlainTextEdit::resizeEvent(event);

		QRect cr = contentsRect();
		m_lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
	}

private:
	LineNumberArea* m_lineNumberArea;

	inline void updateLineNumberAreaWidth(int newBlockCount)
	{
		setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
	}

	inline void highlightCurrentLine()
	{
		QList<QTextEdit::ExtraSelection> extraSelections;

		if (!isReadOnly()) {
			QTextEdit::ExtraSelection selection;

			QColor lineColor = QColor(Qt::yellow).lighter(160);

			selection.format.setBackground(lineColor);
			selection.format.setProperty(QTextFormat::FullWidthSelection, true);
			selection.cursor = textCursor();
			selection.cursor.clearSelection();
			extraSelections.append(selection);
		}

		setExtraSelections(extraSelections);
	}

	inline void updateLineNumberArea(const QRect& rect, int dy)
	{
		if (dy)
			m_lineNumberArea->scroll(0, dy);
		else
			m_lineNumberArea->update(0, rect.y(), m_lineNumberArea->width(), rect.height());

		if (rect.contains(viewport()->rect()))
			updateLineNumberAreaWidth(0);
	}
};
