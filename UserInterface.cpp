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
using std::cout;
using std::cin;

UserInterface::UserInterface()
{	
	//point the pointers to the respective class instances
	pMyThermostat = &myThermostat;
	pMyTelevision = &myTelevision;
	pMyLights = &myLights;
	pMySecSystem = &mySecSystem;
	pMyVac = &myVac;
	//fill the Device vector with POINTERS to all the device objects 
	allDevices.push_back(pMyThermostat);
	allDevices.push_back(pMyTelevision);
	allDevices.push_back(pMyLights);
	allDevices.push_back(pMySecSystem);
	allDevices.push_back(pMyVac);
}

UserInterface::~UserInterface() //destructor
{
}
void UserInterface::getInput(){
	while (true) {
		std::cout << "Welcome to the Henebury Device Manager. We take care of all your devices!\n";
		std::cout << "Here is the list of connected Devices:\n";
		std::cout << "1.Thermostat\n2.Television\n3.Lights\n4.Security System\n5.Vacuum\n6.Save Power Status\n7.Load Schedule From File\n8.Exit program\n";
		std::cout << "\nWhich device would you like to access? (Enter 1-5, or 6 to exit): ";
		//exception catch: if it's not a number, catch the error, dump back to the main menu
		int input = testTheInput(1, 8);
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
			if (input == 6) {	//save schedule to file
				saveRecords(allDevices);
				continue;
			}
			if (input == 7) {	//load schedule from file
				loadRecords(allDevices);
				continue;
			}
			if (input == 8) {
				cout << "\nThank you for using the Henebury Device Manager. Goodbye!\n";
				break;
			}
	};
}


