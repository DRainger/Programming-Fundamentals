#include "Professor.h"
#include "student.h"

int main()
{

	student *s;
	Professor *p;
	s = new student[2];
	p = new Professor[2];

	for (int i = 0; i < 2; i++)
	{
		if (s[i].IsOutStanding)
			s[i].print;
		else if (p[i].IsOutStanding)
			p[i].print;
	}
	return 0;
}