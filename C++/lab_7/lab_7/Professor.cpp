#include "Professor.h"



Professor::Professor()
{
	cout << "number of publications: ";
	cin >> numOfPub;
}

Professor::Professor(string name, int age, int pub) : person(name,age), numOfPub(pub)
{
}

bool Professor::IsOutStanding() const
{
	if (numOfPub > 100)
		return true;
	else
		return false;
}

void Professor::print() const
{
	person::Print();
	cout << "number of publications: " << numOfPub << endl;
}


Professor::~Professor()
{
}
