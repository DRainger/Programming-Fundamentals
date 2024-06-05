#include "Person.h"



Person::Person() : name("none") , age(0)
{
}

Person::Person(string str, int x) : name(str) , age(x)
{
}


Person::~Person()
{
}

void Person::print() const
{
	cout << "Name: " << name << "," << "Age: " << age << endl;
}

bool Person::operator<(Person & p)
{
	if (this->age < p.age)
		return true;
	return false;
}
