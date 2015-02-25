#include "Dora.h"

#define TIMEOUT 10000
#define TURNSPEED 400 
#define MOVEMENT_DELAY 20

void Dora::found()
{
  //motion.update();

  unsigned int left = usSensor1.getDistance();
  unsigned int right = usSensor2.getDistance();

  if (left == 0 && prevLeft != 0){
    nullCountLeft++;
    if (nullCountLeft < 10){
      left = prevLeft;
    }
    else
    {
      nullCountLeft = 0;
      nullCountRight = 0; // ??
      prevLeft = 0;
    }
  } 
  else
  {
    prevLeft = left;
  }


  if (right == 0 && prevRight != 0){
    nullCountRight++;
    if (nullCountRight < 10)
    {
      right = prevRight;
    } 
    else
    {
     nullCountRight = 0;
     nullCountLeft = 0; //??
     prevRight = 0;
    }
  } else {
    prevRight = right;
  }

  setLastSeen(left, right);

  sensorArray.readCalibrated(sensorValues); //int sensorValues[6]
  if (lineDetected())
  {
    state = DODGE;
    return;
  }

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
  if (b-a < 200){
    return 1;
  }

  return (float)pow(a/b, 3);
}
