#include "Management.h"
#include "iostream"
#include "conio.h"
#include "fstream"
#include "sstream"
#include "Course.h"
#include "Table.h"
#include "easyx.h"
using namespace std;
Management::Management()
{
	::settextstyle(20, 0, "����");
	readfile("./images/students.txt");
	menu_btns.push_back(new Pushbutton("�鿴�γ�"));
	menu_btns.push_back(new Pushbutton("��ӿγ�"));
	menu_btns.push_back(new Pushbutton("ɾ���γ�"));
	menu_btns.push_back(new Pushbutton("�޸Ŀγ�"));
	menu_btns.push_back(new Pushbutton("���ҿγ�"));
	menu_btns.push_back(new Pushbutton("�����ɼ�"));
	menu_btns.push_back(new Pushbutton("�˳�ϵͳ"));
	add_btns.push_back(new Pushbutton("�γ̴���"));
	add_btns.push_back(new Pushbutton("�γ�����"));
	add_btns.push_back(new Pushbutton("�γ�ѧ��"));
	add_btns.push_back(new Pushbutton("�γ�����"));
	add_btns.push_back(new Pushbutton("��ӿγ�"));
	erase_btns.push_back(new Pushbutton("���Ʋ���"));
	erase_btns.push_back(new Pushbutton("ɾ���γ�"));
	sreach_btns.push_back(new Pushbutton("�������"));
	sreach_btns.push_back(new Pushbutton("���Ʋ���"));

	modify_btns.push_back(new Pushbutton("�޸Ĵ���"));
	modify_btns.push_back(new Pushbutton("�޸�����"));
	modify_btns.push_back(new Pushbutton("�޸�ѧ��"));
	modify_btns.push_back(new Pushbutton("�޸ķ���"));
	modify_btns.push_back(new Pushbutton("�޸����"));
	modify_btns.push_back(new Pushbutton("����γ�����"));

	for (int i = 0; i < menu_btns.size(); i++)
	{
		menu_btns[i]->setFixedsize(250, 50);
		//��ť����
		int bx = (Window::width() - menu_btns[i]->width()) / 2;
		int space = (Window::height() - menu_btns[i]->height() * menu_btns.size()) / 2;
		int by = i * menu_btns[i]->height() + space;

		menu_btns[i]->move(bx,by);
	}
	for (int i = 0; i < add_btns.size(); i++)
	{
		add_btns[i]->setFixedsize(150, 30);
		//��ť����
		int by = (Window::width() - add_btns[i]->width()) / 2+150;
		int space = (Window::width() - add_btns[i]->width() * add_btns.size()) / 2;
		int bx = i * add_btns[i]->width() + space;

		add_btns[i]->move(bx, by);
	}
	for (int i = 0; i < erase_btns.size(); i++)
	{
		erase_btns[i]->setFixedsize(150, 30);
		//��ť����
		int by = (Window::width() - erase_btns[i]->width()) / 2 + 150;
		int space = (Window::width() - erase_btns[i]->width() * erase_btns.size()) / 2;
		int bx = i * erase_btns[i]->width() + space;

		erase_btns[i]->move(bx, by);
	}
	for (int i = 0; i < sreach_btns.size(); i++)
	{
		sreach_btns[i]->setFixedsize(150, 30);
		//��ť����
		int by = (Window::width() - sreach_btns[i]->width()) / 2 + 150;
		int space = (Window::width() - sreach_btns[i]->width() * sreach_btns.size()) / 2;
		int bx = i * sreach_btns[i]->width() + space;

		sreach_btns[i]->move(bx, by);
	}
	for (int i = 0; i < modify_btns.size()-1; i++)
	{
		modify_btns[i]->setFixedsize(150, 30);
		//��ť����
		int by = (Window::width() - modify_btns[i]->width()) / 2 + 150;
		int space = (Window::width() - modify_btns[i]->width() * (modify_btns.size()-1)) / 2;
		int bx = i * modify_btns[i]->width() + space;

		modify_btns[i]->move(bx, by);
	}
	modify_btns[5]->setFixedsize(250, 50);
	modify_btns[5]->move((Window::width() - modify_btns[5]->width()) / 2, (Window::height() - modify_btns[5]->height()) / 2-100);

	loadimage(&m_bk, "./images/bg_school_koutei.png", Window::width(), Window::height());
	loadimage(&m_bk2, "./images/bg_natural_umi.jpg", Window::width(), Window::height());
	loadimage(&m_stu1, "./images/ryuugakusei_seifuku_asia_man.png", menu_btns[1]->height() / 2, menu_btns[1]->height());
	loadimage(&m_stu2, "./images/ryuugakusei_seifuku_asia_man1.png", menu_btns[1]->height() / 2, menu_btns[1]->height());

	//��ʼ���鿴ѧ�����
	m_showTable = new Table;
	m_showTable->setRowCount(16);
	m_showTable->setHeader(m_header);
	m_showTable->move((Window::width() - m_showTable->width())/2, 50);//���б��
	for (auto& val : vec_cou)
	{
		m_showTable->insertData(val.tostring());
	}
}
void Management::run()
{
	Window::beginDraw();
	while (true)
	{
		Window::clear();


		if(Window::hasMsg())
		{
			m_msg=Window::getMsg();
			switch (m_msg.message)
			{
			case WM_KEYDOWN://����
				if (m_msg.vkcode==VK_ESCAPE)
				{
					op = Menu;
					memset(num, 0, 100);
					memset(name, 0, 100);
					memset(score, 0, 100);
					memset(credit, 0, 100);
					p = 1000;
					flag = false;
				}
				break;
			default://���
				eventloop();
				break;
			}
		}

		switch (op)
		{
		case Menu:
			drawBackground(1);
			op = menu();
			break;
		case Management::Display:
			display();
			break;
		case Management::Add:
			drawBackground(2);
			add();
			break;
		case Management::Erase:
			drawBackground(2);
			erase();
			break;
		case Management::Modify:
			drawBackground(2);
			modify();
			break;
		case Management::Search:
			drawBackground(2);
			search();
			break;
		case Management::Analysis:
			drawBackground(2);
			analysis();
			break;
		default:
			savefile("./images/test.txt");
			exit(6666);
			break;
		}
		Window::flushDraw();
	}

	Window::endDraw();
}

