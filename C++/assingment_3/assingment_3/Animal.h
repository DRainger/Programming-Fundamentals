#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
	string Name;
	string FeedingHabits;
	string ShowCase;

public:
	Animal();
	void Feeding_Habits();
	void Show_Case();
	friend class Zoo;
	virtual ~Animal() = 0;
	string gat_name();
};
#endif // !ANIMAL_H


