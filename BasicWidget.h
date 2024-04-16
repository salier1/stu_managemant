#pragma once
class BasicWidget
{
public:
	//����
	BasicWidget(int x, int y, int w, int h);
	virtual ~BasicWidget(){};
	int width();
	int height();
	void setFixedsize(int w,int h);
	//λ��
	int x();
	int y();
	void move(int x,int y);

	virtual void show() = 0;

protected:
	int m_x;
	int m_y;
	int m_w;
	int m_h;



};

