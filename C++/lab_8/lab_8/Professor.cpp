#include "Professor.h"



Professor::Professor() : Person(), numOfPub(0)
{
}

Professor::Professor(string str, int x, int p) : Person(str,x) , numOfPub(p)
{
}


Professor::~Professor()
{
}

void Professor::print() const
{
	cout << "professor:" << endl;
	Person::print();
	cout << "Number of publications: " << numOfPub << endl;
}

bool Professor::isOutStanding() const
{
	if (numOfPub >= 100)
		return true;
	return false;
}
