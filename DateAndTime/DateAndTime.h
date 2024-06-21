#pragma once
#include <fstream>
#include "Date.h"
#include "Time.h"

class DateAndTime : public Date, public Time
{


public:

	DateAndTime() : Date(), Time() { }
	DateAndTime(unsigned day, unsigned month, unsigned year,
				unsigned seconds, unsigned minutes, unsigned hours) :
				Date(day, month, year), Time(seconds, minutes, hours) { }

	void loadFromDataFile(std::ifstream& ifs);

	void saveInDataFile(std::ofstream& ofs) const;

	friend std::ostream& operator<<(std::ostream& os, const DateAndTime& dateAndTime);
};