//jeff henebury
//implementation of the WeekSchedule class and methods

#include "WeekSchedule.h"


WeekSchedule::WeekSchedule()
{
	//Cannot figure out a way to just construct each Day object from the get-go, doing via calls instead
	Sunday.sDayOfWeek = "Sunday";
	Sunday.idayOfWeek = 1;
	weeklySchedule.push_back(Sunday);
	Monday.sDayOfWeek = "Monday";
	Monday.idayOfWeek = 2;
	weeklySchedule.push_back(Monday);
	Tuesday.sDayOfWeek = "Tuesday";
	Tuesday.idayOfWeek = 3;
	weeklySchedule.push_back(Tuesday);
	Wednesday.sDayOfWeek = "Wednesday";
	Wednesday.idayOfWeek = 4;
	weeklySchedule.push_back(Wednesday);
	Thursday.sDayOfWeek = "Thursday";
	Thursday.idayOfWeek = 5;
	weeklySchedule.push_back(Thursday);
	Friday.sDayOfWeek = "Friday";
	Monday.idayOfWeek = 6;
	weeklySchedule.push_back(Friday);
	Saturday.sDayOfWeek = "Saturday";
	Saturday.idayOfWeek = 7;
	weeklySchedule.push_back(Saturday);
}

WeekSchedule::~WeekSchedule()
{
}

void WeekSchedule::setWeeklySchedule(int DayOnTime, int DayOffTime, int nightOnTime, int nightOffTime)
{
	//let's try passing a reference and an interator...
	for (Day &thisDay : weeklySchedule) {
		thisDay.turnOnTime_day = DayOnTime;
		thisDay.turnOffTime_day = DayOffTime;
		thisDay.turnOnTime_evening = nightOnTime;
		thisDay.turnOffTime_evening = nightOffTime;
	}
	
}

int WeekSchedule::getDayOfWeekFromString() {
	std::string n;
	std::cout << "Enter day: ";
	std::cin >> n;
	if (n == "Sunday") {
		return 1;
	}if (n == "Monday") {
		return 2;
	}
	if (n == "Tuesday") {
		return 3;
	}
	if (n == "Wednesday") {
		return 4;
	}
	if (n == "Thursday") {
		return 5;
	}
	if (n == "Friday") {
		return 6;
	}
	if (n == "Saturday") {
		return 7;
	}
	else {
		std::cout << "Invalid number!";
		return -1;
	}

}



void WeekSchedule::printWeeklySchedule()	//print out each day in the vector of Days
{
	for (Day & day : weeklySchedule) {
		day.printDay();
	}
}
