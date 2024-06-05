#include "EncrypeText.h"


EncrypeText::EncrypeText(Text * _text, bool _status, int * _key) 
	: text(_text), status(_status), enc_key(_key) {}

EncrypeText::~EncrypeText()
{
}

EncrypeText & EncrypeText::operator+=(int * new_key)
{
	if (enc_key)
		delete[] enc_key;
	enc_key = new_key;
	return *this;
}

/*
////**********************************************************
////**     a1 % 5     | |       a2       | |      a3        ||
////**number | meaning| |number | meaning| |numbers meaning:||
////**    1  |    !   | |   -1  |all text| |if a1 operator  ||
////**    2  |    &   | |       |        | |needs rvalue    ||
////**    3  |   <<   | |   x   |only for| |a3 is it rvalue ||
////**    4  |   >>   | |       |word num| |                ||
////**    0  |   +=   | |       |   x    | |                ||
////**********************************************************
////**     -2  in any position meaning end of key         ****
////**********************************************************
*/

EncrypeText & EncrypeText::operator!()
{
	if (status)
		return *this;

	Text& ptext = *text; 
	
	int k[3];
	int index = 0;
	for (int i = 0; enc_key[i] != -2; i++)
	{
		k[index] = enc_key[i];
		if (++index == 3)
		{
			switch (k[0]%5)
			{
			case 1:
				if (k[1] == -1)
					!ptext;
				else
					!ptext[k[2]];
				break;
			case 2:
				if (k[1] == -1)
					&ptext;
				else
					&ptext[k[2]];
				break;
			case 3:
				if (k[1] == -1)
					ptext << k[2];
				else
					ptext[k[2]] << k[2];
				break;
			case 4:
				if (k[1] == -1)
					ptext << k[2];
				else
					ptext[k[2]] << k[2];
				break;
			case 0:
				if (k[1] == -1)
					ptext += k[2];
				else
					ptext[k[2]] += k[2];
				break;
			}
			index = 0;
		}
	}
	status = true;
	return *this;
}

EncrypeText & EncrypeText::operator&()
{
	if (!status)
		return *this;

	Text& ptext = *text;

	int k[3];
	int index = 0;

	int counter = 0;
	int cp = 0;
	for (int i=0; enc_key[i] != -2; i++)
	{
		counter++;
		if (counter == 3)
		{
			cp = i;
			counter = 0;
		}
	}

	for (int i = cp; i >= 0; i--)
	{
		k[index] = enc_key[i];
		if (index == 0)
		{
			switch (k[0]%5)
			{
			case 1:
				if (k[1] == -1)
					!ptext;
				else
					!ptext[k[2]];
				break;
			case 2:
				if (k[1] == -1)
					&ptext;
				else
					&ptext[k[2]];
				break;
			case 3:
				if (k[1] == -1)
					ptext << k[2];
				else
					ptext[k[2]] << k[2];
				break;
			case 4:
				if (k[1] == -1)
					ptext << k[2];
				else
					ptext[k[2]] << k[2];
				break;
			case 0:
				if (k[1] == -1)
					ptext -= k[2];
				else
					ptext[k[2]] -= k[2];
				break;
			}
			index = 3;
		}
		index--;
	}
	status = false;
	return *this;
}

ostream & operator<<(ostream & out, const EncrypeText &_EncrypeText)
{
	out << endl;
	out << "encryption status:" << (_EncrypeText.status ? "true" : "false") << endl;//printing status

	out << "the text is:" << endl;//printing text
	if (_EncrypeText.text != nullptr)
		out << *_EncrypeText.text << endl;

	if (!_EncrypeText.status && _EncrypeText.enc_key != nullptr)//printing key if not yet encrypted
	{
		int i = 0;
		out << "key : {";
		while (_EncrypeText.enc_key[i] != -2) { cout << _EncrypeText.enc_key[i++] << ", "; }
		out << _EncrypeText.enc_key[i] << "}" << endl;
	}
	return out;
}
