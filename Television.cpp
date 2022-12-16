//jeff henebury
//implementation of the Television class and methods
#include "Television.h"

Television::Television()
{
	currentChannel = 1;
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
}
