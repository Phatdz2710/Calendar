#include "Month.h"
#include <iomanip>

//Constructor
Month::Month() : _month(1), _day_order(2), _is_leapYear(false) {}

//Parameters constructor
Month::Month(int month, int dayOrder, bool isLeapYear)
	: _month(month), _day_order(dayOrder), _is_leapYear(isLeapYear)
{
	if (_month < 1 || _month > 12) 
		throw invalid_argument("Invalid Month!");

	if (_day_order < 2 || _day_order > 8) 
		throw invalid_argument("Invalid Day Order!");
}

//Get number of day in month
int Month::GetNumDay() const
{
	switch (_month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11: 
		return 30;
	case 2:
		if (_is_leapYear) return 29;
		else return 28;
	default:
		break;
	}

	return 31;
}

//Set month
void Month::SetMonth(int month)
{
	//check input
	if (month < 1 || month > 12)
		throw invalid_argument("Invalid Month!");

	this->_month = month;
}

//Set day order
void Month::SetDayOrder(int dayOrder)
{
	if (dayOrder < 2 || dayOrder > 8)
		throw invalid_argument("Invalid Day Order!");

	this->_day_order = dayOrder;
}

//Set leap year
void Month::SetLeapYear(bool isLeapYear)
{
	this->_is_leapYear = isLeapYear;
}

//Get month
int Month::GetMonth() const
{
	return this->_month;
}

//Get Day Order
int Month::GetDayOrder() const
{
	return this->_day_order;
}

//Print
void Month::Print() const
{
	cout << setw(_space) << left << "Mon";
	cout << setw(_space) << left << "Tue";
	cout << setw(_space) << left << "Wed";
	cout << setw(_space) << left << "Thu";
	cout << setw(_space) << left << "Fri";
	cout << setw(_space) << left << "Sat";
	cout << setw(_space) << left << "Sun" << endl;

	int begin = 2;
	for (; begin < _day_order; begin++)
	{
		cout << setw(_space) << left << ' ';
	}
	
	for (int i = 1; i <= this->GetNumDay(); i++, begin++)
	{
		cout << setw(_space) << i;
		if (begin == 8)
		{
			begin = 1;
			cout << endl;
		}
	}

}