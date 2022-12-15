//Jeff Henebury
#include "Device.h"
#include <iostream>
using namespace std;

Device::Device()
{
	deviceSound = "Click! I'm a generic device!"; //will be overloaded for each device
	power = false; //start with power turned off
	DeviceSchedule;
	//for vacuum and lights, list of rooms
	rooms.push_back("Living Room");
	rooms.push_back("Dining Room");
	rooms.push_back("Bedroom");
	rooms.push_back("Kitchen");
}
Device ::~Device()
{
}
void Device::doAction()	//mimics the device doing its thing
{
	cout <<"\n" << deviceSound << endl;
}


void Device::getSchedule()
{
	DeviceSchedule.printWeeklySchedule();
}


bool Device::validateScheduleInput(int millTime)
{//making sure that the input time is in military time
	if (millTime >= 0 && millTime <= 2400) {
		return true;
	}
	else
	{
		return false;
	}
}


void Device::setSchedule()
{
	//get the schedule in military time, error check for bad input
	std::cout << "Let's set the schedule for your device." <<
		"Please use military time(i.e., '1750' for 5:30 PM\n";
	//do full week for now, give option for single day if there's time...
	int dayTurnOnTime;
	std::cout << "\nTurn-on time during the day: ";
	cin >> dayTurnOnTime;
	if (!validateScheduleInput(dayTurnOnTime)) {
		cout << "Sorry, that isn't in military time (0-2400). Please try again.\n";
		return;
	}
	std::cout << "\nTurn-off time during the day: ";
	int dayTurnOffTime;
	cin >> dayTurnOffTime;
	if (!validateScheduleInput(dayTurnOffTime)) {
		cout << "Sorry, that isn't in military time (0-2400). Please try again.\n";
		return;
	}
	std::cout << "\nTurn-on time during the evening: ";
	int nightTurnOnTime;
	cin >> nightTurnOnTime;
	if (!validateScheduleInput(nightTurnOnTime)) {
		cout << "Sorry, that isn't in military time (0-2400). Please try again.\n";
		return;
	}
	std::cout << "\nTurn-off time during the evening: ";
	int nightTurnOffTime;
	cin >> nightTurnOffTime;
	if (!validateScheduleInput(nightTurnOffTime)) {
		cout << "Sorry, that isn't in military time (0-2400). Please try again.\n";
		return;
	}
	DeviceSchedule.setWeeklySchedule(dayTurnOnTime, dayTurnOffTime, nightTurnOnTime, nightTurnOffTime);
	std::cout << "\nThank you! Printing the schedule:";
	DeviceSchedule.printWeeklySchedule();
}

void Device::getPowerStatus() {
	if (power) {
		cout << "The device is powered ON.\n";
	}
	else {
		cout << "The device is powered OFF.\n";
	}
}

void Device::onOrOff()
{
	int inp;
	cout << "Would you like the Device:\n1.ON\n2.OFF\n";
	cout << "Please enter 1 or 2: ";
	cin >> inp;
	if (inp == 1) { //on, so true
		cout << "\nYou have powered the device ON.\n";
		power = true; //turn power on
		doAction();
	}
	else {
		cout << "You have powered the device OFF.\n";
		power = false; //turn power off

	}
}

void Device::TestMorningOn() {
	//int morningTimeOn = DeviceSchedule.Sunday.turnOnTime_day;
	//cout << "TEST #2 with method TestMorningOn, Sunday morning on time: " << morningTimeOn << endl;
	int morningTimeOn = DeviceSchedule.weeklySchedule[0].turnOnTime_day;
	cout << "TEST #2 with method TestMorningOn, Sunday morning on time: " << morningTimeOn << endl;

}


