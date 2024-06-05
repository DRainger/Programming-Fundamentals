#ifndef MANU_H
#define MANU_H
#include "Zoo.h"
#include <typeinfo>
class Menu : public Zoo
{
	int count_all;
	int count_mobile;
	int count_lions;
	int choice;
public:
	Menu();
	~Menu();
	void insert_animals();
	void Interfase_Menu();
	void Animal_interfase(int);
};
#endif // !MANU_H

