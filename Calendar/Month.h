#pragma once
#include <iostream>

using namespace std;

class Month
{
private:
	int _month;
	int _day_order;
	bool _is_leapYear;

	const int _space = 5;
public:
	//Constructor
	Month();

	//Parameters constructor
	Month(int month, int dayOrder, bool isLeapYear);

	//Get number of day in month
	int GetNumDay() const;

	//Set month
	void SetMonth(int month);

	//Set day order
	void SetDayOrder(int dayOrder);

	//Set leap year
	void SetLeapYear(bool isLeapYear);

	//Get month
	int GetMonth() const;

	//Get Day Order
	int GetDayOrder() const;
	
	//Print
	void Print() const;
};