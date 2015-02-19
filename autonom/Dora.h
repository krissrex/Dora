#ifndef DORA_H
#define DORA_H
#include "Arduino.h"
#include "Motion.h"
#include "Ultrasound.h"
#include "State.h"


class Dora
{
private:
Motion motion;
unsigned long motionJobRemaining;
Ultrasound usSensor1,usSensor2;
void clean();
STATE state;

public:
Dora();

void init();
void loop();


};

#endif
