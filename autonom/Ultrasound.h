#ifndef ULTRASOUND_H
#define ULTRASOUND_H

#include <NewPing.h> //må importere biblioteket newping
#include <Arduino.h>

class Ultrasound
{
private:
	uint8_t echo, trigger;
	NewPing sonar; // Arduino krever at den allokeres dynamisk, fordi default constructor kjøres

public:
	Ultrasound(uint8_t echo, uint8_t trigger);
	unsigned int getDistance();
	unsigned int lastDistance;
};

#endif

