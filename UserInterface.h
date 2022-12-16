//Jeff Henebury
//implementation of the UserInterface header file
//All the Device objects and their pointers are created here
#pragma once
#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>	//for reading the file and converting string to int
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
	vector <Device *> allDevices;
	//save device schedules to file
	void saveRecords(vector <Device*> allDevices);
	//load device schedules from file
	void loadRecords(vector <Device*> allDevices);


	//exeption checker
	int testTheInput(int lowest, int highest);

};


#endif // !USERINTERFACE_H_

