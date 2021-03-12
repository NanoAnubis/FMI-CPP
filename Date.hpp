#pragma once

class Date
{
public:

	Date();
	Date(int, int, int);
	void addDays(int);
	void removeDays(int);
	bool isLeapYear();
	int DaysToXmas();
	int DaysToNewYear();
	int DaysToDate();
	bool isLaterThen(Date);
	//~Date();
	

private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
	int count_days;

	void SetCount();
	void ChangeDate();
	// 31 28 31 30 31 30 31 31 30 31 30 31 not leap year
	// 31 29 31 30 31 30 31 31 30 31 30 31 leap year

	const int MonthToDays_NL[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 }; 
	const int MonthToDays_L[13] = { 0,31,60,91,121,152,182,213,244,274,305,335,366 }; 
	const int XmasDate_NL = 359;
	const int XmasDate_L = 360;
};

