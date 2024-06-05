#include "EncrypeText.h"






EncrypeText::EncrypeText(Text *_ptext, bool _encryption, int * _pkey) 
	:ptext(_ptext), encryption(_encryption), pkey(_pkey){}

EncrypeText::~EncrypeText()
{
}

EncrypeText & EncrypeText::operator+=(int * _new_key)
{
	if (pkey)
		delete[]pkey;
	pkey = _new_key;
	return *this;
}


EncrypeText & EncrypeText::operator!()
{
	if (encryption)//exit if already encrypted
		return *this;

	Text& Rtext = *ptext;//for convenience

	int an[3];
	int an_index=0;
	for (int i = 0; pkey[i] != -2; i++)
	{
		an[an_index] = pkey[i];
		if (++an_index == 3)
		{
			switch (an[0]%5)   //this  an[0]%5  alow an[0] to be any positive number
			{	
			case  1:
				if (an[1] == -1)
					!Rtext;
				else
					!Rtext[an[2]];
				break;
			//*********************
			case  2:
				if (an[1] == -1)
					&Rtext;
				else
					&Rtext[an[2]];
				break;
			//*********************
			case  3:               //rotating left
				if (an[1] == -1)
					Rtext<<an[2];
				else
					Rtext[an[2]]<< an[2];
				break;
			//*********************
			case  4:               //rotating right

				if (an[1] == -1)
					Rtext>> an[2];
				else
					Rtext[an[2]]>> an[2];
				break;
			//*********************
			case  0:               //adding random word/char;
				if (an[1] == -1)
					Rtext += an[2];
				else
					Rtext[an[2]] += an[2];
				break;
			//*******************
			}
			an_index = 0;
		}
	}
	encryption = true;
	return *this;
}


EncrypeText & EncrypeText::operator&()
{
	if (!encryption)//exit if already decrypted
		return *this;

	Text& Rtext = *ptext;//for convenience

	int an[3];
	int an_index = 2;

	//find last an in pkey[]
	int counter = 0;
	int checkpoint = 0;
	for (int i = 0; pkey[i] != -2; i++)
	{
		counter++;
		if (counter == 3)
		{
			checkpoint = i;
			counter = 0;
		}
	}
	

	// decrypt  (doing everything the oposite of encryption.)
	for (int i = checkpoint; i >= 0; i--)
	{
		
		an[an_index] = pkey[i];
		if (an_index == 0)
		{
			switch (an[0]%5)
			{
			case  1:
				if (an[1] == -1)
					!Rtext;
				else
					!Rtext[an[2]];

				break;
				//*********************
			case  2:
				if (an[1] == -1)
					&Rtext;
				else
					&Rtext[an[2]];
				break;
				//*********************
			case  3:                  // in decryption we rotating right
				if (an[1] == -1)
					Rtext >> an[2];     
				else
					Rtext[an[2]] >> an[2];
				break;
				//*********************
			case  4:                  // in decryption we rotating left
				if (an[1] == -1)
					Rtext << an[2];
				else
					Rtext[an[2]] << an[2];
				break;
				//*********************
			case  0:                 // in decryption we removing that random word/char
				if (an[1] == -1)
					Rtext -= an[2];
				else
					Rtext[an[2]] -= an[2];
				break;
				//*******************
			}
			an_index = 3; // 3 because -1 = 2 
		}
	
		an_index--;
	}
	encryption = false;
	return *this;

}

ostream & operator<<(ostream & out, const EncrypeText & _EncrypeText)
{
	out << endl;
	out << "encryption status:"<< (_EncrypeText.encryption  ? "true":"false") << endl;//printing status

	out << "the text is:" << endl;//printing text
	if (_EncrypeText.ptext != nullptr)
		out << *_EncrypeText.ptext << endl;

	if (!_EncrypeText.encryption && _EncrypeText.pkey != nullptr)//printing key if not yet encrypted
	{
		int i = 0;
		out << "key : {";
			while (_EncrypeText.pkey[i] != -2) {  cout << _EncrypeText.pkey[i++] << ", "; }
		out << _EncrypeText.pkey[i]<< "}"<<endl;
	}
	return out;
}
