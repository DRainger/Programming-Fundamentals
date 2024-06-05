#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
class NODE
{
	friend class LinkList;
private:
	int value;
	NODE *next;

public:
	NODE();
	NODE(int);
	~NODE();
};
#endif // !NODE_H


