#include "Date.hpp"

Date::Date()
{
	day = 1;
	month = 1;
	year = 2000;

	SetCount();
}

Date::Date(int _day, int _month, int _year)
{
	day = _day;
	month = _month;
	year = _year;

	SetCount();
}

void Date::addDays(int n)
{
	count_days += n;
	ChangeDate();
}

void Date::removeDays(int n )
{
	count_days -= n;
	ChangeDate();
}

void Date::SetCount() 
{
	count_days = day;
	switch (isLeapYear())
	{
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
		switch (isLeapYear())
		{
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
		switch (isLeapYear())
		{
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

	switch (isLeapYear())
	{
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

bool Date::isLeapYear()
{
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int Date::DaysToXmas()
{
	return 0;
}

int Date::DaysToNewYear()
{
	return 0;
}

int Date::DaysToDate()
{
	return 0;
}

bool Date::isLaterThen(Date)
{
	return false;
}


