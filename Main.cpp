#include "Management.h"
#include "iostream"
#include "easyx.h"
#include "Window.h"
#include "Table.h" 
using namespace std;


int main()
{
	Window w(960,640,EW_SHOWCONSOLE);
	w.setWindowTitle("ѧ���ɼ�����ϵͳ");
	Management m;
	m.run();

	return w.exec();

}