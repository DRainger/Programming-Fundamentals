#include "EncrypeText.h"

int main()
{
	srand(time(NULL));

	////example from hw2 pdf 
	//Text text1("The London is capital of Great Britain.");
	//int key[] = {3,-1,4,1,-1,3,1,0,4,4,-1,0,5,-1,2,-2};
	//EncrypeText London((Text*)text1,false,key );
	//cout << London<<endl;
	//cout << !London << endl;
	//cout << &London << endl;

	//any text with random key
	Text text2("encrypt me and then decrypt me senpai ...");  

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