void UserInterface::showOptionsForThermostat()
{
	cout << "Great, you chose Thermostat.\n";
	while (true)
	{
		cout << "\n****\n";
		cout <<"Enter the number (1 - 6) of the option you'd like to select:\n";
		cout << "1.Check current power status\n2.Turn the system on or off\n3.Change the temperature\n"
			<< "4.Get current schedule\n5.Set schedule\n6.Quit to go back\n";
		//exception catch: if it's not a number, catch the error, dump back to the main menu
		int deviceInput = testTheInput(1, 6);
				if (deviceInput == 1) { //check power status
					pMyThermostat->getPowerStatus();
				};
				if (deviceInput == 2) {
					//cout << "TEST, you got to CHANGE POWER STATUS\N";
					pMyThermostat->onOrOff();
				};
				if (deviceInput == 3) {
					pMyThermostat->changeTheTemp();					
				};
				if (deviceInput == 4) {	//Getting current scheduling
					pMyThermostat->getSchedule();
					HoursOn(myThermostat);
				};
				if (deviceInput == 5) {	//setting scheduling
					pMyThermostat->setSchedule();
					HoursOn(myThermostat);
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
		cout << "\n****\n";
		cout << "Enter the number (1 - 6) of the option you'd like to select:\n";
		cout << "1.Check current power status\n2.Turn the lights on or off\n3.Get a list of light-connected rooms\n"
			<< "4.Get current schedule\n5.Set schedule\n6.Quit to go back\n";
		/*cout << "What would you like to do?\n";
		cin >> deviceInput;*/
		int deviceInput = testTheInput(1, 6);
		if (deviceInput == 1) {	//check power status
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
			HoursOn(myLights);
		};
		if (deviceInput == 5) {	//setting scheduling
			pMyLights->setSchedule();
			HoursOn(myLights);
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
		int newPower;
		cout << "Enter the number (1-4) of the option you'd like to select:\n";
		cout << "1.Check power status\n2.Turn the power off or on\n3.Get current schedule\n4.Set schedule\n5.Change security sensitivity level\n6.Quit to go back\n";
		cout << "What would you like to do?\n";
		//exception catch: if it's not a number, catch the error, dump back to the main menu
		int deviceInput = testTheInput(1, 6);
		if (deviceInput == 1) {	//check power
			pMySecSystem->getPowerStatus();
		};
		if (deviceInput == 2) { //turn on or off
			pMySecSystem->onOrOff();
		};
		if (deviceInput == 3) {	//get current schedule
			pMySecSystem->getSchedule();
			HoursOn(mySecSystem);
		};
		if (deviceInput == 4) {	//get current schedule
			pMySecSystem->setSchedule();
			HoursOn(mySecSystem);
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
		cout << "\n****\n";
		cout << "Enter the number (1-6) of the option you'd like to select:\n";
		cout << "1.Check current power status\n2.Turn the TV on or off\n3.Check the current channel\n4.Change the channel\n"
			<< "5.Get current schedule\n6.Set new schedule\n7.Quit to go back\n";
		cout << "What would you like to do?\n";
		//exception catch: if it's not a number, catch the error, dump back to the main menu
		int deviceInput = testTheInput(1, 7);
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
			HoursOn(myTelevision);
		};
		if (deviceInput == 6) { //change the schedule
			pMyTelevision->setSchedule();
			HoursOn(myTelevision);
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
			cout << "\n****\n";
			cout << "Enter the number (1 - 6) of the option you'd like to select:\n";
			cout << "1.Check current power status\n2.Turn the vacuum on or off\n3.Get a list of vacuum-connected rooms\n"
				<< "4.Get current schedule\n5.Set schedule\n6.Quit to go back\n";
			cout << "What would you like to do?\n";
			//exception catch: if it's not a number, catch the error, dump back to the main menu
			int deviceInput = testTheInput(1, 6);
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
				HoursOn(myVac);
			};
			if (deviceInput == 5) {	//setting scheduling
				pMyVac->setSchedule();
				HoursOn(myVac);
			};
			if (deviceInput == 6) {
				cout << "Back to Main Menu...\n";
				break;
			};
	}
}

//use Exception Handling to check the input. If it's not one of the options, send error message, clear input, redo
int UserInterface::testTheInput(int lowest, int highest)
{
	int deviceInput;
	while (true)
	{
		cout << "What would you like to do?\n";
		cin >> deviceInput;
		try
		{
			if ((deviceInput < lowest) || (deviceInput > highest)) {
				throw 101;
			}
			else {
				return deviceInput;
			}
		}
		catch (int badInput) {
			cout << "Error: please enter a digit between " << lowest << " and " <<highest << endl;
			cin.clear();    //clear inputted value
			while (cin.get() != '\n'); // empty the loop, start over
			continue;
		}

	}
}
//don't really need this one, just testing out the class to see if it works...
void UserInterface:: showOptionsForDevice()
{
	cout << "Great, you chose the secret testing option: Device.\n";
	while (true)
	{
		cout << "Enter the number (1-4) of the option you'd like to select:\n";
		cout << "1.Check power status\n2.Change the power status\n3.View the schedule\n4.Set schedule\n5.Quit to go back\n";
		cout << "What would you like to do?\n";
		//exception catch: if it's not a number, catch the error, dump back to the main menu
		int deviceInput = testTheInput(1, 6);
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
			HoursOn(myDevice);
		};
		if (deviceInput == 4) {
			cout << "TEST, you got to CHANGE SCHEDULE\n";
			myDevice.setSchedule();
			HoursOn(myDevice);
		};
		if (deviceInput == 5) {
			cout << "Back to Main Menu...\n";
			break;
		};
	}
}

//these are for saving the file

inline void UserInterface::ignoreNewLine()
{
}
//save the schedule for all devices
void UserInterface::saveRecords(vector<Device*> allDevices)
{
	//open file for writing
	try {
		cout << "\nWriting contents to file...";
		//open file for writing
		ofstream fw("Devices.txt", std::ofstream::out);
		//check if file was opened for writing
		if (fw.is_open())
		{
			//store contents to text file
			for (int i = 0; i < allDevices.size(); i++) {
				//save schedule for just one day, since all days have the same schedule for now...
					fw << allDevices[i]->DeviceSchedule.weeklySchedule[0].turnOnTime_day << "\n";
					fw << allDevices[i]->DeviceSchedule.weeklySchedule[0].turnOffTime_day << "\n";
					fw << allDevices[i]->DeviceSchedule.weeklySchedule[0].turnOnTime_evening << "\n";
					fw << allDevices[i]->DeviceSchedule.weeklySchedule[0].turnOffTime_evening << "\n";

				//this works to get the power status:  //fw << allDevices[i]->power<< "\n";
				//save the schedule of each device to the file
				//for (int d = 0; d < 7; d++) {	//inner loop, to get to every day of the week??
				//	fw << allDevices[i]->DeviceSchedule.weeklySchedule[d].turnOnTime_day << "\n";
				//	fw << allDevices[i]->DeviceSchedule.weeklySchedule[d].turnOffTime_day << "\n";
				//	fw << allDevices[i]->DeviceSchedule.weeklySchedule[d].turnOnTime_evening << "\n";
				//	fw << allDevices[i]->DeviceSchedule.weeklySchedule[d].turnOffTime_evening << "\n";
				///*}*/			
			}
			fw.close();
		}
		else cout << "Problem with opening file";
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
	cout << "\nDone!\n";
}

//load in the schedules for all devices
void UserInterface::loadRecords(vector<Device*> allDevices)
{
	ifstream theReadInFile;
	string sReadLine;
	int iReadLine;

	theReadInFile.open("Devices.txt", std::ofstream::out);	//open file
	if (!theReadInFile)
	{
		cout << "Error opening the file.\n";
	}
	else {
		//get the schedule for each device in the vector, plop in the line from the file
		for (int i = 0; i < allDevices.size(); i++) {
			//get 4 lines of input, since we have to fill in 4 lines for each day for each device (time on-morning, time-on-night, etc.)
			//we're just saving the first day, so get just the first day per device...
			std::getline(theReadInFile, sReadLine);
			stringstream(sReadLine) >> iReadLine;	//convert file string to int
			int turnOnTime_day = iReadLine;
			std::getline(theReadInFile, sReadLine);
			stringstream(sReadLine) >> iReadLine;
			int turnOffTime_day = iReadLine;
			std::getline(theReadInFile, sReadLine);
			stringstream(sReadLine) >> iReadLine;
			int turnOnTime_evening = iReadLine;
			std::getline(theReadInFile, sReadLine);
			stringstream(sReadLine) >> iReadLine;
			int turnOffTime_evening = iReadLine;
			// ... and then based off of that first day, set the schedule for the rest of the week for that device, then move on to next device
			allDevices[i]->DeviceSchedule.setWeeklySchedule(turnOnTime_day, turnOffTime_day, turnOnTime_evening, turnOffTime_evening);
			//allDevices[i]->DeviceSchedule.weeklySchedule[0].turnOnTime_day = iReadLine;
			//allDevices[i]->DeviceSchedule.weeklySchedule[0].turnOffTime_day = iReadLine;
			//allDevices[i]->DeviceSchedule.weeklySchedule[0].turnOnTime_evening = iReadLine;
			//allDevices[i]->DeviceSchedule.weeklySchedule[0].turnOffTime_evening = iReadLine;


			//inner loop, to get to every day of the week??
			//for (int d = 0; d < 7; d++) {	
			//	std::getline(theReadInFile, sReadLine);
			//	stringstream(sReadLine) >> iReadLine;	//convert string to int
			//	allDevices[i]->DeviceSchedule.weeklySchedule[d].turnOnTime_day = iReadLine;
			//	allDevices[i]->DeviceSchedule.weeklySchedule[d].turnOffTime_day = iReadLine;
			//	allDevices[i]->DeviceSchedule.weeklySchedule[d].turnOnTime_evening = iReadLine;
			//	allDevices[i]->DeviceSchedule.weeklySchedule[d].turnOffTime_evening = iReadLine;

			//}
		}
		theReadInFile.close();
		cout << "\nFile successfully loaded!\n\n";
	}

}
