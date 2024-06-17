#include "CurrentDate.h" 

unsigned getCurrSeconds()
{
	time_t now = time(0);
	tm date;
	localtime_s(&date, &now);

	return date.tm_sec;
}
unsigned getCurrMinutes()
{
	time_t now = time(0);
	tm date;
	localtime_s(&date, &now);

	return date.tm_min;
}
unsigned getCurrHours()
{
	time_t now = time(0);
	tm date;
	localtime_s(&date, &now);

	return date.tm_hour;
}

unsigned getCurrDay()
{
	time_t now = time(0);
	tm date;
	localtime_s(&date, &now);

	return date.tm_mday;
}
unsigned getCurrMonth()
{
	time_t now = time(0);
	tm date;
	localtime_s(&date, &now);

	return date.tm_mon + 1;
}
unsigned getCurrYear()
{
	time_t now = time(0);
	tm date;
	localtime_s(&date, &now);

	return date.tm_year + 1900;
}

DateAndTime getCurrDateAndTime()
{
	time_t now = time(0);
	tm date;
	localtime_s(&date, &now);

	unsigned seconds = date.tm_sec;
	unsigned minutes = date.tm_min;
	unsigned hours = date.tm_hour;

	unsigned day = date.tm_mday;
	unsigned month = date.tm_mon + 1;
	unsigned year = date.tm_year + 1900;

	return DateAndTime(day, month, year, seconds, minutes, hours);
}