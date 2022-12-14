//implementation of User Interface class
/*
doing this via loops: 
an initial 'choose your device or quit' loop
and then, within each device, a 'choose what you want to do with that device' loop
*/
#pragma once
#include "UserInterface.h"
#include <iostream>
#include <algorithm>	//for transform
#include <string>
using namespace std;

UserInterface::UserInterface()
{	
	//point the pointers to the respective class instances
	pMyThermostat = &myThermostat;
	pMyTelevision = &myTelevision;
	pMyLights = &myLights;
	pMySecSystem = &mySecSystem;
	pMyVac = &myVac;
	//fill the Device vector with all the device objects 
	allDevices.push_back(myThermostat);
	allDevices.push_back(myTelevision);
	allDevices.push_back(myLights);
	allDevices.push_back(mySecSystem);
	allDevices.push_back(myVac);
}

UserInterface::~UserInterface() //destructor
{
}
void UserInterface::getInput(){
	int input;
	while (true) {
		cout << "Welcome to the Henebury Device Manager. We take care of all your devices!\n";
		cout << "Here is the list of connected Devices:\n";
		cout << "1.Thermostat\n2.Television\n3.Lights\n4.Security System\n5.Vacuum\n6.Exit program\n";
		cout << "\nWhich device would you like to access? (Enter 1-5, or 6 to exit): ";
		if ((cin >> input)) {
			if (input == 0) {	//base class Device, just for testing purposes
			showOptionsForDevice();
			continue;
			}
			if (input == 1) {	//thermostat
				showOptionsForThermostat();
				continue;
			}
			if (input == 2) {	//TV
				showOptionsForTV();
				continue;
			}
			if (input == 3) {	//lights
				showOptionsForLights();
				continue;
			}
			if (input == 4) {	//security system
				showOptionsForSecurity();
				continue;
			}
			if (input == 5) {	//vacuum
				showOptionsForVacuum();
				continue;
			}
			if (input == 6) {
				cout << "\nThank you for using the Henebury Device Manager. Goodbye!\n";
				break;
			}
		}
		else {
			// not a valid number, give error message and redo the loop
			cout << "\nInvalid Input! Please input a numerical value.\n\n";
			cin.clear();    //clear inputted value
			while (cin.get() != '\n'); // empty the loop, start over
		};
	};
}


void UserInterface::showOptionsForThermostat()
{
	cout << "Great, you chose Thermostat.\n";
	while (true)
	{
		int deviceInput;
		cout << "\n****\n";
		cout <<"Enter the number (1 - 6) of the option you'd like to select:\n";
		cout << "1.Check current power status\n2.Turn the system on or off\n3.Change the temperature\n"
			<< "4.Get current schedule\n5.Set schedule\n6.Quit to go back\n";
		cout << "What would you like to do?\n";
		cin >> deviceInput;
		//if it's not a number, catch the error, dump back to the main menu
		/*try
		{
			cin >> deviceInput;
			if (!isdigit(deviceInput)) {
				throw "TEST, You have to put in a number!";
			}
		}
		catch (const std::exception& bad)
		{
			cout << bad.what() << endl;
			cout << "Returning to Main Menu.\n";
			return;
		}
		*/
		if (deviceInput == 1) { //check power status
			pMyThermostat->getPowerStatus();
		};
		if (deviceInput == 2) {
			//cout << "TEST, you got to CHANGE POWER STATUS\N";
			pMyThermostat->onOrOff();
		};
		if (deviceInput == 3) {
			pMyThermostat->changeTheTemp();
			//put the below into a method instead...
			/*int newTemp;
			int oldTemp = myThermostat.getCurrentTemp();
			cout << "TEST, you got to CHANGE THE TEMPERATURE.\N";
			cout << "The current temperature is set to: " << oldTemp << " degrees.\n";
			cout << "What would you like to change it to?";
			cin >> newTemp;
			myThermostat.setCurrentTemp(newTemp);
			if (oldTemp < newTemp) {
				cout << "Great, you've turned the temperature up to: " << myThermostat.getCurrentTemp() << " degrees.\n";
			}
			else if (oldTemp > newTemp) {
				cout << "Great, you've turned the temperature down to: " << myThermostat.getCurrentTemp() << " degrees.\n";
			}*/
		};
		if (deviceInput == 4) {	//Getting current scheduling
			pMyThermostat->getSchedule();
		};
		if (deviceInput == 5) {	//setting scheduling
			pMyThermostat->setSchedule();
		};
		if (deviceInput == 6) {
			cout << "Back to Main Menu...\n";
			break;
		};
	}
}

