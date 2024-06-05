#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string.h>

using namespace std;


class person
{
	long ID;
	char Name[10];
	char last[10];
	float hight;
	float weight;
	int birth_year;
	float BMI;

public:
	person();
	void setHight(float);
	void setWeight(float);
	long gat_ID() { return ID; }
	char *gat_name() { return Name; }
	char *gat_last() { return last; }
	float get_hight() { return hight; }
	float get_weight() { return weight; }
	int get_birthYear() { return birth_year; }
	float get_BMI() { return BMI; }
	void calc_BMI() { BMI = weight / (hight*hight); }
	const char *checkBMI();
	void presentInfo();

	~person();
};

float input_hight(float hight);
float input_weight(float weight);
long input_ID(long id);
int input_BY(int y);
#endif //person
