#include "DateAndTime.h"

std::ostream& operator<<(std::ostream& os, const DateAndTime& dateAndTime)
{
	os << (Date)dateAndTime;
	os << ' ';
	os << (Time)dateAndTime;
	return os;
}

void DateAndTime::loadFromDataFile(std::ifstream& ifs)
{
	Date::loadFromDataFile(ifs);

	Time::loadFromDataFile(ifs);
}

void DateAndTime::saveInDataFile(std::ofstream& ofs) const
{
	Date::saveInDataFile(ofs);

	Time::saveInDataFile(ofs);
}