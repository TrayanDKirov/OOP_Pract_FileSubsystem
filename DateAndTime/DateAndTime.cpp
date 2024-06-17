#include "DateAndTime.h"

std::ostream& operator<<(std::ostream& os, const DateAndTime& dateAndTime)
{
	os << (Date)dateAndTime;
	os << ' ';
	os << (Time)dateAndTime;
	return os;
}