#include "Ultrasound.h"

Ultrasound::Ultrasound(uint8_t echo, uint8_t trigger) : sonar(trigger, echo, 150)
{
	this->echo=echo;
	this->trigger=trigger;
	lastDistance = 0;
}

/*void Ultrasound::setup(uint8_t echo, uint8_t trigger)
{
	this->echo=echo;
	this->trigger=trigger;
	sonar=new NewPing(trigger, echo,150);
}*/

unsigned int Ultrasound::getDistance()
{
	unsigned dist = sonar.ping();
	lastDistance = (dist<20||dist>3000)?0:dist; // Lagrer den så den kan henstes senere også, for sammenligning elns.
	return lastDistance;
}
