#pragma once
#ifndef TELEVISION_H_
#define TELEVISION_H_
#include "Device.h"

class Television: public Device {
public:
	Television();
	~Television();
	int currentChannel;
	//bool power;	//overload this, i guess?
	virtual double getCurrentChannel();
	virtual void setCurrentChannel(int newChannel);

};

#endif // !TELEV:ISION_H_