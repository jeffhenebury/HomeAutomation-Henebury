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
	void getInput();
	void showOptionsForDevice();
	void showOptionsForThermostat();
	void showOptionsForTV();
	void showOptionsForLights();
	void showOptionsForSecurity();
	void showOptionsForVacuum();
	//void setDeviceSchedule(Device anyDevice);	//couldn't get this to work, going back to device specific

	//create an instance of each class, then a pointer to that object
	Device myDevice;	//base class object for testing
	Television myTelevision;
	Television* pMyTelevision;
	Thermostat myThermostat; 
	Thermostat* pMyThermostat;
	SecuritySystem mySecSystem;
	SecuritySystem* pMySecSystem;
	Vacuum myVac;
	Vacuum* pMyVac;
	Lights myLights;
	Lights* pMyLights;
	vector <Device> allDevices;
	//exeption checker
	int testTheInput(int lowest, int highest);


private:

};


#endif // !USERINTERFACE_H_

