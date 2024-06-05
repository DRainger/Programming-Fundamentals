#ifndef MOBILE_H
#define MOBILE_H

#include "Animal.h"

class Mobile :public Animal
{
protected:
	string Exersize;

public:
	Mobile();
	virtual ~Mobile();
	void Exersize_Is_Good();
};
#endif // !MOBILE_H


