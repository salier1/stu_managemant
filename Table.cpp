#include "Table.h"
#include "iostream"
#include "string"
#include "graphics.h"
#include "easyx.h"
using namespace std;
Table::Table(int row, int col)
	:BasicWidget(0,0,0,0),m_rows(row),m_cols(col),m_curPage(0),m_maxPage(0),m_extraData(0)
{
	m_prevBtn=new Pushbutton("上一页");
	m_nextBtn=new Pushbutton("下一页");
	m_firstBtn= new Pushbutton("首页");
	m_lastBtn= new Pushbutton("尾页");
}

Table::~Table()
{

	delete m_prevBtn;
	delete m_nextBtn;
	delete m_firstBtn;
	delete m_lastBtn;

}

void Table::setRowCount(int row)
{
	m_rows = row;
}

void Table::setColCount(int col)
{
	m_cols = col;
}

void Table::setHeader(const std::string& header)
{
	m_header = header;
	//m_cols=std::count(m_header.begin(), m_header.end(), '\t');
	m_cols = 4;
	//方便一点
	m_tW= ::textwidth("思想道德修养与法律基础");
	m_tH= ::textheight(m_header.c_str());

	m_gridH = m_tH + 10;
	m_gridW = m_tW + 10;

	m_w = m_gridW * m_cols;
	m_h = m_gridH * m_rows;

	m_firstBtn->move(m_x, m_h + 60);
	m_prevBtn->move(m_firstBtn->x() + m_prevBtn->width(), m_firstBtn->y());
	m_nextBtn->move(m_prevBtn->x() + m_prevBtn->width(), m_firstBtn->y());
	m_lastBtn->move(m_nextBtn->x() + m_prevBtn->width(), m_firstBtn->y());
}

void Table::insertData(const std::string& data)
{
	m_datas.push_back(data);
	updatepage();
}

void Table::modifyData(const std::string& data, int p)
{
	m_datas[p] = data;
}

std::string Table::findData(int p)
{
	return m_datas[p];
}

void Table::eraseData(int p)
{
	m_datas.erase(m_datas.begin() + p);
}

void Table::show()
{
	drawTableGrid();
	drawTableData();
	drawHeader();
	if (m_maxPage > 0)
	{
		drawButton();
	}

}

void Table::drawTableGrid()
{
	setlinecolor(BLACK);
	//横线
	for (int i = 0; i < m_rows + 1; i++)
	{
		line(m_x, m_y + i * m_gridH, m_x + m_cols * m_gridW, m_y + i * m_gridH);
	}
	//竖线
	for (int i = 0; i < m_cols + 1; i++)
	{
		line(m_x + i * m_gridW, m_y, m_x + i * m_gridW, m_y + m_rows * m_gridH);
	}



}

void Table::drawTableData()
{
	int begPos = m_curPage*m_rows;
	int endPos = (m_curPage+1)* m_rows;
	 
	//防止越界
	if (endPos > m_datas.size())
	{
		endPos = m_datas.size();
	}


	//settextstyle(20, 0, "宋体");
	for (int i = begPos; i < endPos; i++)//行
	{
		const auto& line_data = split(m_datas[i]);
		for (size_t j = 0; j < line_data.size(); j++)//列
		{
			//int spaceh=m_grid
			//int tx = m_x + j * m_gridW + (m_gridW - ::textwidth(line_data[j].c_str())) / 2;
			int tx = m_x + j * m_gridW +(m_gridW-textwidth(line_data[j].c_str()))/2;
			int ty = m_y + (i%16) * m_gridH + 5;
			outtextxy(tx, ty, line_data[j].c_str());
		}
	}
}

void Table::drawButton()
{


	m_prevBtn->show();
	m_nextBtn->show();
	m_firstBtn->show();
	m_lastBtn->show();
	char str[30] = {0};
	sprintf_s(str, "第%d页 / 共%d页", m_curPage + 1, m_maxPage + 1);
	outtextxy(m_lastBtn->x() + m_lastBtn->width() + 100, m_lastBtn->y()+m_prevBtn->height()/2-10,str);
}

void Table::drawHeader()
{
	setlinestyle(PS_SOLID, 2);
	::rectangle(m_x, m_y - m_gridH, m_x + m_w, m_y);
	const auto& line_data = split(m_header);
	for (size_t i = 0; i < m_cols; i++)
	{
		line(m_x + i * m_gridW, m_y - m_gridH, m_x + i * m_gridW, m_y);
		int tx = m_x + i * m_gridW + (m_gridW - textwidth(line_data[i].c_str())) / 2;
		int ty = m_y - m_gridH + 5;
		outtextxy(tx, ty, line_data[i].c_str());
	}

	

	setlinestyle(PS_SOLID, 1);
}



std::vector<std::string> Table::split(std::string str, char separator)
{

	std::vector<std::string> res;
	string s = str;

	for (int i = 0; i < 4; i++)
	{
		
		size_t pos = s.find(separator);//找到位置
		res.push_back(s.substr(0, pos));//取出字符串
		s = std::string(s.c_str()+pos + 1);
		
	}
	return res;
}
void Table::updatepage()
{
	m_maxPage = m_datas.size() / m_rows;
	m_extraData = m_datas.size() % m_rows;

}

void Table::eventloop(const ExMessage& msg)
{

	m_prevBtn->eventloop(msg);
	m_nextBtn->eventloop(msg);
	m_firstBtn->eventloop(msg);
	m_lastBtn->eventloop(msg);

	if (m_prevBtn->isclick())
	{
		if (m_curPage != 0)
		{
			m_curPage--;
		}
	}
	if (m_nextBtn->isclick())
	{
		if (m_curPage != m_maxPage)
		{
			m_curPage++;
		}
	}
	if (m_firstBtn->isclick())
	{
		m_curPage = 0;
	}
	if (m_lastBtn->isclick())
	{
		m_curPage = m_maxPage;
	}
}

void Table::drawAddgrid()
{
	setlinecolor(BLACK);
	//横线
	for (int i = 0; i < 2; i++)
	{
		line(m_x, m_y + i * m_gridH, m_x + m_cols * m_gridW, m_y + i * m_gridH);
	}
	//竖线
	for (int i = 0; i < m_cols + 1; i++)
	{
		line(m_x + i * m_gridW, m_y, m_x + i * m_gridW, m_y + m_gridH);
	}
}

void Table::drawAdddata(std::string& num, std::string& name, std::string& credit, std::string& score)
{

	for (size_t j = 0; j < 4; j++)//列
	{
		string s1;
		switch (j)
		{
		case 0:
			s1 = num;
			break;
		case 1:
			s1 = name;
			break;
		case 2:
			s1 = credit;
			break;
		case 3:
			s1 = score;
			break;
		default:
			break;
		}
		int tx = m_x + j * m_gridW + (m_gridW - textwidth(s1.c_str())) / 2;
		int ty = m_y + 5;
		outtextxy(tx, ty, s1.c_str());
	}
}

void Table::drawAdddata2(const std::string& str)
{
	const auto& line_data = split(str);
	for (size_t i = 0; i < line_data.size(); i++)
	{
		int tx = m_x + i * m_gridW + (m_gridW - textwidth(line_data[i].c_str())) / 2;
		int ty = m_y + 5;
		outtextxy(tx, ty, line_data[i].c_str());
		//cout << line_data[i].c_str() << endl;
	}
}





