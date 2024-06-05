
#ifndef ENCRYPETEXT_H
#define ENCRYPETEXT_H
#include "Text.h"

class EncrypeText
{
	Text *text;
	bool status;
	int *enc_key;
public:
	EncrypeText(Text *_text, bool _status, int *_key);
	EncrypeText() : text(nullptr), status(false), enc_key(nullptr) {};
	~EncrypeText();

	EncrypeText &operator+=(int* en_key);
	EncrypeText &operator!();
	EncrypeText &operator&();
	friend ostream& operator<< (ostream& out, const EncrypeText&);
};
#endif // !ENCRYPETEXT_H


