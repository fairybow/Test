#pragma once

#include <QPaintEvent>
#include <QPlainTextEdit>

class TrueEditor : public QPlainTextEdit
{
	Q_OBJECT

public:
	inline TrueEditor(QWidget* parent = nullptr)
		: QPlainTextEdit(parent)
	{
		//
	}

	inline void lineNumberAreaPaintEvent(QPaintEvent* event)
	{
		/*QPainter painter(m_lineNumberArea);
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
		}*/
	}

	inline int lineNumberAreaWidth()
	{
		/*if (m_lineNumberArea->isVisible()) {
			auto digits = 1;
			auto max = qMax(1, blockCount());
			while (max >= 10) {
				max /= 10;
				++digits;
			}
			auto space = 3 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;
			return space;
		}*/
		return 0;
	}

private:
	//
};
