#pragma once

#include "../Layout.hpp"
#include "WebEngineView.hpp"

class Preview : public QWidget
{
public:
	inline Preview(QWidget* parent = nullptr)
		: QWidget(parent)
	{
		setContentsMargins(0, 0, 0, 0);
		Layout::set(this, m_view);
	}

private:
	WebDocument m_content;
	WebEngineView* m_view = new WebEngineView(m_content, this);

	inline QString url() { return QString("qrc:/Test.html"); }
};
