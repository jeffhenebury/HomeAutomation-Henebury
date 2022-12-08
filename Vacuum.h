//header file for vaccuum class
#pragma once
#ifndef VACUUM_H_
#define VACUUM_H_
#include "Device.h"
#include <vector>
#include <algorithm>

class Vacuum : public Device {
public:
	Vacuum();
	~Vacuum();
	std::vector <std::string> rooms;
	std::string currentRoom;	//tell vacuum what room to vacuum
	virtual void getSchedule();	//print out the current schedule
	virtual void setSchedule(std::string dayOfWeek); //input a day of the week, prompt for change to schedule
	virtual void doAction(); //make a sound when the device is running
	virtual std::string getCurrentRoom();
	virtual void setCurrentRoom(std::string newRoom);

};

#endif // !VACUUM_H_