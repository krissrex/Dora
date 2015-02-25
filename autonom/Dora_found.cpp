#include "Dora.h"

#define TIMEOUT 10000
#define TURNSPEED 400 
void Dora::found()
{
  motion.update();

  usSensor1.getDistance();
  usSensor2.getDistance();
  Direction d;

  if(usSensor1.getLastDistance()==0||(usSensor1.getLastDistance()>usSensor2.getLastDistance()))
  {
    d=RIGHT;
  }
  else 
  {
    d=LEFT;
  }

  lastSeen=d;

  if(usSensor1.getLastDistance()==0||usSensor2.getLastDistance()==0))
  {
    motion.turnWithSpeed(d,0.4, TURNSPEED,TIMEOUT);
    return;
  }

  if(d==RIGHT)
  {
    motion.turnWithSpeed(d,usSensor2.getLastDistance()/usSensor1.getLastDistance(), TURNSPEED,TIMEOUT);  
  }
  else
  {
    motion.turnWithSpeed(d,usSensor1.getLastDistance()/usSensor2.getLastDistance(), TURNSPEED,TIMEOUT);
  }

}
