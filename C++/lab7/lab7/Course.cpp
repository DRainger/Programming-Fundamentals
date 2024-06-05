#include "Course.h"



Course::Course(string c_n, int c)
{
	course_name = c_n;
	credit = c;
}


Course::Course(const Course &other)
{
	*this = other;
}

Course & Course::operator=(const Course &other)
{
	course_name = other.course_name;
	credit = other.credit;
}

void Course::Print() const
{
	cout << "course name: " << course_name << " " << "credit: " << credit << endl;
}

Course::~Course()
{
}
