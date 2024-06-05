#ifndef ZOO_H
#define ZOO_H
#define MAX_ALL 200
#define MAX_MOB 100
#include "Animal.h"
#include "Stationery.h"
#include "Carnivores.h"
#include "Herbavorus.h"


class Zoo
{
protected:
	Animal **All_Animals;
	Mobile **Mobile_Animals;
	Lion **All_Lions;
public:
	int count; //counter for amount of animals for d'tor
	Zoo();
	~Zoo();
};

#endif // !ZOO_H

