#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
	string name;
	int age;
public:
	Person();
	Person(string, int);
	virtual~Person() = 0;

	void print()const;
	bool operator<(Person& p);
};
#endif // PERSON_H

