#include "Animal.h"






Animal::Animal()
{
}

void Animal::Feeding_Habits()
{
	cout << Name << endl;
	cout << FeedingHabits << endl;
}

void Animal::Show_Case()
{
	cout << Name << endl;
	cout << ShowCase << endl;
}

Animal::~Animal()
{
}

string Animal::gat_name()
{
	return Name;
}
