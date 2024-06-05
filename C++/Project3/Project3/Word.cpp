#include "Word.h"


char Word::random_char()
{
	unsigned int type=rand()%3; // 0- number , 1- capital latter ,2- latter(not capital)
	switch (type) {
	case 0:
		return (char)(48 + rand() % 10);
	case 1:
		return (char)(65 + rand() % 26);
	case 2:
		return (char)(97 + rand() % 26);
	}
}

int Word::my_strlen(const char* tmp)const
{
	if (tmp)
	{
		int i;
		for (i = 0;  tmp[i] != '\0' && tmp[i] != ' ';  i++) { }
		return i;
	}
	return 0;
}

Word::Word(const char* tmp)
{
	Size_of_Word=my_strlen(tmp); 
	word = new char[Size_of_Word + 1];
	for (int i = 1; i < Size_of_Word; i++) { word[i] = tmp[i]; } 
	word[Size_of_Word] = '\0';
}
Word::Word(const Word &sec)
{
	*this = sec;
};

Word::~Word()
{
	if(word)
		delete[] word;
}

Word & Word::operator!()
{
	for (int i = 0; i < Size_of_Word; i++)
	{
		if(47 < word[i] && word[i] < 58)//number
			word[i] = 105 - word[i];
		else if(64 < word[i] && word[i] < 91)//capital latter
			word[i] = 'a'+'z' -(32 + word[i]);
		else if (96 < word[i] && word[i] < 123)//latter(not capital)
			word[i] = 'A'+'Z' -(word[i] - 32);
	}
	return *this;
}

Word & Word::operator&()
{
	char tmp;
	for (int i = 0,j= Size_of_Word-1; i < j; i++,j--)
	{
		tmp = word[i];
		word[i] = word[j];
		word[j] = tmp;
	}
	return *this;
}

Word & Word::operator<<(int n)
{

	char a1;
	if (Size_of_Word >= 2)
	{
		while (n>0)
		{
			n--;
			a1 = word[0];
			for ( int i = 0, j = 1;
				  j < Size_of_Word;
				  i++, j++)
			{
				word[i] = word[j];
			}
			word[Size_of_Word - 1] = a1;
		}
	}
	return *this;
}

Word & Word::operator>>(int n)
{
	if (Size_of_Word >= 2)
	{
		char an;
		while (n)
		{
			n--;
			an = word[Size_of_Word - 1];
			for (int j = Size_of_Word - 1 , i = Size_of_Word - 2;	i >= 0;		i--,j--)
			{
				word[j] = word[i];
			}
			word[0] = an;
		}
	}
	return *this;
}

char & Word::operator[](int n)
{
	if (word)
	{
		n %= Size_of_Word;  // the modulo thingy
		return word[n];
	}
	else
	{
		cout << "error char index";
		system("pause");
		exit(ERROR);
	}
}

Word & Word::operator+=(int x)
{
	if (Size_of_Word)
	{
		char* tmp = new char[Size_of_Word + 2];// Size_of_Word+1+1
		x %= Size_of_Word;// the modulo thingy

		int i;
		for (i = 0; i < x; i++)
			tmp[i] = word[i];

		tmp[i] = random_char();

		for (     ; i < Size_of_Word; i++)
		{
			tmp[i + 1] = word[i];
		}

		if (word)
			delete[] word;

		Size_of_Word++;
		word = tmp;
		word[Size_of_Word] = '\0';
	}
	else
	{
		word = new char[2];
		Size_of_Word++;
		word[0] = random_char();
		word[1] = '\0';
	}


	return *this;
}
Word & Word::operator-=(int x)
{
	int i;
	if (word)
	{
		if (Size_of_Word == 1)
		{
			delete[] word;
			Size_of_Word = 0;
			word = nullptr;
			return *this;
		}

		char* tmp = new char[Size_of_Word];//Size_of_Word+1-1

		x %= (Size_of_Word - 1);// the modulo thingy

		for (i = 0; i < x; i++)
			tmp[i] = word[i];
		i++;

		for (; i < Size_of_Word; i++)
		{
			tmp[i - 1] = word[i];
		}
		tmp[Size_of_Word-1] = '\0';

		delete[] word;//update word
		Size_of_Word--;

		word = tmp;

		return *this;
	}
			cout << "error empty";
			system("pause");
			exit(ERROR);
}
	
	

Word & Word::operator=(const Word& Rvalue)
{
	if (this->word != nullptr)
		delete word;
	this->Size_of_Word = Rvalue.Size_of_Word;
	this->word = new char[this->Size_of_Word+1];
	for (int i = 0; i < this->Size_of_Word; i++)
		this->word[i] = Rvalue.word[i];
	return *this;
}


ostream & operator<<(ostream & out, const Word & _word)
{
	for (int i = 0; i < _word.Size_of_Word ;i++ )
	{
		out << _word.word[i];
	}
	return out;
}
