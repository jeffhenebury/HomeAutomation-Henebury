#pragma once
#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_
#include <vector>
#include "Device.h"
#include "Thermostat.h"
#include "Television.h"
#include "SecuritySystem.h"
#include "Vacuum.h"
#include "Lights.h"
#include "WeekSchedule.h"
#include <string>


class UserInterface
{
public:
	UserInterface();
	~UserInterface();
	std::vector <std::string> devices;
	void LoopThroughDevices();
	void getInput();
	void showOptionsForDevice();
	void showOptionsForThermostat();
	void showOptionsForTV();
	void showOptionsForLights();
	void showOptionsForSecurity();
	void showOptionsForVacuum();
	void getDeviceSchedule(Device anyDevice);

	Device myDevice;	//for testing
	Television myTelevision;
	Thermostat myThermostat; 
	SecuritySystem mySecSystem;
	Vacuum myVac;
	Lights myLights;

	

private:

};


#endif // !USERINTERFACE_H_

