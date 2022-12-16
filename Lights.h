//Jeff Henebury
//implementation of the Lights header file
//can see what rooms the lights arec onnected to

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
	string currentRoom;	//tell vacuum what room to change... this is later functionality, not implemented yet
	virtual std::string getCurrentRoom();
	virtual void setCurrentRoom(std::string newRoom);
	void printRooms();

};

#endif // !LIGHTS_H_