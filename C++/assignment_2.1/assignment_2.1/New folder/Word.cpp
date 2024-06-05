#include "Word.h"



int Word::strlen(const char *buff) const
{
	if (buff)
	{
		int i;
		for (i = 0; buff[i] != '\0' && buff[i] != ' '; i++) {}
			return i;
	}
	return 0;
}

char Word::RandChar() const
{
	int choice = rand() % 3; // choce randomly 0, 1, 2.
	switch (choice)
	{
	case 0:
		return (char)(48 + rand() % 10); // number
	case 1:
		return (char)(65 + rand() % 26); // upper case
	case 2:
		return (char)(97 + rand() % 26); // lower case
	}
}

Word::Word(const char* buff)
{
	length = strlen(buff);
	word = new char[length + 1];
	for (int i = 1; i < length; i++)
	{
		word[i] = buff[i];
	}
	word[length] = '\0';
}

Word::Word(const Word &other)
{
	*this = other;
}

Word & Word::operator=(const Word & other)
{
	if (this->word != nullptr)
		delete this->word;
	this->length = other.length;
	this->word = new char[this->length + 1];
	for (int i = 0; i < this->length; i++)
		this->word[i] = other.word[i];
	this->word[length] = '\0';
	return *this;
}

Word & Word::operator!()
{
	for (int i = 0; i < length; i++)
	{
		if (47 < word[i] && word[i] < 58)//number
			word[i] = 105 - word[i];
		else if (64 < word[i] && word[i] < 91)//capital latter
			word[i] = 'a' + 'z' - (32 + word[i]);
		else if (96 < word[i] && word[i] < 123)//latter(not capital)
			word[i] = 'A' + 'Z' - (word[i] - 32);
	}
	return *this;
}
Word & Word::operator&()
{
	char temp;
	for (int i = 0, j = length-1; i < j; i++, j--)
	{
		temp = word[i];
		word[i] = word[j];
		word[j] = temp;
	}
	return *this;
}
Word & Word::operator<<(int n)
{
	char a;
	if (length >= 2)
	{
		while (n>0) 
		{
			n--;
			a = word[0];
			for (int i = 1, j = 0; i < length; i++, j++)
				word[i] = word[j];
			word[length - 1] = a;
		}
	}
	return *this;
}
Word & Word::operator>>(int n)
{
	char b;
	if (length >= 2)
	{
		while (n) 
		{
			n--;
			b = word[length - 1];
			for (int i = length - 2, j = length - 1; i >= 0; i--, j--)
				word[j] = word[i];
		}
		word[0] = b;
	}
	return *this;
}
Word & Word::operator+=(int n)
{
	if (length)
	{
		char *temp = new char[length + 2];
		n %= length; // if n is biger then the length of the word

		int i;
		for (i = 0; i < n; i++)
			temp[i] = word[i];

		temp[i] = RandChar();

		for (; i < length; i++)
			temp[i + 1] = word[i];

		if (word)
			delete[] word;

		length++;
		word = temp;
		word[length] = '\0';
	}
	else
	{
		word = new char[2];
		word[0] = RandChar();
		word[1] = '\0';
	}
	return *this;
}
Word & Word::operator-=(int n)
{
	if (word)
	{
		int i;
		if (length == 1)
		{
			delete[] word;
			length = 0;
			word = nullptr;
			return *this;
		}

		char *temp = new char[length];
		n %= (length - 1);

		for (i = 0; i < n; i++)
			temp[i] = word[i];
		i++;
		for (; i < length; i++)
		{
			temp[i - 1] = word[i];
		}
		temp[length-1] = '\0';

		delete[] word;
		length--;

		word = temp;
		return *this;
	}
	cout << "error empty";
	system("pause");
	exit(ERROR);
}
char & Word::operator[](int n)
{
	if (word)
	{
		n %= length;
		return word[n];
	}
	else
	{
		cout << "error char index";
		system("pause");
		exit(ERROR);
	}
}

Word::~Word()
{
	if (word)
		delete[]word;
}

ostream & operator<<(ostream & out, const Word & word)
{
	for (int i = 0; i < word.length; i++)
	{
		out << word.word[i];
	}
	return out;
}
