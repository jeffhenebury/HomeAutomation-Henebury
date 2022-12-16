//Jeff Henebury
//implementation of the WeekSchedule header file
//contains a vector of Days to build a Week'
//device schedule is built from here

#pragma once
#ifndef WEEKSCHEDULE_H_
#define WEEKSCHEDULE_H_
#include "Day.h"


using namespace std;

class WeekSchedule
{
public:
	WeekSchedule();
	~WeekSchedule();
	//create a day object for the 7 dats of the week
	Day Sunday;
	Day Monday;
	Day Tuesday;
	Day Wednesday;
	Day Thursday;
	Day Friday;
	Day Saturday;
	vector <Day> weeklySchedule;
	//methods
	void setWeeklySchedule(int DayOnTime, int DayOffTime, int nightOnTime, int nightOffTime);
	int getDayOfWeekFromString();
	void printWeeklySchedule();



private:

};


#endif // !WEEKSCHEDULE_H_
