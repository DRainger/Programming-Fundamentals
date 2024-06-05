#include "Menu.h"

Menu::Menu()
{
	count_all = 0;     //****************************************//
	count_lions = 0;   // gat amounts of animals all/mobiles/lions
	count_mobile = 0;  //**************************************//
}


Menu::~Menu()
{
}

void Menu::insert_animals()
{
	int i = 5;             //**********************//
	Animal_interfase(i);   // enter first 5 animals
}

void Menu::Interfase_Menu()
{
	do
	{
		cout << endl << "%$##***Manu***##$%" << endl;
		cout << ".1. Enter animal" << endl;
		cout << ".2. feed all animals" << endl;
		cout << ".3. show case all animals in the zoo" << endl;
		cout << ".4. Exersize" << endl;
		cout << ".5. lion's exhibition" << endl;
		cout << ".6. exit" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			int amount;
			cout << "how meny do you whant to add: ";
			cin >> amount;
			Animal_interfase(amount);
			break;
		case 2:
			for (int i = 0; i < count_all; i++)
			{
				All_Animals[i]->Feeding_Habits();
			}
			break;
		case 3:
			for (int i = 0; i < count_all; i++)
			{
				All_Animals[i]->Show_Case();
			}
			break;
		case 4:
			for (int i = 0; i < count_mobile; i++)
			{
				Mobile_Animals[i]->Exersize_Is_Good();
			}
			break;
		case 5:
			cout << "lions are:" << endl;
			for (int i = 0; i < count_lions; i++)
			{
				All_Lions[i]->Exhibition();
			}
			break;
		case 6:
			break;
		default:
			cout << "invalid input";
			break;
		}

	} while (choice != 6);
}

void Menu::Animal_interfase(int amount)
{

	int buff;
	cout << "(1)spong" << endl << "(2)coral" << endl << "(3)great witte shark" << endl;
	cout << "(4)wolf" << endl << "(5)lion" << endl << "(6)horse" << endl << "(7)zebra" << endl;
	cout << "(8)caw" << endl << "(9)buffalo" << endl << "(10)sheep" << endl;
	for (int i=0;i < amount ;i++)
	{
		cout << "enter choice:";
		cin >> buff;

		switch (buff)
		{
		case 1:
			{
			All_Animals[count_all] = new Sponges;
			count_all++;
			}
			break;
		case 2:
			{
			All_Animals[count_all] = new Corals;
			count_all++;
			}
			break;
		case 3:
			{
			All_Animals[count_all] = new Great_White_Shark;
			Mobile_Animals[count_mobile] = new Great_White_Shark;
			count_all++;
			count_mobile++;

			}
			break;
		case 4:
			{
			All_Animals[count_all] = new Wolf;
			Mobile_Animals[count_mobile] = new Wolf;
			count_all++;
			count_mobile++;
			}
			break;
		case 5:
			{
			All_Animals[count_all] = new Lion;
			Mobile_Animals[count_mobile] = new Lion;
			All_Lions[count_lions] = new Lion;
			count_all++;
			count_mobile++;
			count_lions++;
			}
			break;
		case 6:
			{
			All_Animals[count_all] = new Horse;
			Mobile_Animals[count_mobile] = new Horse;
			count_all++;
			count_mobile++;
			}
			break;
		case 7:
			{
			All_Animals[count_all] = new Zebra;
			Mobile_Animals[count_mobile] = new Zebra;
			count_all++;
			count_mobile++;
			}
			break;
		case 8:
			{
			All_Animals[count_all] = new Caw;
			Mobile_Animals[count_mobile] = new Caw;
			count_all++;
			count_mobile++;
			}
			break;
		case 9:
			{
			All_Animals[count_all] = new Buffalo;
			Mobile_Animals[count_mobile] = new Buffalo;
			cout << count_all << endl;
			cout << count_mobile << endl;
			count_all++;
			count_mobile++;
			}
			break;
		case 10:
			{
			All_Animals[count_all] = new Sheep;
			Mobile_Animals[count_mobile] = new Sheep;
			count_all++;
			count_mobile++;
			}
			break;
		default:
			cout << "invalid input" << endl;
			i--;
			break;

		}
	}
	count = count_all; // gat amount of all animals for d'tor
}
