#ifndef ULTRASOUND_H
#define ULTRASOUND_H

#include <NewPing.h> //må importere biblioteket newping
#include <Arduino.h>
#include "State.h"

class Ultrasound
{
private:
uint8_t echo,trigger;
NewPing *sonar; // Arduino krever at den allokeres dynamisk av en eller annen grunn

public:
Ultrasound();
void setup(uint8_t echo, uint8_t trigger);
unsigned int getDistance();
void clean();

};

#endif

