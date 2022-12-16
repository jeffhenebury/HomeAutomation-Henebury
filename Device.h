#pragma once
#ifndef DEVICE_H_
#define DEVICE_H_
#include <string>
#include <iostream>
#include "WeekSchedule.h"

//user-defined template. Get any device type, add up the total hours of run time per day!
template <typename T>  void HoursOn(T anyDevice) {
	int morningTimeOn = anyDevice.DeviceSchedule.weeklySchedule[0].turnOnTime_day;
	int morningTimeOff = anyDevice.DeviceSchedule.weeklySchedule[0].turnOffTime_day;
	int nightTimeOn = anyDevice.DeviceSchedule.weeklySchedule[0].turnOnTime_evening;
	int nightTimeOff = anyDevice.DeviceSchedule.weeklySchedule[0].turnOffTime_evening;
	//std::cout << "TEST, Morning time on: " << morningTimeOn << endl;
	float totalHoursOn = ((static_cast<float>(morningTimeOff) - morningTimeOn) + (nightTimeOff - nightTimeOn)) / 100;
	std::cout << "\n*Total hours this device is on per day: " << totalHoursOn << " *\n";

}

class Device 
{
public:
	Device ();
	~Device (); //default destructor
	bool power;	//false for off, true for on
	std::string deviceSound; //will be overloaded for each device
	WeekSchedule DeviceSchedule;
	std::vector <std::string> rooms;	//for those devices where we need to know specific rooms... this could be built out more later
	virtual void getPowerStatus(); //a way to find if the device is currently on or off
	virtual void onOrOff(); //user inputs whether they want the device turned on or off
	virtual void getSchedule();	//print out the current schedule
	virtual bool validateScheduleInput(int millTime); //make sure input matches correct format
	virtual void setSchedule();
	virtual void doAction(); //make a sound when the device is running
	virtual void TestMorningOn();


private:


};



#endif // !DEVICE_H_
