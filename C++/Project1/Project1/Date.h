#pragma once

#include <iostream>
#include <ctime>

using namespace std;


class Date
{
	int day, month, year;
public:
	Date();
	Date(int day, int month, int year);
	void set_year(int);
	void set_month(int);
	void set_day(int);
	void print_date();
	void gat_month(int);
	bool is_leap_year();
	int num_days();
	int next_day();
	


	~Date();

};





