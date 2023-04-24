#pragma once

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

private:
	//
};
