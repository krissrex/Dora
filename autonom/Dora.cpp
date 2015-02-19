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
{for(;;){

  unsigned int usSensor1Ping=0;
switch (state)
  {
    case SEARCH:
      usSensor1Ping = usSensor1.getDistance();
      //unsigned int usSensor2Ping = usSensor2.getDistance();
      
      break;
    case FOUND:
      break;
    case DODGE:
      break;
    
  };
  
  

Serial.print(usSensor1.getDistance());
Serial.print("     ");
Serial.println(usSensor2.getDistance());
motionJobRemaining=motion.update();
}

}
void Dora::clean()
{
  usSensor1.clean();
}
