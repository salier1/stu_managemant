#include "Pushbutton.h"
#include "string"

Pushbutton::Pushbutton(const std::string& text="button", int x, int y, int w, int h)
	:BasicWidget(x, y, w, h), m_text(text)
{

}
//显示按钮
void Pushbutton::show()
{
	setfillcolor(cur_c);
	::fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, 10, 10);
	//文字居中显示
	settextcolor(BLACK);
	int tx = m_x+(m_w - textwidth(m_text.c_str())) / 2;
	int ty = m_y+(m_h - textheight(m_text.c_str())) / 2;

	::outtextxy(tx, ty, m_text.c_str());
}

bool Pushbutton::isin()
{
	if (m_msg.x >= m_x && m_msg.x <= m_x + m_w && m_msg.y >= m_y && m_msg.y <= m_y + m_h)
	{
		return true;
	}
	return false;
}

bool Pushbutton::isclick()
{
	if (isin())
	{
		if (m_msg.message == WM_LBUTTONDOWN)
		{
			return true;
		}
	}
	return false;
}

void Pushbutton::eventloop(const ExMessage& msg)
{
	m_msg = msg; 
	if (!isin())
	{
		cur_c = normal_c;
		flag = false;
	}
	else
	{
		cur_c = hover_c;
		flag = true;
	}
}

