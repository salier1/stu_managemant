#pragma once
#include "BasicWidget.h"
#include"string"
#include "easyx.h"
class Pushbutton :
    public BasicWidget
{
public:
    Pushbutton(const std::string& text,int x=0, int y=0, int w = 150, int h = 30);
    void show() override;//������ʾ��
    bool isin();//����������
    bool isclick();//�����

    void eventloop(const ExMessage& msg); //�������
private:
    std::string m_text;
    ExMessage m_msg;
    bool flag=false;
    COLORREF normal_c= RGB(232, 232, 236);
    COLORREF hover_c= RGB(200, 200, 200);
    COLORREF cur_c= RGB(232, 232, 236);

};

