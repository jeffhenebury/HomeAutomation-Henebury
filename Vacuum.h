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
	virtual std::string getCurrentRoom();
	virtual void setCurrentRoom(std::string newRoom);
	void printRooms(); //see what rooms are conencted to the device

};

#endif // !VACUUM_H_