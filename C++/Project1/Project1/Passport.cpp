#include "Passport.h"


void Passport::setGender(char g)
{
	int gender;
	do {
		cout << "enter gender (M\F):";
		cin >> gender;

		if (gender == 'f')
			gender = 'F';

		if (gender == 'm')
			gender = 'M';

		if (gender != 'F' || gender != 'M')
			cout << "wrong input" << endl;

	} while (gender = 'F' || gender = 'M');

	g=gender;
}
