#include "Studend.h"



Studend::Studend() :Person() , GPA(0)
{
}

Studend::Studend(string str, int x, int g) : Person(str,x) , GPA(g)
{
}


Studend::~Studend()
{
}

void Studend::print() const
{
	cout << "student:" << endl;
	Person::print();
	cout << "GPA: " << GPA << endl;
}

bool Studend::isOutStanding() const
{
	if (GPA >= 85)
		return true;
	return false;
}
