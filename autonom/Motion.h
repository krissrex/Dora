#ifndef MOTION_H
#define MOTION_H
#include "Arduino.h"
#include "State.h"
#include <ZumoMotors.h>

enum Direction {RIGHT, LEFT};

class Motion: public ZumoMotors
{
private:
void newJob(int durationInMillis);
unsigned long remainingTime();

unsigned long jobDurationInMillis, jobStartTimeInMillis;

public:
Motion();

void turnLeft180();
void turnRight180();
void turnLeft90();
void turnRight90();
void abortOperation();
void turnWithSpeed(Direction d, float factor, int speed, unsigned long time);
unsigned long update();



};

#endif
