#include "Dora.h"

Dora::Dora(){}

void Dora::init()
{
motionJobRemaining=0;
motion= Motion();
motion.turnWithSpeed(RIGHT,0.5,350,10);
//usSensor1 = Ultrasound();
usSensor1.setup(2,3);
}
void Dora::loop()
{for(;;){



motionJobRemaining=motion.update();
}}
