#include "Ultrasound.h"

void Ultrasound::setup(int echo, int trigger)
{

this.echo=echo;
this.trigger=trigger;
sonar= NewPing(trigger, echo,200);

}

unsigned int Ultrasound::getDistance()
{
return this.sonar.ping();
}



