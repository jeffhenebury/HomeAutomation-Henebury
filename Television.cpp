#include "Television.h"

Television::Television()
{
	currentChannel = 1;
	//power = false;	//what's going on with power? it works for base class, not interior, until i redeclare
	deviceSound = "\nWelcome to the FIFA World Cup channel! IT's a GOOOOOOOOAAALLLL!!\n";
}

Television::~Television()
{
}

double Television::getCurrentChannel()
{
	return currentChannel;
}

void Television::setCurrentChannel(int newChannel)
{
	currentChannel = newChannel;
	//std::cout << "\nThe channel is now set to " << newChannel << ". I hope something good is on!\n";
}
