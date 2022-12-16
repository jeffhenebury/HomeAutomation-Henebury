//Jeff Henebury
//header file for vacuum class
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
	std::string currentRoom;	//tell vacuum what room to vacuum; to be implemented more later
	virtual std::string getCurrentRoom();
	virtual void setCurrentRoom(std::string newRoom);
	void printRooms(); //see what rooms are conencted to the device

};

#endif // !VACUUM_H_