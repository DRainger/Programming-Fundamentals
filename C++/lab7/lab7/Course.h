#pragma once
#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
using namespace std;

class Course
{
	string course_name;
	int credit;
public:
	Course();
	Course(string c_n, int);
	Course(const Course&);
	Course & operator= (const Course&);
	void Print()const;
	~Course();
};
#endif // !COURSE_H

