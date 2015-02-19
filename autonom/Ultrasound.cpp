#include "Ultrasound.h"

Ultrasound::Ultrasound()
{}

void Ultrasound::setup(uint8_t echo, uint8_t trigger)
{

this->echo=echo;
this->trigger=trigger;
sonar= NewPing(trigger, echo,200);

}

unsigned int Ultrasound::getDistance()
{
return this->sonar.ping();
}



