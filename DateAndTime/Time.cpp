#include "Time.h"

bool Time::areSecondsCorrect(unsigned seconds) const
{
	return seconds >= GLOBAL_CONSTS_TIME::MIN_SECONDS &&
		   seconds <= GLOBAL_CONSTS_TIME::MAX_SECONDS;
}
bool Time::areMinutesCorrect(unsigned minutes) const
{
	return minutes >= GLOBAL_CONSTS_TIME::MIN_MINUTES &&
		   minutes <= GLOBAL_CONSTS_TIME::MAX_MINUTES;
}
bool Time::areHoursCorrect(unsigned hours) const
{
	return hours >= GLOBAL_CONSTS_TIME::MIN_HOURS &&
		   hours <= GLOBAL_CONSTS_TIME::MAX_HOURS;
}

Time::Time(unsigned seconds, unsigned minutes, unsigned hours)
{
	setTime(seconds, minutes, hours);
}

void Time::setSeconds(unsigned seconds)
{
	if (!areSecondsCorrect(seconds))
	{
		this->seconds = GLOBAL_CONSTS_TIME::MAX_SECONDS;
		return;
	}
	this->seconds = seconds;
}
void Time::setMinutes(unsigned minutes)
{
	if (!areMinutesCorrect(minutes))
	{
		this->minutes = GLOBAL_CONSTS_TIME::MAX_MINUTES;
		return;
	}
	this->minutes = minutes;
}
void Time::setHours(unsigned hours)
{
	if (!areHoursCorrect(hours))
	{
		this->hours = GLOBAL_CONSTS_TIME::MAX_HOURS;
		return;
	}
	this->hours = hours;
}

void Time::setTime(unsigned seconds, unsigned minutes, unsigned hours)
{
	setSeconds(seconds);
	setMinutes(minutes);
	setHours(hours);
}

unsigned Time::getSeconds() const
{
	return this->seconds;
}
unsigned Time::getMinutes() const
{
	return this->minutes;
}
unsigned Time::getHours() const
{
	return this->hours;
}

std::ostream& operator<<(std::ostream& os, const Time& time)
{
	return os << time.hours << ':' << time.minutes << ':' << time.seconds;
}