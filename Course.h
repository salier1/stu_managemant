#pragma once
#include "string"
class Course
{
public:
	Course();
	Course(const std::string& number,const std::string& name, double credit, unsigned int grade);
	std::string tostring(); //��ʽ�������ֵ
	std::string tostringx(); //��ʽ�������ֵ
public:
	std::string number;
	std::string name;
	double credit;
	unsigned int grade;

	double gpa1();


	 
};

