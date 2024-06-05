#pragma once
#ifndef WORD
#define WORD
#define ERROR 1
#include <iostream>
#include <ctime>

using namespace std;

class Word
{
	char *word;
	int length;

	int strlen(const char*)const;
	char RandChar()const;
public:
	Word() :word (nullptr), length(0) {};
	Word(const char* buff);
	Word(const Word&);

	Word& operator! ();
	Word& operator& ();
	Word& operator<< (int n);
	Word& operator>> (int n);
	Word& operator+= (int n);
	Word& operator-= (int n);
	char& operator[] (int n);
	Word& operator= (const Word &word);
	friend ostream & operator << (ostream &out, const Word &c);
	~Word();
};
#endif // !WORD


