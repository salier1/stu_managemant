#pragma once
#include "Window.h"
#include "vector"
#include "Pushbutton.h"
#include "string"
#include "Course.h"
#include "Table.h"
class Management
{

public:
	Management();

	
	enum Operator
	{
		Display,
		Add,
		Erase,
		Modify,
		Search,
		Analysis,
		Menu=77
	};

	int op = Menu;
	void run();//启动
	void display();//显示
	void add();//增加
	void erase();//删除
	void modify();//改
	void search();//找
	void analysis();//分析
	int menu();//菜单

	void drawBackground(int t);
	void eventloop();
	void readfile(const std::string& filename);
	void savefile(const std::string& filename);


private:
	ExMessage m_msg;
	IMAGE m_bk;
	IMAGE m_bk2;
	IMAGE m_stu1;
	IMAGE m_stu2;
	//几个按钮
	std::vector<Pushbutton*>menu_btns;
	std::vector<Pushbutton*>add_btns;
	std::vector<Pushbutton*>erase_btns;
	std::vector<Pushbutton*>sreach_btns;
	std::vector<Pushbutton*>modify_btns;


private: //读取文件
	std::string m_header;
	std::vector<Course>vec_cou;

	//查看学生
	Table* m_showTable;

	//存储输入
	char num[100] = { 0 };
	char name[100] = { 0 };
	char credit[100] = { 0 };
	char score[100] = { 0 };
	int p = 1000;
	bool flag = false;

};

