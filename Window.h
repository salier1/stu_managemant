#include "easyx.h"
#include "string"
#pragma once
class Window
{
public:
	Window(int width, int height, int flag);//��������
	int exec();//��ֹ����
	void setWindowTitle(const std::string& title);//���ô�������

	//���·�װeasyx�⺯��
	static int width();
	static int height();
	static void clear();
	static void beginDraw();
	static void flushDraw();
	static void endDraw();

	//������������
	inline static bool hasMsg() { return ::peekmessage(&m_msg, EM_MOUSE | EM_KEY); }
	inline static const ExMessage& getMsg() { return m_msg; }



private:
	HWND m_handle; //���ھ��
	static ExMessage m_msg; //�����Ϣ


};


