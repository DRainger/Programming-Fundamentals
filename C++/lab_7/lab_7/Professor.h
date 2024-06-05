#pragma once
#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "person.h"
class Professor:person
{
	int numOfPub;
public:
	Professor();
	Professor(string name, int age, int pub);
	bool IsOutStanding()const;
	void print()const;
	~Professor();
};
#endif // !PROFESSOR_H

