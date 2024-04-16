#include "Course.h"
#include "sstream"
Course::Course()
{
}

Course::Course(const std::string& number,const std::string& name, double credit, unsigned int grade)
	:number(number),name(name), credit(credit), grade(grade)
{
}

std::string Course::tostring()
{
	std::stringstream ss;
	ss << number << "\t" << name;
	ss<<"\t"<< credit << "\t" << grade << std::endl;
	return ss.str();
}

std::string Course::tostringx()
{
	std::stringstream ss;
	ss << number << "\t" << name;
	for (int i = 30; i > name.size(); i--)
	{
		ss << " ";
	}
	ss << "\t" << credit << "\t" << grade << std::endl;
	return ss.str();
}

double Course::gpa1()
{
	if (grade >= 60)return (grade - 50);
	else
	{
		return 0;
	}
}
