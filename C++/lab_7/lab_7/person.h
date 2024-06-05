#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;


class person
{
	string name;
	string last;
	int age;
public:
	person(string, string, int);
	void print()const;
	bool operator<(const person & other)const;
	~person();
};
#endif // !PERSON_H


