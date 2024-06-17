#pragma once
#include <iostream>

namespace GLOBAL_CONSTS_DATE
{
	const unsigned MIN_MOUNTH = 0;
	const unsigned MAX_MOUNTH = 12;
}

class Date
{
	unsigned day = 1;
	unsigned month = 1;
	unsigned year = 2000;

	bool monthHas31Days(unsigned month) const;

	bool isDayCorrect(unsigned day) const;
	bool isMonthCorrect(unsigned month) const;
	bool isYearCorrect(unsigned year) const;

public:

	Date() = default;
	Date(unsigned day, unsigned month, unsigned year);

	void setDay(unsigned day);
	void setMonth(unsigned month);
	void setYear(unsigned year);

	unsigned getDay() const;
	unsigned getMonth() const;
	unsigned getYear() const;

	void setDate(unsigned day, unsigned month, unsigned year);
	bool isLeapYear() const;
	unsigned getMaxDaysInMonth() const;

	friend std::ostream& operator<<(std::ostream& os, const Date& date);
};