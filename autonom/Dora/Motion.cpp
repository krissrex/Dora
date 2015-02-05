#include "Motion.h"

Motion::Motion()
  {
    newJob(0);
  }

void Motion::newJob(int durationInMillis)
  {
    jobDurationInMillis=durationInMillis;
    jobStartTimeInMillis= millis();
  }

//Starttid + hvor lang tid bevegelsen tar - tiden nå = hvor lang tid det er igjen.
unsigned long Motion::remainingTime()
  {
    long time= jobStartTimeInMillis+jobDurationInMillis-millis();
    return time<=0?0:static_cast<unsigned long>(time); 
  }

void Motion::turnRight180()
  {
    setLeftSpeed(300);
    setRightSpeed(-300);
    newJob(430);

  }

void Motion::turnLeft180()
  {
    setLeftSpeed(-300);
    setRightSpeed(300);
    newJob(430);
  }

void Motion::turnRight90()
  {
    setLeftSpeed(300);
    setRightSpeed(-300);
    newJob(215);
  }

void Motion::turnLeft90()
  {
    setLeftSpeed(-300);
    setRightSpeed(300);
    newJob(215);
  }

void Motion::abortOperation()
  {
    setLeftSpeed(0);
    setRightSpeed(0);
    jobDurationInMillis=0;
  }

unsigned long Motion::update()
  {
    unsigned long remaining=remainingTime();
    if(remaining==0)
    {
      abortOperation();
      return 0;
    }
    return remaining;
  }
  
void Motion::turnWithSpeed(Direction d, float factor, int speed, unsigned long time)
  {
    factor=factor>1?1:factor; // For å unngå at den får fortere enn det andre hjulet
    switch(d)
      {
        case RIGHT:
          setLeftSpeed(speed);
          setRightSpeed(speed*factor);
          newJob(time);
          break;
        case LEFT:
          setLeftSpeed(speed*factor);
          setRightSpeed(speed);
          newJob(time);
          break;
      }
    
  }