#include "LinkList.h"



LinkList::LinkList() : head(nullptr) 
{
}

LinkList::LinkList(int first, int diff, int size) 
{
	head = new NODE(first);
	NODE *temp = head;

	for (int i = 1; i < size; i++)
	{
		first += diff;
		temp->next = new NODE(first);
		temp = temp->next;
	}
	temp->next = nullptr;
}

LinkList::LinkList(const LinkList & other)
{
	*this = other;
}

LinkList::~LinkList()
{
	NODE * temp = head;
	while (temp != nullptr) {
		NODE * ptemp = temp;
		temp = temp->next;
		delete ptemp;
	}
	head = nullptr;
}

void LinkList::operator--()
{
	if (head != nullptr)
	{
		NODE *temp = head;
		if (head->next == nullptr)
		{
			head = nullptr;
			delete temp;
		}
		else
		{
			while (temp->next->next != nullptr)
			{
				temp = temp->next;
				delete temp->next;
				temp->next = nullptr;
			}
		}
	}
}

LinkList & LinkList::operator!()
{
	NODE *tmp = nullptr, *ptmp;
	while (head)
	{
		ptmp = tmp;
		tmp = head;
		head = head->next;
		tmp->next = ptmp;
	}
	head = tmp;

	return *this;
}

LinkList & LinkList::operator=(const LinkList & list)
{
	if (this == &list)
		cout << "error-Self-assigning";

	if (list.head == nullptr)
	{
		head = nullptr;
	}
	else
	{
		head = new NODE(list.head->value);
		NODE *tmp_o = head;
		NODE *tmp_t = list.head->next;
		while (tmp_t != nullptr)
		{
			tmp_o->next = new NODE(tmp_t->value);
			tmp_t = tmp_t->next;
			tmp_o = tmp_o->next;

		}
		tmp_o->next = nullptr;
	}
	return *this;
}

int & LinkList::operator[](int index)
{
	NODE *tmp = head;

	if (index < 0)
	{
		cout << "error-negative index" << endl;
		system("pause");
		exit(1);
	}
	else
	{
		while (index)
		{
			if (!tmp->next)
			{
				cout << "error-index too big" << endl;
				system("pause");
				exit(1);
			}
			else
			{
				tmp = tmp->next;
				index--;
			}
		}
	}
	return tmp->value;
}

void LinkList::print() const
{
	NODE *temp = head;
	while (temp != nullptr) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

ostream & operator<<(ostream & out, const LinkList & c)
{
	if (c.head == 0)
		cout << "list is empty." << endl;
	else
	{
		c.print();
	}
	return out;
}
