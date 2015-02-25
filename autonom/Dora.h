#ifndef DORA_H
#define DORA_H

//System libs:
#include <Arduino.h>
//Egne libs:
#include "Motion.h"
#include "Ultrasound.h"
#include "State.h"
//PLab libs:
#include "Pushbutton.h"
#include "QTRSensors.h"
#include "ZumoReflectanceSensorArray.h"

class Dora
{
private:
	Motion 		motion;
	Pushbutton 	zumoButton;
	Ultrasound 	usSensor1, 	usSensor2;
	STATE 		state;
	ZumoReflectanceSensorArray sensorArray;

	unsigned int sensorValues[6];
	unsigned long motionJobRemaining;

	void autoCalibration();
	void manualCalibration();

	boolean lineDetected();

public:
	Dora();

	void init();
	void loop();

	void start();
	void search();
	void calibrate();
	void found();
	void back();
	void dodge();
};

#endif
