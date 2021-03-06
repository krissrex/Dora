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
    Direction lastSeen;

    int nullCountLeft; //Teller 0 i found
    int nullCountRight;
    unsigned int prevLeft;
    unsigned int prevRight;

	unsigned int sensorValues[6];
	unsigned long motionJobRemaining;

	unsigned long lastUpdated; //For found

	void autoCalibration();
	void manualCalibration();

	boolean lineDetected();
	void setLastSeen(int left, int right);
    float setSail(int a, int b);

    void debug();

public:
	Dora();

	void init();
	void loop();

	void start();
	void search();
	void calibrate();
	void found();
	void dodge();
};

#endif
