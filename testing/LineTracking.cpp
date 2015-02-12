#include <Arduino.h>
#include "LineTracking.h"
#include <ZumoMotors.h>
#include <ZumoReflectanceSensorArray.h>
#include <QTRSensors.h>

LineTracking::LineTracking(){}

void LineTracking::init(ZumoMotors motors){
	sensorArray = ZumoReflectanceSensorArray();
	sensorArray.init();
	this->motors = motors;
	lastError = 0;
}

void LineTracking::update(){
	int pv = sensorArray.readLine(sensors);
	int error = pv - 2500;
	int speedDiff = 0.7*error + 6*(error - lastError); // prøv 0.16*error
	lastError = error;

	int m1Speed = 400 + speedDiff;
	int m2Speed = 400 - speedDiff;

	// Here we constrain our motor speeds to be between 0 and MAX_SPEED.
	// Generally speaking, one motor will always be turning at MAX_SPEED
	// and the other will be at MAX_SPEED-|speedDifference| if that is positive,
	// else it will be stationary.  For some applications, you might want to
	// allow the motor speed to go negative so that it can spin in reverse.
	if (m1Speed < -50){
		m1Speed = -50;
	}
	if (m2Speed < -50){
		m2Speed = -50;
	}
	if (m1Speed > 400){
		m1Speed = 400;
	}
	if (m2Speed > 400){
		m2Speed = 400;
	}

	motors.setSpeeds(m1Speed, m2Speed);
}

void LineTracking::calibrate(){
  delay(1000);
  int i;
  for(i = 0; i < 80; i++)
  {
    if ((i > 10 && i <= 30) || (i > 50 && i <= 70))
      motors.setSpeeds(-200, 200);
    else
      motors.setSpeeds(200, -200);
      
    sensorArray.calibrate();

    // Since our counter runs to 80, the total delay will be
    // 80*20 = 1600 ms.
    delay(20);
  }
  motors.setSpeeds(0,0);
}