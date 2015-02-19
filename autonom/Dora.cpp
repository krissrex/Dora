#include "Dora.h"

Dora::Dora(){}

void Dora::init()
{
state=START;
motionJobRemaining=0;
motion= Motion();
//motion.turnWithSpeed(RIGHT,0.7,400,10000);
usSensor1.setup(3,4);
usSensor2.setup(5,6);


}
void Dora::loop()
{
  for(;;) //Infite for loop master race 
  {
    switch (state)
      {
        case START:
          start();
          break;
        case CALIBRATE:
          calibrate();
          break;
        case SEARCH:
          search();
          break;
        case FOUND:
          found();
          break;
        case DODGE:
          dodge();
          break;
        case DODGE:
          dodge();
          break;
        default:
        break;
      }

      //Debug
      Serial.print(usSensor1.getDistance());
      Serial.print("     ");
      Serial.println(usSensor2.getDistance());

      motionJobRemaining=motion.update(); //No idea. spør mathias
    }
}

void Dora::clean()
{
  usSensor1.clean();
}
