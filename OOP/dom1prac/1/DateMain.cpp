/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Lubomir Stoykov
* @idnumber 62569
* @task 1
* @compiler VC
*/

#include<iostream>
#include "Date.hpp"

using namespace std;

int main() {

	Date dt1;
	Date dt2(25, 5, 2011);
	Date dt3 = dt1;
	cout << dt1.isLeapYear() << endl;
	cout << dt2.isLeapYear() << endl;
	cout << dt1.isLaterThen(dt2) << endl;
	cout << dt2.isLaterThen(dt1) << endl;
	dt3 = dt2;
	dt1.addDays(135);
	dt2.removeDays(53);
	dt1.addDays(330);
	dt2.removeDays(500);
	cout << dt1.DaysToXmas() << endl;
	cout << dt1.DaysToNewYear() << endl;
	cout << dt2.DaysToXmas() << endl;
	cout << dt1.DaysToDate(dt2) << endl;
	cout << dt2.DaysToDate(dt1) << endl;


	return 0;
}