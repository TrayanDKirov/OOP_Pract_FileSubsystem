#pragma once
#include <iostream>

namespace GLOBAL_CONSTS_TIME
{
	const unsigned MAX_SECONDS = 59;
	const unsigned MIN_SECONDS = 0;
	const unsigned MAX_MINUTES = 59;
	const unsigned MIN_MINUTES = 0;
	const unsigned MAX_HOURS = 23;
	const unsigned MIN_HOURS = 0;
}

class Time
{
	unsigned seconds = 0;
	unsigned minutes = 0;
	unsigned hours = 0;

	bool areSecondsCorrect(unsigned seconds) const;
	bool areMinutesCorrect(unsigned minutes) const;
	bool areHoursCorrect(unsigned hours) const;

public:

	Time() = default;
	Time(unsigned seconds, unsigned minutes, unsigned hours);

	void setSeconds(unsigned seconds);
	void setMinutes(unsigned minutes);
	void setHours(unsigned hours);

	void setTime(unsigned seconds, unsigned minutes, unsigned hours);

	unsigned getSeconds() const;
	unsigned getMinutes() const;
	unsigned getHours() const;

	friend std::ostream& operator<<(std::ostream& os, const Time& time);
};