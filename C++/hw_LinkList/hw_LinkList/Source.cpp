#include "LinkList.h"

int main()
{
	LinkList obj(2,3,5) , obj2;
	cout <<"first obj: "<< obj;
	obj2 = obj;
	cout << "second obj after copying frist object on second: " << obj2;
	int i;
	cout << "enter witch element to present: " << endl;
	cin >> i;
	cout << "element in " << i << "place :" << obj[i] << endl;


	system("PAUSE");
	return 0;
}