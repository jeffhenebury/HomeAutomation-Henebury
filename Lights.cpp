//jeff henebury
//implementation of the Lights class and methods
//
#include "Lights.h"

Lights::Lights()
{
	currentRoom = "Living Room";
	deviceSound = "CLICK! (There go the lights!)\n";
}

Lights::~Lights()
{
}

std::string Lights::getCurrentRoom()
{
	return currentRoom;
}

void Lights::setCurrentRoom(std::string newRoom)
{
	if (std::find(rooms.begin(), rooms.end(), newRoom) != rooms.end()) 		//check the rooms vector for the input
	{
		currentRoom = newRoom;
	}
	else {
		std::cout << "I'm sorry, but " << newRoom << " is not in my list of rooms! Please try again.\n";
	};
}

void Lights::printRooms()
{
	if (power) {
		cout << "Lights are currently ON in the following rooms:\n";

	}
	else if (!power) {
		cout << "Lights are currently OFF in the following rooms:\n";
	}
	for (string room : rooms) {
		cout << room << "\n";
	}
}
