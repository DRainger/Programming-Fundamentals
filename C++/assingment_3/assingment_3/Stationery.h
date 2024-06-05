#ifndef STATIONERY_H
#define STATIONERY_H

#include "Animal.h"

; class Stationery : public Animal
{
public:
	Stationery();
	virtual ~Stationery();
};

class Sponges : public Stationery
{
public:
	Sponges();
	virtual ~Sponges();
};

class Corals : public Stationery
{
public:
	Corals();
	virtual ~Corals();
};
#endif // !STATIONERY_H