void Management::display()
{

	drawBackground(2);
	m_showTable->show();
}

void Management::add()
{




	for (int i = 0; i < add_btns.size(); i++)
	{
		add_btns[i]->show();
		add_btns[i]->eventloop(m_msg);
		string n1 = num;
		string n2 = name;
		string n3 = credit;
		string n4 = score;
		if (add_btns[i]->isclick())
		{
			switch (i)
			{
			case 0:
				InputBox(num, 100, "������γ̴���");
				break;
			case 1:
				InputBox(name, 100, "������γ�����");
				break;
			case 2:
				InputBox(credit, 100, "������γ�ѧ��");
				break;
			case 3:
				InputBox(score, 100, "������γ�����");
				break;
			default:
				if (!n1.empty() && !n2.empty() && !n3.empty() && !n4.empty())
				{
					Course cou;
					m_showTable->insertData(n1 + "\t" + n2 + "\t" + n3 + "\t" + n4);
					stringstream ss(n1 + "\t" + n2 + "\t" + n3 + "\t" + n4);
					ss >> cou.number >> cou.name >> cou.credit >> cou.grade;
					vec_cou.push_back(cou);
					memset(num, 0, 100);
					memset(name, 0, 100);
					memset(score, 0, 100);
					memset(credit, 0, 100);
					op = Menu;
					HWND hWND = GetHWnd();
					SetWindowText(hWND, "Sauce");
					MessageBox(hWND, "�������", "��ӳɹ�", MB_OKCANCEL);
				}
				else
				{
					HWND hWND = GetHWnd();
					SetWindowText(hWND, "Sauce");
					MessageBox(hWND, "����Ҫ�������е���Ϣ", "���ʧ��", MB_OKCANCEL);
				}

				break;
			}
		}


		m_showTable->drawHeader();
		m_showTable->drawAddgrid();
		m_showTable->drawAdddata(n1, n2, n3, n4);



	}




}

