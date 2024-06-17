#include "Date.h"

bool Date::monthHas31Days(unsigned mont) const
{
	switch (month)
	{
	case 1:;
	case 3:;
	case 5:;
	case 7:;
	case 8:;
	case 10:;
	case 12: return true;
		break;
	default: return false;
		break;
	}
}

unsigned Date::getMaxDaysInMonth() const
{
	if (monthHas31Days(this->month))
	{
		return 31;
	}
	if (this->month == 2)
	{
		if (isLeapYear())
		{
			return 29;
		}
		return 28;
	}
	return 30;
}

bool Date::isLeapYear() const
{
	if (this->year % 4 == 0)
	{
		if (this->year % 100 == 0)
		{
			return this->year % 400 == 0;
		}
		return true;
	}
	return false;
}


bool Date::isDayCorrect(unsigned day) const
{
	return ( day >= 1 ) && ( day <= getMaxDaysInMonth());
}
bool Date::isMonthCorrect(unsigned month) const
{
	return month >= GLOBAL_CONSTS_DATE::MIN_MOUNTH && month <= GLOBAL_CONSTS_DATE::MAX_MOUNTH;
}
bool Date::isYearCorrect(unsigned year) const
{
	return true;
}

Date::Date(unsigned day, unsigned month, unsigned year)
{
	setDate(day, month, year);
}

void Date::setDay(unsigned day)
{
	if (!isDayCorrect(day))
	{
		throw std::invalid_argument("Day in Date::setDay() is incorrect");
	}
	this->day = day;
}

void Date::setMonth(unsigned mounth)
{
	if (!isMonthCorrect(mounth))
	{
		throw std::invalid_argument("Mounth in Date::setMounth() is incorrect");
	}
	this->month = mounth;
}

void Date::setYear(unsigned year)
{
	if (!isYearCorrect(year))
	{
		throw std::invalid_argument("Year in Date::setYear() is incorrect");
	}
	this->year = year;
}

void Date::setDate(unsigned day, unsigned month, unsigned year)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

unsigned Date::getDay() const
{
	return this->day;
}
unsigned Date::getMonth() const
{
	return this->month;
}
unsigned Date::getYear() const
{
	return this->year;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	return os << date.day << '.' << date.month << '.' << date.year;
}