#include<iostream>
#include "Date.hpp"

using namespace std;

int main() {

	Date d1;
	Date d2(25, 5, 2011);
	cout << d1.isLeapYear() << endl;
	cout << d2.isLeapYear() << endl;
	cout << d1.isLaterThen(d2) << endl;
	cout << d2.isLaterThen(d1) << endl;
	d1.addDays(135);
	d2.removeDays(53);
	d1.addDays(330);
	d2.removeDays(500);
	cout << d1.DaysToXmas() << endl;
	cout << d1.DaysToNewYear() << endl;
	cout << d2.DaysToXmas() << endl;
	cout << d1.DaysToDate(d2) << endl;
	cout << d2.DaysToDate(d1) << endl;

	return 0;
}