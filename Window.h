#include "easyx.h"
#include "string"
#pragma once
class Window
{
public:
	Window(int width, int height, int flag);//创建窗口
	int exec();//防止闪退
	void setWindowTitle(const std::string& title);//设置窗口名字

	//重新封装easyx库函数
	static int width();
	static int height();
	static void clear();
	static void beginDraw();
	static void flushDraw();
	static void endDraw();

	//按键和鼠标操作
	inline static bool hasMsg() { return ::peekmessage(&m_msg, EM_MOUSE | EM_KEY); }
	inline static const ExMessage& getMsg() { return m_msg; }



private:
	HWND m_handle; //窗口句柄
	static ExMessage m_msg; //鼠标消息


};


