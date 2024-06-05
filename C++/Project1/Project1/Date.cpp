#include "Date.h"

using namespace std;



Date::Date()
{
	time_t rawtime;
	struct tm * cortime;

	time ( &rawtime );
	cortime = localtime(&rawtime);

	day = timeinfo->tm_day;
	month = timeinfo->tm_mon + 1;
	year = timeinfo->tm_year + 1900;

}

Date::Date(int Day, int Month, int Year)
{
	day = Day;
	month = Month;
	year = Year;

}

void Date::set_year(int y)
{

	year = y;

}

void Date::set_month(int m)
{

	month = m;

}

void Date::set_day(int d)
{

	day = d;

}

void Date::print_date()
{

	cout << day << "/" << month << "/" << year<<endl;

}

void Date::gat_month(int m)
{

	if (m == 1)
		cout << "January";
	if (m == 2)
		cout << "February";
	if (m == 3)
		cout << "March";
	if (m == 4)
		cout << "April";
	if (m == 5)
		cout << "May";
	if (m == 6)
		cout << "June";
	if (m == 7)
		cout << "July";
	if (m == 8)
		cout << "August";
	if (m == 9)
		cout << "September";
	if (m == 10)
		cout << "October";
	if (m == 11)
		cout << "November";
	if (m == 12)
		cout << "December";

}

bool Date::is_leap_year()
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}

int Date::num_days()
{
	int days;
	switch (month)
	{
	case 2:
		if (is_leap_year)
			days = 29;
		else
		{
			days = 28;
		}
	case 4:
	case 6:
	case 9:
	case 11:
		days = 30;
	default:
		days = 31;
		break;
	}

	return days;
}

int Date::next_day()
{

	return 0;
}


Date::~Date()
{
}
