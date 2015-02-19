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

  switch state{}
  
  

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
