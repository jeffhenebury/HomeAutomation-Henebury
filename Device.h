#pragma once
#ifndef DEVICE_H_
#define DEVICE_H_
#include <string>
#include <chrono>
#include <iostream>
#include "WeekSchedule.h"

class Device 
{
public:
	Device ();
	~Device (); //default destructor
	bool power;	//false for off, true for on
	std::string deviceSound; //will be overloaded for each device
	WeekSchedule DeviceSchedule;

	virtual void getPowerStatus(); //a way to find if the device is on or off
	virtual void onOrOff(); //user inputs whether they want the device turned on or off
	//virtual void setPowerStatus(bool tOrF); //press powerbutton, if on turn off, else it's off and turn on
	virtual void getSchedule();	//print out the current schedule
	virtual void setSchedule();
	virtual void doAction(); //make a sound when the device is running


private:


};



#endif // !DEVICE_H_
