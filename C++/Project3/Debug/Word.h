
#ifndef _WORD
#define _WORD
#include <iostream>
#include <ctime>
using namespace std;

#define NO_ERROR 0
#define ERROR 1
class Word
{
	int Size_of_Word;
	char* word;

	char random_char();
	int my_strlen(const char*)const;
public:
	Word() :word(nullptr), Size_of_Word(0) {};
	Word(const char*);
	Word(const Word&);
	~Word();

	Word& operator!();
	Word& operator&();
	Word& operator<<(int);
	Word& operator>>(int);
	char& operator[](int);
	Word& operator+=(int);
	Word& operator-=(int);
	Word& operator=(const Word&);
	friend ostream& operator<<(ostream& out, const Word& _word);
};

#endif // _WORD

