#include "person.h"


person::person(string str, string str_l int a)
{
	name = str;
	last = str_l;
	age = a;
}

void person::print()const
{
	cout << "name: " << name << endl;
	cout << "age: " << age << endl;
}

bool person::operator<(const person & other) const
{
	if (age < other.age)
		return true;
	else
		return false;
}


person::~person()
{
}
