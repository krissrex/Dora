#ifndef DORA_H
#define DORA_H
#include "Arduino.h"
#include "Motion.h"

class Dora
{
private:
Motion motion;
unsigned long motionJobRemaining;

public:
Dora();

void init();
void loop();


};

#endif