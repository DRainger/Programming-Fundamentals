#pragma once
#include "Course.h"
#ifndef GRADE_H
#define GRADE_H

class Grade 
{
	Course c;
	int grade;
public:
	Grade(string, int, int);
	Grade(const Grade&);
	Grade &operator=(const Grade&);
	void print()const;
	~Grade();
};
#endif // !GRADE_H


