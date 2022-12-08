#include "Television.h"

Television::Television()
{
	power = false;
	currentChannel = 1;
}

Television::~Television()
{
}
//we don't need these b/c of inheritance!
//void Television::getPowerStatus()
//{
//}
//
//void Television::setPowerStatus(bool tOrF)
//{
//}

void Television::getSchedule()
{
}

void Television::setSchedule(std::string dayOfWeek)
{
}

void Television::doAction()
{
	std::cout << "Welcome to the FIFA World Cup channel! IT's a GOOOOOOOOAAALLLL!!\n";
}

double Television::getCurrentChannel()
{
	return currentChannel;
}

void Television::setCurrentChannel(int newChannel)
{
	currentChannel = newChannel;
	std::cout << "\nThe channel is now set to " << newChannel << ". I hope something good is on!\n";
}
