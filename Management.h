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
	void run();//����
	void display();//��ʾ
	void add();//����
	void erase();//ɾ��
	void modify();//��
	void search();//��
	void analysis();//����
	int menu();//�˵�

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
	//������ť
	std::vector<Pushbutton*>menu_btns;
	std::vector<Pushbutton*>add_btns;
	std::vector<Pushbutton*>erase_btns;
	std::vector<Pushbutton*>sreach_btns;
	std::vector<Pushbutton*>modify_btns;


private: //��ȡ�ļ�
	std::string m_header;
	std::vector<Course>vec_cou;

	//�鿴ѧ��
	Table* m_showTable;

	//�洢����
	char num[100] = { 0 };
	char name[100] = { 0 };
	char credit[100] = { 0 };
	char score[100] = { 0 };
	int p = 1000;
	bool flag = false;

};

