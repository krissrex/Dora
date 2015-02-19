#include "Ultrasound.h"

Ultrasound::Ultrasound()
{
  
}

void Ultrasound::setup(uint8_t echo, uint8_t trigger)
{

this->echo=echo;
this->trigger=trigger;
sonar=new NewPing(trigger, echo,200);

}

unsigned int Ultrasound::getDistance()
{
unsigned dist = sonar->ping();
return (dist<20||dist>3000)?0:dist;
}


void Ultrasound::clean()
{
delete sonar;
}
