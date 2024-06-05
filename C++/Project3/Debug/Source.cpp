#include "EncrypeText.h"

int main()
{
	srand(time(NULL));

	//any text with random key
	Text text2("London is capital of Great Britain");  

	// generating key
	int random_key_size = 100 + rand() % 100;// min size 
	int* random_key = new int[random_key_size];
	for (int i = 0; i < random_key_size; i++)
	{
		if (i % 3 == 1)
		{
			if (rand() % 2)
				random_key[i] = -1;
			else
				random_key[i] = rand() % 100; // rolling from 0 to 99
		}
		else
			random_key[i] = rand() % 100; // rolling from 0 to 99
	}
	random_key[random_key_size-1] = -2;//stop mark


	EncrypeText Random((Text*)text2, false, random_key);
	cout << Random << endl;
	cout << !Random << endl;
	cout << &Random << endl;



	//delete random_key;
	delete[] random_key;
	system("pause");
	return 0;
}