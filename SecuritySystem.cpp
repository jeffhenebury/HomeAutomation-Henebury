#include "SecuritySystem.h"

SecuritySystem::SecuritySystem()
{
    currentSensitivity = 5;
    deviceSound = "*****************WEEE-OOO! WEE-OO! Alert, Alert!*****************\n";
}

SecuritySystem::~SecuritySystem()
{
}

double SecuritySystem::getLightSensitivity()
{
    return currentSensitivity;
}

void SecuritySystem::setLightSensitivity(int newLightSensitivity)
{
    if ((newLightSensitivity < 1) || (newLightSensitivity > 5)) {
        std:: cout << "I'm sorry, sensitivity level must be between 1-5. Please try again.\n";
    }
    else {
        if (currentSensitivity > newLightSensitivity) { //if turning it down...
            currentSensitivity = newLightSensitivity;
            std::cout << "Security sensitivity level has been successfully decreased to level: " << currentSensitivity << ".\n";
        }
        else {
            currentSensitivity = newLightSensitivity;
            std::cout << "Security sensitivity level has been successfully increased to level: " << currentSensitivity << ".\n";
        }   
    }
}
