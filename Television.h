#pragma once
#ifndef TELEVISION_H_
#define TELEVISION_H_
#include "Device.h"

class Television: public Device {
public:
	Television();
	~Television();
	int currentChannel;
	bool power;
	virtual void getSchedule();	//print out the current schedule
	virtual void setSchedule(std::string dayOfWeek); //input a day of the week, prompt for change to schedule
	virtual void doAction(); //make a sound when the device is running
	virtual double getCurrentChannel();
	virtual void setCurrentChannel(int newChannel);

};

#endif // !TELEV:ISION_H_