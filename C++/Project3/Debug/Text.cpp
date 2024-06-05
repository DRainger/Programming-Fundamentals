#include "Text.h"


/*method return number of words also ignor double spaces*/
int Text::text_len(const char* tmp) const
{
	if (tmp)
	{
		int i, space_count = 0;
		for (i = 0; tmp[i] != '\0'; i++)
		{	if (tmp[i] == ' '&& tmp[i+1] != ' ')	space_count++; }
		return space_count+1;
	}
	return 0;
}

/*ctor convert text string to array of words with size*/
Text::Text(const char * tmp)
{
	Size_of_Text = text_len(tmp);
	ptext = new Word[Size_of_Text];

	int index=0;
	for (int j = 0; j < Size_of_Text; j++)// creating Size_of_Text words
	{
		ptext[j] = Word(&tmp[index]);// sending to word ctor address of start of each word in tmp

		while (tmp[index] != '\0'   &&   !(tmp[index] == ' '&& tmp[index + 1] != ' ')  )//looking for start of next word
			index++;
		index++;
	}
}

Text::~Text()
{
	if (ptext)	
		delete[] ptext;

}

Text::operator Text*()
{
	return this;
}

Text & Text::operator!()// magic!
{
	for (int i = 0; i < Size_of_Text; i++)
		!ptext[i];
	return *this;
}

Text & Text::operator&()// operator swap places
{
	Word tmp;
	for (int i = 0, j = Size_of_Text - 1; i < j; i++, j--)
	{
		tmp = ptext[i];
		ptext[i] = ptext[j];
		ptext[j] = tmp;
	}
	return *this;
}

Text & Text::operator<<(int n)//operator rotate left n times
{
	Word a1;
	if (Size_of_Text >= 2) 
	{
		while (n)
		{
			n--;
					/*rotation*/
			a1 = ptext[0];     // a1 first word
			for (int i = 0, j = 1;
				j < Size_of_Text;
				i++, j++)
			{
				ptext[i] = ptext[j]; //an = an+1  (moving from left to right)
			}
			ptext[Size_of_Text - 1] = a1;  //last_a = a1
		}
	}
	return *this;
}

Text & Text::operator>>(int n)//operator rotate right n times
{
	if (Size_of_Text >= 2)
	{
		Word an;
		while (n>0)
		{
			n--;
						/*rotation*/
			an = ptext[Size_of_Text - 1];  //an = last_a 
			for (int j = Size_of_Text - 1, i = Size_of_Text - 2; i >= 0; i--, j--)
			{
				ptext[j] = ptext[i]; //an+1 = an  (moving from right to left)
			}
			ptext[0] = an;// a1 = last_a
		}
	}
	return *this;
}

Word & Text::operator[](int x)//function return word in x position else exit with error
{	
	if (ptext)
	{
		x %= Size_of_Text;// if n is biger the the length of the word
		return ptext[x];
	}
	else
	{
		cout << "error word index";
		system("pause");
		exit(ERROR);
	}
	
}

Text & Text::operator+=(int x)// operator add random word  in x 
{

	if (ptext)
	{
		int i;
		Word* tmp = new Word[Size_of_Text + 1]; //creating tmp array of words

		x %= Size_of_Text;// if n is biger the the length of the word

		for (i = 0; i < x; i++)//copy words beffore x
			tmp[i] = ptext[i];

		for (int j = 1 + rand() % 10; j > 0; j--)//roll word (lengh max 10)
			tmp[i] += 0; // add to word random char xj times
		i++;

		for (; i < Size_of_Text + 1; i++) //copy words after x
			tmp[i] = ptext[i - 1];

		//update ptext
		delete[] ptext;
		Size_of_Text++;
		ptext = tmp;

		return *this;
	}
	else
	{
		Size_of_Text = 1;
		ptext = new Word[Size_of_Text];
		for (int i = 1 + rand() % 10; i > 0; i--)//roll word (lengh max 10)
			ptext[0] += 0;
		return *this;
	}
}

Text & Text::operator-=(int x)// operator remove  word  in x 
{
	if (ptext)
	{
		if (Size_of_Text == 1)
		{
			delete[] ptext;
			ptext = nullptr;
			Size_of_Text = 0;
			return *this;
		}
		Word* tmp = new Word[Size_of_Text - 1];//creating tmp array of words
		int i;

		x %= (Size_of_Text - 1);

		for (i = 0; i < x; i++)//copy words beffore x
			tmp[i] = ptext[i];
		i++;
		for (; i < Size_of_Text; i++)
			tmp[i - 1] = ptext[i];

		delete[] ptext;
		Size_of_Text--;
		ptext = tmp;


		return *this;
	}
	else
	{
		cout << "error3";
		system("pause");
		exit(ERROR);
	}
}

ostream & operator<<(ostream & out, const Text & _text)//operator print words with " " between them 
{
	for (int i = 0; i < _text.Size_of_Text; i++)
	{
		out << _text.ptext[i];
		if (i != _text.Size_of_Text - 1)
			out << " ";
	}
	out << ".";
	return out;
}
