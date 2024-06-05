
#ifndef _ENCRYPETEXT
#define _ENCRYPETEXT
#include "Text.h"
class EncrypeText
{
	Text *ptext;
	bool encryption;//status
	int* pkey;
public:
	EncrypeText() :ptext(nullptr), encryption(false), pkey(nullptr) {};
	EncrypeText(Text*, bool, int*);
	~EncrypeText();


	EncrypeText& operator+=(int*);
	EncrypeText& operator!();
	EncrypeText& operator&();
	friend ostream& operator<<(ostream& out, const EncrypeText&);
};
#endif // _ENCRYPETEXT