void Management::erase()
{



	for (int i = 0; i < erase_btns.size(); i++)
	{
		erase_btns[i]->show();
		erase_btns[i]->eventloop(m_msg);


		if (erase_btns[i]->isclick())
		{
			switch (i)
			{
			case 0:
				InputBox(name, 100, "������γ�����");
				flag = false;
				for (size_t i = 0; i < vec_cou.size(); i++)
				{
					if (vec_cou[i].name == name)
					{
						p = i;
						flag = true;
						//cout << p << endl;
						break;

					}


				}
				if (!flag)
				{
					HWND hWND = GetHWnd();
					SetWindowText(hWND, "Sauce");
					MessageBox(hWND, "������ȷ�Ŀγ�����", "����ʧ��", MB_OKCANCEL);
				}
				
				break;
			case 1:
				if (p >= 0 && p <= vec_cou.size())
				{
					vec_cou.erase(vec_cou.begin() + p);
					m_showTable->eraseData(p);
					memset(name, 0, 100);
					p = 1000;
					HWND hWND = GetHWnd();
					SetWindowText(hWND, "Sauce");
					MessageBox(hWND, "����˳�", "ɾ���ɹ�", MB_OKCANCEL);
					op = Menu;

				}
				else
				{
					HWND hWND = GetHWnd();
					SetWindowText(hWND, "Sauce");
					MessageBox(hWND, "δ�ҵ���¼", "ɾ��ʧ��", MB_OKCANCEL);
				}

				break;

			default:

				break;
			}
		}


		m_showTable->drawHeader();
		m_showTable->drawAddgrid();
		if(p>=0&&p<=vec_cou.size())m_showTable->drawAdddata2(m_showTable->findData(p));


	}





}

void Management::modify()
{

	for (int i = 0; i < modify_btns.size(); i++)
	{
		if (p >= 0 && p <= vec_cou.size() || i == 5)
		{
			modify_btns[i]->show();
			modify_btns[i]->eventloop(m_msg);
		}


		stringstream ss1;
		if (modify_btns[i]->isclick())
		{
			switch (i)
			{
			case 0:
				InputBox(num, 100, "������γ̴���");
				vec_cou[p].number = num;
				m_showTable->modifyData(vec_cou[p].tostring(), p);
				break;
			case 1:
				InputBox(name, 100, "������γ�����");
				vec_cou[p].name = name;
				m_showTable->modifyData(vec_cou[p].tostring(), p);
				break;
			case 2:
				InputBox(credit, 100, "������γ�ѧ��");
				ss1.str(credit);
				ss1 >> vec_cou[p].credit;
				m_showTable->modifyData(vec_cou[p].tostring(), p);
				break;
			case 3:
				InputBox(score, 100, "������γ�ѧ��");
				ss1.str(score);
				ss1 >> vec_cou[p].grade;
				m_showTable->modifyData(vec_cou[p].tostring(), p);
				break;
			case 4:
				memset(num, 0, 100);
				memset(name, 0, 100);
				memset(score, 0, 100);
				memset(credit, 0, 100);
				p = 1000;
				break;
			default:
				InputBox(name, 100, "������γ�����");
				flag = false;
				for (size_t i = 0; i < vec_cou.size(); i++)
				{
					if (vec_cou[i].name == name)
					{
						p = i;
						flag = true;
						//cout << p << endl;
						break;

					}
				}
				if (!flag)
				{
					HWND hWND = GetHWnd();
					SetWindowText(hWND, "Sauce");
					MessageBox(hWND, "������ȷ�Ŀγ�����", "����ʧ��", MB_OKCANCEL);
				}

				
				break;
			}
		}


		m_showTable->drawHeader();
		m_showTable->drawAddgrid();
		if (p >= 0 && p <= vec_cou.size())m_showTable->drawAdddata2(m_showTable->findData(p));


	}

}







