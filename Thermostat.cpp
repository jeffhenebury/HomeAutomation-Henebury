#include "Thermostat.h"


Thermostat::Thermostat() //constructor
{
	deviceSound = "Clang! Clang! (Radiators are clanging!)"; //will be overloaded for each device
	power = false; //start with power turned off
	currentTemp = 68;
}

Thermostat::~Thermostat()
{
}

//void Thermostat::setPowerStatus(bool tOrF)
//{
//	power = tOrF;
//}


//void Thermostat::doAction()
//{
//	std::cout << deviceSound;	//mimic the action via printing a sound
//}

double Thermostat::getCurrentTemp()
{
	return currentTemp;
}

void Thermostat::setCurrentTemp(double newTemp)
{
	if (newTemp < 0) {
		cout << "Brrr! Too cold! Please try again.\n";
		return;
	}
	if (newTemp > 90) {
		cout << "Yikes! Too hot! Please try again.\n";
		return;
	}
	currentTemp = newTemp;
}

void Thermostat::changeTheTemp()
{
	int newTemp;
	int oldTemp = getCurrentTemp();
	std::cout << "TEST, you got to CHANGE THE TEMPERATURE.\n";
	std::cout << "The current temperature is set to: " << oldTemp << " degrees.\n";
	std::cout << "What would you like to change it to?";
	std::cin >> newTemp;
	setCurrentTemp(newTemp);
	if (oldTemp < newTemp) {
		std::cout << "Great, you've turned the temperature up to: " << getCurrentTemp() << " degrees.\n";
	}
	else if (oldTemp > newTemp) {
		std::cout << "Great, you've turned the temperature down to: " << getCurrentTemp() << " degrees.\n";
	}
}
