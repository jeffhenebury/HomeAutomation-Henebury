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
	// Using time point and system_clock
	/*std::chrono::time_point<std::chrono::steady_clock> start, end;*/
		//std::chrono::hours week;

	//const static std::string daysOfWeek[];	//maybe get rid of the array version?
	//vector <string> daysOfWeekVect{ "Sunday",
	//"Monday",
	//"Tuesday",
	//"Wednesday",
	//"Thursday",
	//"Friday",
	//"Saturday"
	//};
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
