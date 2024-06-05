#include "person.h"





person::person()
{
	
	cout << "enter first name:";
	cin >> Name;
	cout << "enter last name:";
	cin >> last;
	birth_year = input_BY(birth_year);
	ID = input_ID(ID);
	hight = input_hight(hight);
	weight = input_weight(weight);

}

void person::setHight(float h)
{
	hight = h;
}

void person::setWeight(float w)
{
	weight = w;
}


float input_hight(float hight)
{

	cout << "enter hight:";
	cin >> hight;

	while ( hight < 0.1 || hight > 3 )
	{
		cout << "invalid input, try agien";
		cin >> hight;

	}

	return hight;

}

float input_weight(float weight)
{
	cout << "enter weight";
	cin >> weight;

	while (weight < 0.1)
	{

		cout << "invalid input, try agin";
		cin >> weight;

	}

	return weight;
}

long input_ID(long id)
{
	cout << "enter i.d:";
	cin >> id;
	while (id > 999999999 && id < 1000000000)
	{

		cout << "invalid input, try agin:";
		cin >> id;

	}
	return id;
}

int input_BY(int y)
{
	cout << "enter birth year:";
	cin >> y;
	while (y < 1900 && y > 2019) 
	{
		cout << "invalid input, try agien:";
		cin >> y;
	}
	return y;
}

const char *person::checkBMI()
{

	if (BMI >= 18.5 && BMI <= 25.0)
	{
		return "optimal weight";
	}
	if (BMI >= 25.0) 
	{
		return "over weight";
	}
	if (BMI <= 18.5)
	{
		return "under weight";
	}

}

void person::presentInfo()
{
	BMI = weight / (hight*hight);


	cout << "\n";
	cout << "name:" << Name <<" " << last << endl;
	cout << "i.d:" << ID << endl;
	cout << "birth year:" << birth_year << endl;
	cout << "weight:" << weight << endl;
	cout << "hight:" << hight << endl;
	cout << "BMI:" << BMI << endl;
	cout << "\n";
	cout << "weight condition:" << this->checkBMI() << endl;


}

person::~person()
{
}


