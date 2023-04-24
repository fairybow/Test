#pragma once

#include "TrueEditor.hpp"

class Editor : public QWidget
{
	Q_OBJECT

public:
	inline Editor(QWidget* parent = nullptr)
		: QWidget(parent)
	{
		//
	}

private:
	TrueEditor m_trueEditor = new TrueEditor(this);
};
