#include "Year.h"
#include <iomanip>

int main()
{
	int year;
	cout << "Enter year you want to show calendar (2000 to 2099): "; cin >> year;
	Year a(year);

	a.Print();
	return 1;
}