//header file for security system class
#pragma once
#ifndef SECURITYSYSTEM_H_
#define SECURITYSYSTEM_H_
#include "Device.h"

class SecuritySystem : public Device {
public:
	SecuritySystem();
	~SecuritySystem();
	int currentSensitivity;
	//virtual void getSchedule();	//print out the current schedule
	//virtual void setSchedule(std::string dayOfWeek); //input a day of the week, prompt for change to schedule
	virtual void doAction(); //make a sound when the device is running
	virtual double getLightSensitivity();
	virtual void setLightSensitivity(int lightSensitivity);

};

#endif // SECURITYSYSTEM_H_