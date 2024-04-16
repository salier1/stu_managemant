#pragma once
#include "BasicWidget.h"
#include "string"
#include "vector"
#include "Pushbutton.h"
class Table :
    public BasicWidget
{
public:
    Table(int row = 0, int col = 0);
    ~Table();
    void setRowCount(int row);
    void setColCount(int col);
    void setHeader(const std::string& header);
    void insertData(const std::string& data);
    void modifyData(const std::string& data, int p);
    std::string findData(int p);
    void eraseData(int p);
    void show();
    void drawTableGrid();//绘制表格
    void drawTableData();//绘制数据
    void drawButton();
    void drawHeader();
    static std::vector<std::string> split(std::string str, char separator = '\t');//字符串分割函数
    void updatepage();
    void eventloop(const ExMessage&msg);//连接四个按钮的指令出发；

    void drawAddgrid();
    void drawAdddata(std::string& num, std::string& name, std::string& credit, std::string& score);
    void drawAdddata2(const std::string& str);


private:
    int m_rows;
    int m_cols;
    std::string m_header;
    std::vector<std::string> m_datas;
    int m_gridW;
    int m_gridH;//表格大小
    int m_tW;
    int m_tH;//文字大小
     //换行处理
private:
    int m_curPage;
    int m_maxPage;
    int m_extraData;

    Pushbutton* m_prevBtn;
    Pushbutton* m_nextBtn;
    Pushbutton* m_firstBtn;
    Pushbutton* m_lastBtn;
};

