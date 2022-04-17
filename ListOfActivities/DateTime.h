
#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <ctime>
using std::time_t;

time_t StrToDateTime(const char* str);

const char* AddDay(const char* dbDateStr);
const char* AddWeek(const char* dbDateStr);
const char* AddMonth(const char* dbDateStr);
