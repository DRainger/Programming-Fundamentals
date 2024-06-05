#ifndef Studend_H
#define Studend_H
#include "Person.h"

class Studend :public Person
{
	int GPA;
public:
	Studend();
	Studend(string, int, int);
	~Studend();

	void print()const;
	bool isOutStanding()const;
};
#endif // !Studend_H


