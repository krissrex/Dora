#include "Dora.h"

#define TIMEOUT 10000
#define TURNSPEED 400 
void Dora::found()
{
  motion.update();

  unsigned int prevLeft = usSensor1.getLastDistance();
  unsigned int prefRight = usSensor2.getLastDistance();

  unsigned int left = usSensor1.getDistance();
  unsigned int right = usSensor2.getDistance();

  Direction d;

  if (left==0 && right== 0) {
    //set state søk;
    //return;
  }


  if(left==0 || (left>right))
  {
    d=RIGHT;
  }
  else 
  {
    d=LEFT;
  }

  lastSeen=d;

  if(left==0 || right==0)
  {
    motion.turnWithSpeed(d, 0.9, TURNSPEED, TIMEOUT); //Høy avstand = høy faktor!
    return;
  }

  

  if(d==RIGHT)
  {
    motion.turnWithSpeed(d, (float)pow(right/left, 4), TURNSPEED,TIMEOUT);  
  }
  else
  {
    motion.turnWithSpeed(d,(float)pow(left/right, 4), TURNSPEED,TIMEOUT);
  }

}
