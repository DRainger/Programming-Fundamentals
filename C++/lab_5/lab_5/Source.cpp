#include "CMatrixFun.h"
#include <stdlib.h>
#include <time.h>


int main()
{
	CMatrixFun obj(3,4);
	srand(time(NULL));
	obj.Print();

	system("pause");
	return 0;
}



