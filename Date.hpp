#pragma once

class Date
{
public:

	Date();
	Date(const unsigned int, const unsigned int, const unsigned int);
	Date(const Date&);
	Date& operator=(const Date&);
	~Date() {};

	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void addDays(const unsigned int);
	void removeDays(const unsigned int);
	bool isLeapYear() const;
	int DaysToXmas() const;
	int DaysToNewYear() const;
	int DaysToDate(const Date &) const;
	bool isLaterThen(const Date &) const;
	

private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
	int count_days;

	void SetCount();
	void ChangeDate();

	const int MonthToDays_NL[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 }; 
	const int MonthToDays_L[13] = { 0,31,60,91,121,152,182,213,244,274,305,335,366 }; 
	const int XmasDate_NL = 359;
	const int XmasDate_L = 360;
};

