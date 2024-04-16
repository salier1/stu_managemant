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
    void drawTableGrid();//���Ʊ��
    void drawTableData();//��������
    void drawButton();
    void drawHeader();
    static std::vector<std::string> split(std::string str, char separator = '\t');//�ַ����ָ��
    void updatepage();
    void eventloop(const ExMessage&msg);//�����ĸ���ť��ָ�������

    void drawAddgrid();
    void drawAdddata(std::string& num, std::string& name, std::string& credit, std::string& score);
    void drawAdddata2(const std::string& str);


private:
    int m_rows;
    int m_cols;
    std::string m_header;
    std::vector<std::string> m_datas;
    int m_gridW;
    int m_gridH;//����С
    int m_tW;
    int m_tH;//���ִ�С
     //���д���
private:
    int m_curPage;
    int m_maxPage;
    int m_extraData;

    Pushbutton* m_prevBtn;
    Pushbutton* m_nextBtn;
    Pushbutton* m_firstBtn;
    Pushbutton* m_lastBtn;
};