void Management::search()
{


	for (int i = 0; i < sreach_btns.size(); i++)
	{
		sreach_btns[i]->show();
		sreach_btns[i]->eventloop(m_msg);

		if (sreach_btns[i]->isclick())
		{
			switch (i)
			{
			case 0:
				InputBox(num, 100, "������γ̴���");
				flag = false;
				for (size_t i = 0; i < vec_cou.size(); i++)
				{
					if (vec_cou[i].number == num)
					{
						p = i;
						//cout << p << endl;
						flag = true;
						break;

					}
				}
				if (!flag)
				{
					HWND hWND = GetHWnd();
					SetWindowText(hWND, "Sauce");
					MessageBox(hWND, "������ȷ�Ŀγ̴���", "����ʧ��", MB_OKCANCEL);
				}

				break;
			case 1:
				InputBox(name, 100, "������γ�����");
				flag = true;
				for (size_t i = 0; i < vec_cou.size(); i++)
				{
					if (vec_cou[i].name == name)
					{
						p = i;
						flag = true;
						//cout << p << endl;
						break;

					}
				}
				if (!flag)
				{
					HWND hWND = GetHWnd();
					SetWindowText(hWND, "Sauce");
					MessageBox(hWND, "������ȷ�Ŀγ�����", "����ʧ��", MB_OKCANCEL);
				}
				break;

			default:

				break;
			}
		}


		m_showTable->drawHeader();
		m_showTable->drawAddgrid();
		if (p >= 0 && p <= vec_cou.size())m_showTable->drawAdddata2(m_showTable->findData(p));


	}



}

void Management::analysis()
{
	double gpa=0;
	double cnt=0;
	for (int i=0;i<vec_cou.size();i++)
	{
		gpa += vec_cou[i].gpa1() * vec_cou[i].credit;
		cnt += vec_cou[i].credit;
	}
	gpa = gpa / cnt / 10;
	outtextxy(0, 0, "ana");
	char str[1000] = { 0 };
	sprintf_s(str, "����5�����㷨�����gpa��%lf", gpa);
	outtextxy((Window::width() - textwidth(str))/2, (Window::height() - textheight(str)) / 2, str);
}

int Management::menu()
{


	for (int i = 0; i < menu_btns.size(); i++)
	{
		menu_btns[i]->show();
		menu_btns[i]->eventloop(m_msg);
		if (menu_btns[i]->isclick())
		{
			return i;
		}
		if (menu_btns[i]->isin())
		{
			putimage(menu_btns[i]->x() - menu_btns[i]->height() / 2, menu_btns[i]->y(), &m_stu1, SRCAND);
			putimage(menu_btns[i]->x() - menu_btns[i]->height() / 2, menu_btns[i]->y(), &m_stu2, SRCPAINT);
		}
		
	}

    return Menu;
}

void Management::drawBackground(int t)
{
	switch (t)
	{
	case 1:
		putimage(0, 0, &m_bk);
		break;
	default:
		putimage(0, 0, &m_bk2);
		break;
	}
}

void Management::eventloop()
{
	switch (op)
	{
	case Management::Display:
		m_showTable->eventloop(m_msg);
		break;
	default:
		break;
	}

}

void Management::readfile(const std::string& filename)
{

	fstream read(filename, ios::in);
	if (!read.is_open())
	{
		return;
	}
	//��ȡ��ͷ
	char buf[1024] = { 0 };
	read.getline(buf,1024);
	//cout << buf << endl;
	m_header = buf;

	//��ȡ����
	while (!read.eof())
	{
		char data[1024] = { 0 };
		read.getline(data, 1024);
		//��������
		if (strlen(data) == 0)break;
		Course cou;
		stringstream ss(data);
		ss >> cou.number >> cou.name >> cou.credit >> cou.grade;
		vec_cou.push_back(cou);



	}
	read.close();
}

void Management::savefile(const std::string& filename)
{
	fstream write(filename, ios::out | ios::trunc);
	if (!write.is_open())
	{
		cerr << filename << "file open failed" << endl;
		return;
	}
	//��ͷ
	m_header += "\n";
	write.write(m_header.c_str(), m_header.size());
	//����
	for (auto& val : vec_cou)
	{
		std::string info = val.tostringx();
		write.write(info.c_str(), info.size());
	}

	write.close();
}
