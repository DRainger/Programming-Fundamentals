#pragma once
#define _PASSPORT_H

#include <iostream>
#include <cstringt.h>
#include "Date.h"

using namespace std;


class Passport {

	char Name[80];
	int BirthDay;//*
	char Gender;
	int LastExit;//*
	int LastReturn;//*

public:
	Passport(char *str, /**/int BD, char g, /**/int E, /**/int R) /*need to switch type int -> date*/
	{
		setName(str);
		setGender(g);
	};

	void setName(char *str) { strcpy(Name, str); };
	void setGender(char g);

};