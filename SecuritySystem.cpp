#include "SecuritySystem.h"

SecuritySystem::SecuritySystem()
{
    currentSensitivity = 5;
}

SecuritySystem::~SecuritySystem()
{
}

//void SecuritySystem::getSchedule()
//{
//    //NEED TO FIND A WAY TO GET THE SCHEDULE
//}
//
//void SecuritySystem::setSchedule(std::string dayOfWeek)
//{
//    //NEED TO FIND A WAY TO SET THE SCHEDULE
//
//}

void SecuritySystem::doAction()
{
    std::cout << "*****************WEEE-OOO! WEE-OO! Alert, Alert!*****************\n";
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
        currentSensitivity = newLightSensitivity;
    }
}
