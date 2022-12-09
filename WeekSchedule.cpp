#include "WeekSchedule.h"


WeekSchedule::WeekSchedule()
{
	//start = std::chrono::steady_clock::now(); //set start time as moment the schedule is made
	//end = std::chrono::steady_clock::duration(604800, 1);
	/*const static std::string daysOfWeek[] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
	};*/
	//this doesn't compile...
	//Day Sunday("Sunday", 1);
	//Day Monday("Monday", 2);
	//Day Tuesday("Tuesday", 3);
	//Day Wednesday("Wednesday", 4);
	//Day Thursday("Thursday", 5);
	//Day Friday("Friday", 6);
	//Day Saturday("Saturday", 7);
	//weeklySchedule = { Sunday, Monday,Tuesday,Wednesday,Thursday,Friday,Saturday };
	// 
	// 
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



	//std::chrono::hours week = std::chrono::hours(168); //168 hours in a week
	//std::chrono::hours day = std::chrono::hours(24); //24 hours in a day
	//std::chrono::hours hour = std::chrono::hours(1); //i hour in an hour
}

WeekSchedule::~WeekSchedule()
{
}



void WeekSchedule::setWeeklySchedule(int DayOnTime, int DayOffTime, int nightOnTime, int nightOffTime)
{
	//get the day from the , change its times for each day
	//this first loop doesn't work, i think it's just making a copy of the objects in the vector...
	// 
	//for (Day day : weeklySchedule) {
	//	day.turnOnTime_day = DayOnTime;
	//	day.turnOffTime_day = DayOffTime;
	//	day.turnOnTime_evening = nightOnTime;
	//	day.turnOffTime_evening = nightOffTime;
	//}

	//so let's try passing a reference and an interator...
	for (auto& day : weeklySchedule) {
		day.turnOnTime_day = DayOnTime;
		day.turnOffTime_day = DayOffTime;
		day.turnOnTime_evening = nightOnTime;
		day.turnOffTime_evening = nightOffTime;
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
