#include "student.h"



student::student()
{
	cout << "enter GPA: ";
	cin >> GPA;
}

student::student(string name, int age, int gpa) : person(name, age), GPA(gpa)
{
}

bool student::IsOutStanding()const
{
	if (GPA >= 85)
		return true;
	else
		return false;
}

void student::print() const
{
	person::Print();
	cout << "GPA: " << GPA << endl;
}


student::~student()
{
}
