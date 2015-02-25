#include "Dora.h"

#define LINE 100

Dora::Dora() : zumoButton(12), motion(), sensorArray(), usSensor1(3,4), usSensor2(5,6), lastSeen(RIGHT)
{

}

void Dora::init()
{
  state = START;
  motionJobRemaining = 0;
  sensorArray.init();
  
  /*motion = Motion();
  //motion.turnWithSpeed(RIGHT,0.7,400,10000);
  usSensor1.setup(3,4);
  usSensor2.setup(5,6);
   // pin 12, pull up enabled, default high
  sensorArray = ZumoReflectanceSensorArray();*/
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
        default:
        break;
      }

      motion.update(); //Gir ut tiden som er igjen før en motion (svinging) er ferdig
    }
}


boolean Dora::lineDetected(){
  bool funnet = false;
  //sensor 0 og 5 funker ikke!

  for (int i=1; i<5; i++){
    if (sensorValues[i] < LINE)
    {
      funnet = true;
      break;
    }
  }

  return funnet;
}

void Dora::setLastSeen(int left, int right){
  Direction d;

  if (left==0 && right== 0) {
    return;
  }

  if(left==0 || (left>right))
  {
    lastSeen=RIGHT;
  }
  else 
  {
    lastSeen=LEFT;
  }
}