#include "Management.h"
#include "iostream"
#include "easyx.h"
#include "Window.h"
#include "Table.h" 
using namespace std;


int main()
{
	Window w(960,640,EW_SHOWCONSOLE);
	w.setWindowTitle("学生成绩管理系统");
	Management m;
	m.run();

	return w.exec();

}