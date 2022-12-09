#pragma once
//header file for lights class, **CLEAN THIS UP**
#pragma once
#ifndef LIGHTS_H_
#define LIGHTS_H_
#include "Device.h"
#include <vector>
#include <algorithm>

class Lights : public Device {
public:
	Lights();
	~Lights();
	string currentRoom;	//tell vacuum what room to change... this is later functionality
	virtual std::string getCurrentRoom();
	virtual void setCurrentRoom(std::string newRoom);
	void printRooms();

};

#endif // !LIGHTS_H_