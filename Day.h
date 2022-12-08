#pragma once
#pragma once
#ifndef DAY_H_
#define DAY_H_
#include <iostream>
#include <string>
#include <vector>


class Day
{
public:
	Day();
	~Day();
	Day(std::string dayStr, int dayInt);
	std::string sDayOfWeek = "";
	int idayOfWeek;
	int hoursInDay;
	int turnOnTime_day;	//be able to schedule a day schedule and an evening/ night schedule
	int turnOffTime_day;
	int  turnOnTime_evening;
	int  turnOffTime_evening;
	void printDay();


private:

};

#endif // ! DAY_H_