#include "Professor.h"
#include "Studend.h"

int main()
{
	Person **people;
	int n;
	cout << "how many people: ";
	cin >> n;
	people = new Person*[n];

	string str;
	int age, gpa, pub;

	for (int i = 0; i < n; i++)
	{
		cout << "typ 1 to craete professor, typ 2 to ctreate student." << endl;
		switch (i)
		{
		case 1:
			cout << "enter name: ";
			cin >> str;
			cout << "enter age: ";
			cin >> age;
			cout << "number of publications: ";
			cin >> pub;
			people[i] = new Professor(str, age, pub);
			break;
		case 2:
			cout << "enter name: ";
			cin >> str;
			cout << "enter age: ";
			cin >> age;
			cout << "enter GPA: ";
			cin >> gpa;
			people[i] = new Studend(str, age, gpa);
			break;
		}
	}

	return 0;
}