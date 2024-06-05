#ifndef CARNIVORES_H
#define CARNIVORES_H
#include "Mobile.h"

class Carnivores : public Mobile
{
public:
	Carnivores();
	virtual ~Carnivores();
};

class Great_White_Shark : public Carnivores
{
public:
	Great_White_Shark();
	virtual ~Great_White_Shark();
};

class Wolf : public Carnivores
{
public:
	Wolf();
	virtual ~Wolf();
};

class Lion : public Carnivores
{
public:
	Lion();
	void Exhibition();
	virtual ~Lion();
};
#endif // !CARNIVORES_H


