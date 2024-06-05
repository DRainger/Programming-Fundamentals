
#ifndef TEXT_H
#define TEXT_H

#include "Word.h"

class Text
{
	Word *text;
	int text_len;

	int TextLength(const char *temp)const;
public:
	Text() :text(nullptr), text_len(0) {};
	Text(const char*);
	~Text();

	Text &operator!();
	Text &operator&();
	Text &operator<<(int n);
	Text &operator>>(int n);
	Text &operator+=(int n);
	Text &operator-=(int n);
	Word &operator[](int n);
	operator Text*();
	friend ostream &operator<< (ostream& out, const Text&);
};
#endif // !TEXT_H


