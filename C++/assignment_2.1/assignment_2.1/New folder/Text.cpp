#include "Text.h"



int Text::TextLength(const char * temp) const
{
	if (temp) 
	{
		int i, spaces = 0;
		for (i = 0; temp[i] != '\0'; i++)
			if (temp[i] == ' ' && temp[i + 1] != ' ')
				spaces++;
		return spaces+1;
	}
	return 0;
}

Text::Text(const char *temp)
{
	text_len = TextLength(temp);
	text = new Word[text_len + 1];
	cout << text;
	int i = 0;
	for (int j = 0; j < text_len; j++)
	{
		text[j] = Word(&temp[i]);

		while (temp[i] != '\0' && !(temp[i] == ' ' &&temp[i+1] !=' '))
			i++;
		i++;
	}
}

Text::~Text()
{
	if (text)
		delete[] text;
}

Text & Text::operator!()
{
	for (int i = 0; i < text_len; i++)
		!text[i];
	return *this;
}

Text & Text::operator&()
{
	Word temp;
	for (int i = 0, j = text_len - 1; i < j; i++, j--)
	{
		temp = text[i];
		text[i] = text[j];
		text[j] = temp;
	}
	return *this;
}

Text & Text::operator<<(int n)
{
	Word fw;
	if (text_len >= 2)
	{
		while (n)
		{
			n--;
			fw = text[0];
			for (int i = 0, j = 0; i < text_len; i++, j++)
				text[i] = text[j];
			text[text_len - 1] = fw;
		}
	}
	return *this;
}

Text & Text::operator>>(int n)
{
	Word lw;
	if (text_len >= 2)
	{
		while (n)
		{
			n--;
			lw = text[text_len - 1];
			for (int i = text_len - 1, j = text_len - 2; i >= 0; i--, j--)
				text[i] = text[j];
			text[0] = lw;
		}
	}
	return *this;
	
}

Text & Text::operator+=(int n)
{
	if(text)
	{
		int i;
		Word *temp = new Word[text_len + 1];

		n %= text_len; //if n is biger then the length of the text

		for (i = 0; i < n; i++)
			temp[i] = text[i];
		for (int k = 0; k < rand() % 8; k++)
			text[k] += 0;
		i++;
		for (; i < text_len + 1; i++)
			temp[i] = text[i - 1];
		delete[] text;
		text_len++;
		text = temp;

		return *this;
	}
	else
	{
		text_len = 1;
		text = new Word[text_len];
		for (int k = 0; k < rand() % 8; k++)
			text[k] += 0;
		return *this;
	}
}

Text & Text::operator-=(int n)
{
	if (text)
	{
		if (text_len == 1)
		{
			delete[] text;
			text = nullptr;
			text_len = 0;
			return *this;
		}

		int i;
		Word *temp = new Word[text_len - 1];

		n %= text_len - 1;

		for (i = 0; i < n; i++)
			temp[i] = text[i];
		i++;
		for (; i < text_len; i++)
			temp[i - 1] = text[i];
		delete[] text;
		text_len--;
		text = temp;

		return *this;
	}
	else
	{
		cout << "error3";
		system("pause");
		exit(ERROR);
	}
}

Word & Text::operator[](int n)
{
	if (text)
	{
		n %= text_len;
		return text[n];
	}
	else
	{
		cout << "error word index";
		system("pause");
		exit(ERROR);
	}
}

Text::operator Text*()
{
	return this;
}

ostream & operator<<(ostream & out, const Text & _text)
{
	for (int i = 0; i < _text.text_len; i++)
	{
		out << _text.text[i];
		if (i != _text.text_len - 1)
			out << " ";
	}
	out << ".";
	return out;
}
