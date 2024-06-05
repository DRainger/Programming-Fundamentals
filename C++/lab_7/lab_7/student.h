#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"


class student:person
{
	int GPA;
public:
	student();
	student(string name, int age, int GPA);
	bool IsOutStanding()const;
	void print()const;
	~student();
};
#endif // !STUDENT_H

