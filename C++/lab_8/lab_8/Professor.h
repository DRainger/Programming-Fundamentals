#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "Person.h"

class Professor :public Person
{
	int numOfPub;
public:
	Professor();
	Professor(string,int,int);
	~Professor();

	void print()const;
	bool isOutStanding()const;
};
#endif // !PROFESSOR_H


