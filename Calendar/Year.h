#pragma once
#include <iostream>
#include "Month.h"

using namespace std;

class Year
{
private:
	int _year;
	int _day_order;
	Month* listMonth;

	bool isLeapYear(int year);

public:
	//Constructor
	Year();

	//Parameters constructor
	Year(int year);

	//Get Year
	int GetYear() const;

	//Print
	void Print() const;
};