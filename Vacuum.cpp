#include "Vacuum.h"

Vacuum::Vacuum()
{
	power = false;
	currentRoom = "Living Room";
	std::vector <std::string> rooms = { "living room", "dining room", "bedroom" };
}

Vacuum::~Vacuum()
{
}

void Vacuum::getSchedule()
{
	//NEED TO FIGURE OUT SCHEDULE
}

void Vacuum::setSchedule(std::string dayOfWeek)
{
	//NEED TO FIGURE OUT SCHEDULE
}

void Vacuum::doAction()
{
	std::cout << "VROOOOOOOM! (Sorry kitten, I know you're scared of the vacuum!\n";
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
