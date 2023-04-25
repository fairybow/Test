#pragma once

#include "editor/Editor.hpp"
#include "preview/Preview.hpp"
#include "splitter/Splitter.h"
#include "tree/Tree.hpp"

#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);

private:
	QMenuBar* m_menuBar = new QMenuBar(this);
	QStatusBar* m_statusBar = new QStatusBar(this);
	Tree* m_tree = new Tree;
	Editor* m_editor = new Editor;
	Preview* m_preview = new Preview;
	Splitter* m_splitter = new Splitter(Qt::Horizontal, { m_tree, m_editor, m_preview }, this);
};
