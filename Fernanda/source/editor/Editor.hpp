#pragma once

#include "../Layout.hpp"
#include "TrueEditor.hpp"

#include <QVector>
#include <QWidget>

class Editor : public QWidget
{
	Q_OBJECT

public:
	inline Editor(QWidget* parent = nullptr)
		: QWidget(parent)
	{
		Layout::setStack(this, { m_trueEditor }); // shadow, overlay, trueEditor, underlay
	}

private:
	TrueEditor* m_trueEditor = new TrueEditor(this);
};
