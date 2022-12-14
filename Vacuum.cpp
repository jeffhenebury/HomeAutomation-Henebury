#include "Vacuum.h"

Vacuum::Vacuum()
{
	currentRoom = "Living Room";
	//std::vector <std::string> rooms = { "living room", "dining room", "bedroom" };
	rooms.push_back("living room");
	rooms.push_back("dining room");
	rooms.push_back("bedroom");
	deviceSound = "VROOOOOOOM! (Sorry kitten, I know you're scared of the vacuum!)\n";
}

Vacuum::~Vacuum()
{
}

std::string Vacuum::getCurrentRoom()
{
	return currentRoom;
}

void Vacuum::setCurrentRoom(std::string newRoom)
{
	if (std::find(rooms.begin(), rooms.end(), newRoom) != rooms.end()) 		//check the rooms vector for the input
	{
		currentRoom = newRoom;
	}
	else {
		std::cout << "I'm sorry, but " << newRoom << " is not in my list of rooms! Please try again.\n";
	};
}

void Vacuum::printRooms()
{
	if (power) {
		cout << "Vacuum is currently ON and cleaning the following rooms:\n";
	}
	else if (!power) {
		cout << "Vacuum is currently OFF. It is connected for cleaning the following rooms:\n";
	}
	for (string room : rooms) {
		cout << room << "\n";
	}
}