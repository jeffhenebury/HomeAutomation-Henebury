#pragma once
//header file for lights class, **CLEAN THIS UP**
#pragma once
#ifndef LIGHTS_H_
#define LIGHTS_H_
#include "Device.h"
#include <vector>
#include <algorithm>

class Lights : public Device {
public:
	Lights();
	~Lights();
	std::vector <std::string> rooms;
	std::string currentRoom;	//tell vacuum what room to vacuum
	bool power;
	WeekSchedule lightsSchedule;

	virtual void getSchedule();	//print out the current schedule
	virtual void setSchedule(std::string dayOfWeek); //input a day of the week, prompt for change to schedule
	virtual void doAction(); //make a sound when the device is running
	virtual std::string getCurrentRoom();
	virtual void setCurrentRoom(std::string newRoom);

};

#endif // !LIGHTS_H_