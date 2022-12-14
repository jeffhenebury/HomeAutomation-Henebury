//header file for security system class
#pragma once
#ifndef SECURITYSYSTEM_H_
#define SECURITYSYSTEM_H_
#include "Device.h"

class SecuritySystem : public Device {
public:
	SecuritySystem();
	~SecuritySystem();
	int currentSensitivity;
	virtual double getLightSensitivity();
	virtual void setLightSensitivity(int lightSensitivity);
};

#endif // SECURITYSYSTEM_H_