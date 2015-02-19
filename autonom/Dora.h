#ifndef DORA_H
#define DORA_H
#include "Arduino.h"
#include "Motion.h"
#include "Ultrasound.h"
class Dora
{
private:
Motion motion;
unsigned long motionJobRemaining;
Ultrasound usSensor1;

public:
Dora();

void init();
void loop();


};

#endif
