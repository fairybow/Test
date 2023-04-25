#pragma once

#include <QTreeView>

class Tree : public QTreeView
{
	Q_OBJECT

public:
	Tree(QWidget* parent = nullptr)
		: QTreeView(parent)
	{
		//
	}

private:
	//
};