void UserInterface::showOptionsForLights()
{
	cout << "Great, you chose Lights.\n";
	while (true)
	{
		int deviceInput;
		cout << "\n****\n";
		cout << "Enter the number (1 - 6) of the option you'd like to select:\n";
		cout << "1.Check current power status\n2.Turn the lights on or off\n3.Get a list of light-connected rooms\n"
			<< "4.Get current schedule\n5.Set schedule\n6.Quit to go back\n";
		cout << "What would you like to do?\n";
		cin >> deviceInput;
		//if it's not a number, catch the error, dump back to the main menu
	/*	try
		{
			if (isdigit(deviceInput)) {
				continue;
			}
			else {
				throw std::runtime_error("not a number!");
			}
		}
		catch (const std::exception& bad)
		{
			cout << bad.what() << endl;
			cout << "Returning to Main Menu.\n";
			return;
		}*/
		if (deviceInput == 1) {
			//cout << "\nTEST, you got to POWER STATUS\n";
			pMyLights->getPowerStatus();
		};
		if (deviceInput == 2) {
			pMyLights->onOrOff();
		};
		if (deviceInput == 3) {	//get a list of rooms, see if they're on or off
			pMyLights->printRooms();
		};
		if (deviceInput == 4) {	//Getting current scheduling
			pMyLights->getSchedule();
		};
		if (deviceInput == 5) {	//setting scheduling
			pMyLights->setSchedule();
		};
		if (deviceInput == 6) {
			cout << "Back to Main Menu...\n";
			break;
		};
	}
}

void UserInterface::showOptionsForSecurity()
{
	cout << "Great, you chose Security System.\n";
	while (true)
	{
		int deviceInput;
		int newPower;
		cout << "Enter the number (1-4) of the option you'd like to select:\n";
		cout << "1.Check power status\n2.Turn the power off or on\n3.Get current schedule\n4.Set schedule\n5.Change security sensitivity level\n6.Quit to go back\n";
		cout << "What would you like to do?\n";
		cin >> deviceInput;
		if (deviceInput == 1) {	//check power
			pMySecSystem->getPowerStatus();
		};
		if (deviceInput == 2) { //turn on or off
			pMySecSystem->onOrOff();
		};
		if (deviceInput == 3) {	//get current schedule
			pMySecSystem->getSchedule();
		};
		if (deviceInput == 4) {	//get current schedule
			pMySecSystem->setSchedule();
		};
		if (deviceInput == 5) {	//chnge sensitivy level
			cout << "What would you like the security system's sensitivity level to be set to? (1 lowest, 5 highest): ";
			cin >> newPower;
			pMySecSystem->setLightSensitivity(newPower);
		};
		if (deviceInput == 6) {
			cout << "Back to Main Menu...\n";
			break;
		};
	}
}

