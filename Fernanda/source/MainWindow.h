#include "preview/Preview.hpp"
#include "splitter/Splitter.h"

#include <QMainWindow>
#include <QMenuBar>
#include <QPlainTextEdit>
#include <QStatusBar>
#include <QTreeView>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);

private:
	QMenuBar* m_menuBar = new QMenuBar(this);
	QTreeView* m_treeView = new QTreeView;
	QPlainTextEdit* m_editor = new QPlainTextEdit;
	Preview* m_preview = new Preview;
	Splitter* m_splitter = new Splitter(Qt::Horizontal, { m_treeView, m_editor, m_preview }, this);
	QStatusBar* m_statusBar = new QStatusBar(this);
};
