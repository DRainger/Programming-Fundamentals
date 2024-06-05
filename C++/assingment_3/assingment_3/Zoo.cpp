#include "Zoo.h"



Zoo::Zoo()
{
	All_Animals = new Animal*[MAX_ALL];
	Mobile_Animals = new Mobile*[MAX_MOB];
	All_Lions = new Lion*[MAX_MOB];
}


Zoo::~Zoo()
{
	for (int i = 0; i < count; i++)
	{
		delete All_Animals[i];
	}
	delete[]All_Animals;
	delete[]Mobile_Animals;
	delete[]All_Lions;
}
