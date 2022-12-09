#pragma once
#ifndef THERMOSTAT_H_
#define THERMOSTAT_H_
#include "Device.h"


class Thermostat: public Device
{
public:
	Thermostat();
	~Thermostat();
	double currentTemp;
//	bool power;
//	virtual void setPowerStatus(bool tOrF); //press powerbutton, if on turn off, else it's off and turn on
//	virtual void doAction(); //make a sound when the device is running
	virtual double getCurrentTemp();
	virtual void setCurrentTemp(double newTemp);
	virtual void changeTheTemp();

private:

};



#endif // !THERMOSTAT_H_