void UserInterface::showOptionsForTV()
{
	cout << "Great, you chose TV.\n";
	while (true)
	{
		int deviceInput;
		cout << "\n****\n";
		cout << "Enter the number (1-6) of the option you'd like to select:\n";
		cout << "1.Check current power status\n2.Turn the TV on or off\n3.Check the current channel\n4.Change the channel\n"
			<< "5.Get current schedule\n6.Set new schedule\n7.Quit to go back\n";
		cout << "What would you like to do?\n";
		cin >> deviceInput;
		/*std::transform(deviceInput.begin(), deviceInput.end(), deviceInput.begin(),
			[](unsigned char c) { return std::tolower(c); });*/
		if (deviceInput == 1) {	//check power status
			pMyTelevision->getPowerStatus();
		};
		if (deviceInput == 2) { //set new power status
			pMyTelevision->onOrOff();
		};
		if (deviceInput == 3) { //check current channel
			cout << "The current channel is set to: " << pMyTelevision->getCurrentChannel() << ".(I love this show!)\n";
		};
		if (deviceInput == 4) { //change the channel
			int newChannel;
			int oldChannel = pMyTelevision->getCurrentChannel();
			cout << "The current channel is set to: " << oldChannel << ".\n";
			cout << "What would you like to change it to?\n";
			cin >> newChannel;
			pMyTelevision->setCurrentChannel(newChannel);
			if (oldChannel < newChannel) {
				cout << "Great, you've turned the channel up to: " << pMyTelevision->getCurrentChannel() << ". Hope something good is on!\n";
			}
			else if (oldChannel > newChannel) {
				cout << "Great, you've turned the channel down to: " << pMyTelevision->getCurrentChannel() << ". Hope something good is on!\n";
			}
		};
		if (deviceInput == 5) {	//get current schedule
			pMyTelevision->getSchedule();
		};
		if (deviceInput == 6) { //change the schedule
			pMyTelevision->setSchedule();
		};
		if (deviceInput == 7) { //back to main menu
			cout << "Back to Main Menu...\n";
			break;
		};
	}
}

void UserInterface::showOptionsForVacuum() {
	cout << "Great, you chose Vacuum.\n";
	while (true)
		{
			int deviceInput;
			cout << "\n****\n";
			cout << "Enter the number (1 - 6) of the option you'd like to select:\n";
			cout << "1.Check current power status\n2.Turn the vacuum on or off\n3.Get a list of vacuum-connected rooms\n"
				<< "4.Get current schedule\n5.Set schedule\n6.Quit to go back\n";
			cout << "What would you like to do?\n";
			cin >> deviceInput;
			/*std::transform(deviceInput.begin(), deviceInput.end(), deviceInput.begin(),
				[](unsigned char c) { return std::tolower(c); });*/
			if (deviceInput == 1) { //check power status
				pMyVac->getPowerStatus();
			};
			if (deviceInput == 2) {
				pMyVac->onOrOff();
			};
			if (deviceInput == 3) {	//get a list of rooms, see if they're on or off
				pMyVac->printRooms();
			};
			if (deviceInput == 4) {	//Getting current scheduling
				pMyVac->getSchedule();
			};
			if (deviceInput == 5) {	//setting scheduling
				pMyVac->setSchedule();
			};
			if (deviceInput == 6) {
				cout << "Back to Main Menu...\n";
				break;
			};
	}
}

//don't really need this one, just testing out the class to see if it works...
void UserInterface:: showOptionsForDevice()
{
	cout << "Great, you chose the secret testing option: Device.\n";
	while (true)
	{
		int deviceInput;
		cout << "Enter the number (1-4) of the option you'd like to select:\n";
		cout << "1.Check power status\n2.Change the power status\n3.View the schedule\n4.Set schedule\n5.Quit to go back\n";
		cout << "What would you like to do?\n";
		cin >> deviceInput;
		/*std::transform(deviceInput.begin(), deviceInput.end(), deviceInput.begin(),
			[](unsigned char c) { return std::tolower(c); });*/
		if (deviceInput == 1) {
			cout << "TEST, you got to POWER STATUS\n";
			myDevice.getPowerStatus();
		};
		if (deviceInput == 2) {
			cout << "TEST, you got to CHANGE POWER STATUS\n";
			myDevice.onOrOff();
		};
		if (deviceInput == 3) {
			cout << "TEST, you got to VIEW SCHEDULE\n";
			myDevice.getSchedule();
		};
		if (deviceInput == 4) {
			cout << "TEST, you got to CHANGE SCHEDULE\n";
			myDevice.setSchedule();
			//UserInterface::setDeviceSchedule(myDevice);
		};
		if (deviceInput == 5) {
			cout << "Back to Main Menu...\n";
			break;
		};
	}
}

