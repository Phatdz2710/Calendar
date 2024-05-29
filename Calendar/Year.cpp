#include "Year.h"

bool Year::isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) return true;
	return false;
}

//Constructor
Year::Year() : _year(2024), _day_order(2)
{
	listMonth = new Month[12];
	int numDay = 31;
	int dayOrder = 2;

	listMonth[0].SetDayOrder(_day_order);
	listMonth[0].SetMonth(1);
	listMonth[0].SetLeapYear(false);

	for (int i = 1; i < 12; i++)
	{
		listMonth[i].SetMonth(i+1);

		numDay = listMonth[i].GetNumDay();

		if (numDay == 31) dayOrder += 3;
		else if (numDay == 30) dayOrder += 2;
		else if (numDay == 29) dayOrder += 1;

		if (dayOrder > 8) dayOrder -= 7;

		listMonth[i].SetDayOrder(dayOrder);
	}
}

//Parameters Constructor
Year::Year(int year) : _year(year), _day_order(2)
{
	if (year < 2000 || year > 2099) throw invalid_argument("Year must be greater than 2000!");

	int yearBegin = 2000;
	int begin = 7;

	//Tinh so nam nhuan
	int numLeapYear = (year - yearBegin) / 4 + 1;
	if (isLeapYear(year)) numLeapYear -= 1;
	int numNonLeapYear = (year - yearBegin) - numLeapYear;

	begin += numNonLeapYear + 2 * numLeapYear;
	
	while (begin > 8)
	{
		begin -= 7;
	}

	listMonth = new Month[12];
	int numDay = 31;
	int dayOrder = begin;
	_day_order = dayOrder;

	listMonth[0].SetDayOrder(dayOrder);
	listMonth[0].SetMonth(1);

	for (int i = 1; i < 12; i++)
	{
		listMonth[i].SetMonth(i + 1);
		if (isLeapYear(_year))
			listMonth[i].SetLeapYear(true);

		numDay = listMonth[i-1].GetNumDay();

		if (numDay == 31) dayOrder += 3;
		else if (numDay == 30) dayOrder += 2;
		else if (numDay == 29) dayOrder += 1;

		if (dayOrder > 8) dayOrder -= 7;

		listMonth[i].SetDayOrder(dayOrder);
	}
}

int Year::GetYear() const
{
	return _year;
}

void Year::Print() const
{
	for (int i = 0; i < 12; i++)
	{
		cout << "\n----------" << i + 1 << "-----------\n";
		listMonth[i].Print();
	}
}