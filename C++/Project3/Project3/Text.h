#ifndef _TEXT
#define _TEXT
#include "Word.h"
class Text
{
	Word* ptext;
	int Size_of_Text;

	int text_len(const char* tmp)const;
public:
	Text() :ptext(nullptr), Size_of_Text(0) {};
	Text(const char*);
	~Text();
	
	operator Text*();  //casting operator ( "&"  operator already in use and we will use casting to get object addres)
	Text& operator!();
	Text& operator&();
	Text& operator<<(int);
	Text& operator>>(int);
	Word& operator[](int);
	Text& operator+=(int);
	Text& operator-=(int);
	friend ostream& operator<<(ostream& out, const Text& );
};

#endif // _TEXT
