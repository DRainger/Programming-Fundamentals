#ifndef Herbavorus_H
#define Herbavorus_H
#include "Mobile.h"

class Herbavorus : public Mobile
{
public:
	Herbavorus();
	virtual ~Herbavorus();
};

class Equus : public Herbavorus
{
public:
	Equus();
	virtual ~Equus();
};

class Horse : public Equus
{
public:
	Horse();
	virtual ~Horse();
};

class Zebra : public Equus
{
public:
	Zebra();
	virtual ~Zebra();
};

class Cattle : public Herbavorus
{
public:
	Cattle();
	virtual ~Cattle();
};

class Caw : public Cattle
{
public:
	Caw();
	virtual ~Caw();
};

class Buffalo : public Cattle
{
public:
	Buffalo();
	virtual ~Buffalo();
};

class Sheep : public Cattle
{
public:
	Sheep();
	virtual ~Sheep();
};
#endif // !Herbavorus_H


