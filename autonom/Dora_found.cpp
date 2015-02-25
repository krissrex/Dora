#include "Dora.h"

#define TIMEOUT 10000
#define TURNSPEED 400 
#define MOVEMENT_DELAY 20

void Dora::found()
{
  //motion.update();

  unsigned int prevLeft = usSensor1.getLastDistance();
  unsigned int prefRight = usSensor2.getLastDistance();

  unsigned int left = usSensor1.getDistance();
  unsigned int right = usSensor2.getDistance();

  sensorArray.readCalibrated(sensorValues); //int sensorValues[6]
  if (lineDetected())
  {
    state = DODGE;
    return;
  }

  setLastSeen(left, right);
  if (left==0 && right == 0)
  {
    state = SEARCH;
    return;
  }

  if (millis()-lastUpdated <= MOVEMENT_DELAY)
  {
    return;
  }

  lastUpdated = millis();

  if(left==0 || right==0)
  {
    motion.turnWithSpeed(lastSeen, 0.9, TURNSPEED, TIMEOUT); //Høy avstand = høy faktor!
    return;
  }



  if(lastSeen==RIGHT)
  {
    motion.turnWithSpeed(lastSeen, setSail(right,left), TURNSPEED,TIMEOUT);  
  }
  else
  {
    motion.turnWithSpeed(lastSeen,setSail(left,right), TURNSPEED,TIMEOUT);
  }

}

float Dora::setSail(int a, int b)
{
 float factor=(float)pow(a/b, 4)
  return factor>0.95?1:factor;
}
