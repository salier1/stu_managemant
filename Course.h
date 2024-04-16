#pragma once
#include "string"
class Course
{
public:
	Course();
	Course(const std::string& number,const std::string& name, double credit, unsigned int grade);
	std::string tostring(); //格式化输出数值
	std::string tostringx(); //格式化输出数值
public:
	std::string number;
	std::string name;
	double credit;
	unsigned int grade;

	double gpa1();


	 
};

