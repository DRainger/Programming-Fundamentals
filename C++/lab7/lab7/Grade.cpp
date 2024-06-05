#include "Grade.h"


Grade::Grade(string c_n, int crt, int grd) : grade(grd)
{
	Course(c_n, crt);
}

Grade::Grade(const Grade &other)
{
	*this = other;
}

Grade & Grade::operator=(const Grade &other)
{
	grade = other.grade;
	c = other.c;
}

void Grade::print() const
{
	Course::Print();

}

Grade::~Grade()
{
}
