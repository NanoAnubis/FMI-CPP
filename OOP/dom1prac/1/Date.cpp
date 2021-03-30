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

#include "Date.hpp"

Date::Date()
{
	day = 1;
	month = 1;
	year = 2000;

	SetCount();
}

Date::Date(const unsigned int _day, const unsigned int _month, const unsigned int _year)
{
	day = _day;
	month = _month;
	year = _year;

	SetCount();
}

Date::Date(const Date& other)
{
	day = other.getDay();
	month = other.getMonth();
	year = other.getYear();
	SetCount();
}

Date& Date::operator=(const Date& other)
{
	day = other.getDay();
	month = other.getMonth();
	year = other.getYear();
	SetCount();
	return *this;
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

void Date::addDays(const unsigned int n)
{
	count_days += n;
	ChangeDate();
}

void Date::removeDays(const unsigned int n )
{
	count_days -= n;
	ChangeDate();
}

bool Date::isLeapYear() const
{
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int Date::DaysToXmas() const
{
	switch (isLeapYear()) {
	case true: {
		return XmasDate_L - count_days;
	}
	case false: {
		return XmasDate_NL - count_days;
	}
	}
}

int Date::DaysToNewYear() const
{
	switch (isLeapYear()) {
	case true: {
		return 367 - count_days;
	}
	case false: {
		return 366 - count_days;
	}
	}
}

int Date::DaysToDate(const Date &rhs) const
{
	int days_left = rhs.count_days - this->count_days;
	if (days_left < 0) {
		switch (isLeapYear())
		{
		case true: {
			days_left += 366;
			break;
		}
		case false: {
			days_left += 365;
			break;
		}
		}
	}
	return days_left;
}

bool Date::isLaterThen(const Date &rhs) const
{
	return rhs.count_days > this->count_days;
}

void Date::SetCount()
{
	count_days = day;
	switch (isLeapYear()) {
	case true: {

		for (int i = 0; i < 12; i++) {
			if (month == i + 1) {
				count_days += MonthToDays_L[i];
				break;
			}
		}

		break;
	}
	case false: {

		for (int i = 0; i < 12; i++) {
			if (month == i + 1) {
				count_days += MonthToDays_NL[i];
				break;
			}
		}
		break;
	}
	}
}

void Date::ChangeDate()
{
	while (count_days < 0) { // If year changes to the previous one
		year--;
		switch (isLeapYear()) {
		case true: {
			count_days += 366;
			break;
		}
		case false: {
			count_days += 365;
			break;
		}
		}

	}
	while (count_days >= 366) { // If year(L/NL) changes to the next one
		bool flag = 0;
		switch (isLeapYear()) {
		case true: {
			if (count_days == 366) {
				flag = 1;
				break;
			}
			year++;
			count_days -= 366;
			break;
		}
		case false: {
			year++;
			count_days -= 365;
			break;
		}
		}
		if (flag == 1) {
			flag = 0;
			break;
		}
	}

	switch (isLeapYear()) {
	case true: {

		for (int i = 0; i < 12; i++) {
			if (count_days > MonthToDays_L[i] && count_days <= MonthToDays_L[i + 1]) {
				month = i + 1;
				day = count_days - MonthToDays_L[i];
				break;
			}
		}

		break;
	}
	case false: {

		for (int i = 0; i < 12; i++) {
			if (count_days > MonthToDays_NL[i] && count_days <= MonthToDays_NL[i + 1]) {
				month = i + 1;
				day = count_days - MonthToDays_NL[i];
				break;
			}
		}
		break;
	}
	}
}
