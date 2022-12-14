#include "Day.h"


Day::Day()
{
	sDayOfWeek = "";
	idayOfWeek = 0;
	hoursInDay = 2400;
	turnOnTime_day = 0;
	turnOffTime_day = 0;
	turnOnTime_evening = 0;
	turnOffTime_evening = 0;
	
}

Day::~Day()
{
}

inline Day::Day(std::string dayStr, int dayInt)
{
	sDayOfWeek = dayStr;
	idayOfWeek = dayInt;
	hoursInDay = 2400;
	turnOnTime_day = 0;
	turnOffTime_day = 0;
	turnOnTime_evening = 0;
	turnOffTime_evening = 0;
}


void Day::printDay()	//print the full schedule of the day
{
	std::cout << "\nDay: " << sDayOfWeek << "\nAutomatic Turn On Time (Day): " << turnOnTime_day << "\nAutomatic Turn Off Time (Day): " << turnOffTime_day 
		<<"\nAutomatic Turn On Time (Evening):" << turnOnTime_evening << "\nAutomatic Turn Off Time (Evening):" << turnOffTime_evening << "\n";
}
