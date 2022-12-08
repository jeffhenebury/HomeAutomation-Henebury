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
#include <cctype>
#include <string>
using namespace std;

UserInterface::UserInterface()
{
	devices = { "Thermostat", "TV", "Lights" , "Security"};
	//Device myDevice;
}

UserInterface::~UserInterface() //destructor
{
}
void UserInterface::getInput(){
	while (true) {
		//string input;	//moving to int
		int input;
		cout << "Welcome to the Henebury Device Manager. We take care of all your devices!\n";
		cout << "Here is the list of connected Devices:\n";
		cout << "1.Thermostat\n2.Television\n3.Lights\n4.Security System\n5.Vacuum\n6.Exit program\n";
		//LoopThroughDevices();
		cout << "\nWhich device would you like to access? (Enter 1-5, or 6 to exit): ";
		cin >> input;
		/*std::transform(input.begin(), input.end(), input.begin(),
			[](unsigned char c) { return std::tolower(c); });*/
		//if (input == "device") {
			if (input == 0) {
			//cout << "TEST, you put in the secret input for Device.\n";
			showOptionsForDevice();
			continue;	//after you exit the device loop, back to the all-device loop
		};
		if (input == 1) {
			//cout << "TEST, you put in thermostat.\n";
			showOptionsForThermostat();
			continue;
		};
		if (input == 2) {
			//cout << "TEST, you put in TV.\n";
			showOptionsForTV();
			continue;
		};
		if (input == 3) {
		//	cout << "TEST, you put in lights.\n";
			showOptionsForLights();
			continue;
		};
		if (input == 4) {
		//	cout << "TEST, you put in security system.\n";
			showOptionsForSecurity();
			continue;
		};
		if (input == 5) {
		//	cout << "TEST, you put in Vacuum.\n";
			showOptionsForVacuum();
			continue;
		};
		if (input == 6) {
			cout << "\nThank you for using the Henebury Device Manager. Goodbye!\n";
			break;
		};
	};

}
void UserInterface::LoopThroughDevices()
{
	for (int i = 0; i < devices.size(); i++) {
		cout <<(i+1) <<"." << devices[i] << endl;
	}
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
		/*std::transform(deviceInput.begin(), deviceInput.end(), deviceInput.begin(),
			[](unsigned char c) { return std::tolower(c); });*/
		if (deviceInput == 1) {
			cout << "\nTEST, you got to POWER STATUS\n";
			myThermostat.getPowerStatus();
		};
		if (deviceInput == 2) {
			//cout << "TEST, you got to CHANGE POWER STATUS\N";
			myThermostat.onOrOff();
		};
		if (deviceInput == 3) {
			myThermostat.changeTheTemp();
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
			myThermostat.getSchedule();
		};
		if (deviceInput == 5) {	//setting scheduling
			myThermostat.setSchedule();
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
		cout << "Enter the number (1-4) of the option you'd like to select:\n";
		cout << "1.Check power status\n2.Turn the power on or off\n3.View current schedule"<<
			"\n4.Set schedule\n5.Quit to go back\n";
		cout << "What would you like to do?\n";
		cin >> deviceInput;
		/*std::transform(deviceInput.begin(), deviceInput.end(), deviceInput.begin(),
			[](unsigned char c) { return std::tolower(c); });*/
		if (deviceInput == 1) {
			cout << "TEST, you got to POWER STATUS\N";
			myDevice.getPowerStatus();
		};
		if (deviceInput == 2) {
			cout << "TEST, you got to CHANGE POWER STATUS\N";
			myLights.onOrOff();
		};
		if (deviceInput == 3) {
			//view schedule
			myLights.getSchedule();
		};
		if (deviceInput == 4) {
			cout << "TEST, you got to CHANGE SCHEDULE\N";
			myLights.setSchedule();
			//UserInterface::setDeviceSchedule(myLights);
		};
		if (deviceInput == 5) {
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
		cout << "1.Check power status\n2.Turn the power off or on\n3.Set schedule\n4.Change sensitivity level of the lights\n5.Quit to go back\n";
		cout << "What would you like to do?\n";
		cin >> deviceInput;
		/*std::transform(deviceInput.begin(), deviceInput.end(), deviceInput.begin(),
			[](unsigned char c) { return std::tolower(c); });*/
		if (deviceInput == 1) {
		//	cout << "TEST, you got to POWER STATUS\N";
			mySecSystem.getPowerStatus();
		};
		if (deviceInput == 2) {
	//		cout << "TEST, you got to CHANGE POWER STATUS\N";
			mySecSystem.onOrOff();
		};
		if (deviceInput == 3) {
			//NEED TO FIGURE OUT SCHEDULE
			cout << "****************TEST, NEED TO FIGURE OUT SCHEDULE**************\N.";
		};
		if (deviceInput == 4) {
		//	cout << "TEST, you got to CHANGE SECURITY LIGHT SENSITIVITY\N";
			cout << "What would you like the security system's sensitivity level to be set to? (1 lowest, 5 highest): ";
			cin >> newPower;
			mySecSystem.setLightSensitivity(newPower);

		};
		if (deviceInput == 5) {
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
		if (deviceInput == 1) {	//check power suatus
			myTelevision.getPowerStatus();
		};
		if (deviceInput == 2) { //set new power status
			myTelevision.onOrOff();
		};
		if (deviceInput == 3) { //check current channel
			cout << "The current channel is set to: " << myTelevision.getCurrentChannel() << ".(I love this show!)\n";
		};
		if (deviceInput == 4) { //change the channel
			int newChannel;
			int oldChannel = myTelevision.getCurrentChannel();
			//cout << "TEST, you got to CHANGE THE CHANNEL.\N";
			cout << "The current channel is set to: " << oldChannel << ".\n";
			cout << "What would you like to change it to?\n";
			cin >> newChannel;
			myTelevision.setCurrentChannel(newChannel);
			if (oldChannel < newChannel) {
				cout << "Great, you've turned the channel up to: " << myTelevision.getCurrentChannel() << ". Hope something good is on!\n";
			}
			else if (oldChannel > newChannel) {
				cout << "Great, you've turned the channel down to: " << myTelevision.getCurrentChannel() << ". Hope something good is on!\n";
			}
		};
		if (deviceInput == 5) {	//get current schedule
			myTelevision.getSchedule();
		};
		if (deviceInput == 6) { //change the schedule
			myTelevision.setSchedule();
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
		cout << "Enter the number (1-4) of the option you'd like to select:\n";
		cout << "1.Check power status\n2.Turn the power on or off\n3.Change the room you're vaccumming\n4.Set schedule\n5.Quit to go back\n";
		cout << "What would you like to do?\n";
		cin >> deviceInput;
		/*std::transform(deviceInput.begin(), deviceInput.end(), deviceInput.begin(),
			[](unsigned char c) { return std::tolower(c); });*/
		if (deviceInput == 1) {
			cout << "TEST, you got to POWER STATUS\N";
			myVac.getPowerStatus();
		};
		if (deviceInput == 2) {
			cout << "TEST, you got to CHANGE POWER STATUS\N";
			myVac.onOrOff();
		};
		if (deviceInput == 3) {
			cout << "TEST, you got to CHANGE ROOM\N";
			myVac.onOrOff();
		};
		if (deviceInput == 4) {
			//NEED TO FIGURE OUT SCHEDULE
			cout << "****************TEST, NEED TO FIGURE OUT SCHEDULE**************\N.";
		};
		if (deviceInput == 5) {
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

//a one-stop shop for scheduling all devices?? Unfortunately does not seem to persist in memory, not sure why
//void UserInterface::setDeviceSchedule(Device anyDevice) {
//	std::cout << "Let's set the schedule for your device." <<
//		"Please use military time(i.e., '1750' for 5:30 PM\n";
//	//do full week for now, give option for single day if there's time...
//	int dayTurnOnTime;
//	std::cout << "\nTurn-on time during the day: ";
//	cin >> dayTurnOnTime;
//	std::cout << "\nTurn-off time during the day: ";
//	int dayTurnOffTime;
//	cin >> dayTurnOffTime;
//	std::cout << "\nTurn-on time during the evening: ";
//	int nightTurnOnTime;
//	cin >> nightTurnOnTime;
//	std::cout << "\nTurn-off time during the evening: ";
//	int nightTurnOffTime;
//	cin >> nightTurnOffTime;
//	anyDevice.DeviceSchedule.setWeeklySchedule(dayTurnOnTime, dayTurnOffTime, nightTurnOnTime, nightTurnOffTime);
//	std::cout << "\nThank you! Printing the schedule:";
//	anyDevice.DeviceSchedule.printWeeklySchedule();
//
//}

