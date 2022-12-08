#include "Lights.h"

Lights::Lights()
{

	currentRoom = "Living Room";
	std::vector <std::string> rooms = { "living room", "dining room", "bedroom" };
	std::string deviceSound = "CLICK! (There go the lights!)\n";
	//lightsSchedule;

}

Lights::~Lights()
{
}


void Lights::doAction()
{
	std::cout << "CLICK! (There go the lights!)\n";
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
