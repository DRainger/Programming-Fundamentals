#ifndef LINKLIST_H
#define LINKLIST_H
#include "NODE.h"

class LinkList
{
	NODE *head;

public:
	LinkList();
	LinkList(int, int, int);
	LinkList(const LinkList &);
	~LinkList();

	void operator --();
	LinkList &operator !();
	LinkList &operator =(const LinkList& list);
	int &operator [](int);


	void print()const;
	friend ostream & operator<<(ostream& out, const LinkList& c);
};
#endif // !LINKLIST_H


