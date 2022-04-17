
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>

#include "DateTime.h"

using namespace std;

char* TimeToStr(time_t tt, const char* format)
{
	static char buff[64];
	strftime(buff, sizeof buff, format, localtime(&tt));
	return buff;
}

char* TimeToDbDStr(time_t tt) { return TimeToStr(tt, "%Y.%m.%d"); }

time_t CreateDateTime(int year, int month, int day, int hour, int min, int sec)
{
	tm tm;

	tm.tm_year = year - 1900;
	tm.tm_mon = month - 1;
	tm.tm_mday = day;
	tm.tm_hour = hour;
	tm.tm_min = min;
	tm.tm_sec = sec;
	tm.tm_isdst = -1;
	tm.tm_wday = 0;
	tm.tm_yday = 0;

	return mktime(&tm);
}

time_t CreateDate(int year, int month, int day) { return CreateDateTime(year, month, day, 0, 0, 0); }

time_t DbDateStrToDate(const char* str)
{
	int year, month, day;

	char buff[128];
	strncpy(buff, str, sizeof buff);

	char* p = strtok(buff, "./");
	year = atoi(p);

	p = strtok(nullptr, "./");
	month = atoi(p);

	p = strtok(nullptr, " \r\n\0");
	day = atoi(p);

	return CreateDate(year, month, day);
}

const char* AddDay(const char* dbDateStr)
{
	const time_t tt = DbDateStrToDate(dbDateStr);
	tm tm = *localtime(&tt);

	tm.tm_mday += 1;
	const time_t tt2 = mktime(&tm);

	return TimeToDbDStr(tt2);
}


const char* AddWeek(const char* dbDateStr)
{
	const time_t tt = DbDateStrToDate(dbDateStr);
	tm tm = *localtime(&tt);

	tm.tm_mday += 6;
	const time_t tt2 = mktime(&tm);

	return TimeToDbDStr(tt2);
}


const char* AddMonth(const char* dbDateStr)
{
	const time_t tt = DbDateStrToDate(dbDateStr);
	tm tm = *localtime(&tt);

	tm.tm_mon += 1;
	tm.tm_mday -= 1;
	const time_t tt2 = mktime(&tm);

	return TimeToDbDStr(tt2);
}