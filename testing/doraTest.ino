#include <PLab_ZumoMotors.h>
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoBuzzer.h>
#include <ZumoMotors.h>
#include <ZumoReflectanceSensorArray.h>
#include "test.h"
#include "LineTracking.h"



#define MAX_SPEED 400
#define SPEED 400


Pushbutton zumo_button(ZUMO_BUTTON);
ZumoMotors motors;
ZumoReflectanceSensorArray array;
LineTracking lineTracking;
Test test;


void setup(){
	Serial.begin(9600);
	lineTracking.init(motors);
	array.init();

	zumo_button.waitForButton();
	lineTracking.calibrate();
	zumo_button.waitForButton();

	//zumo_button.waitForButton();
	//long time = millis();
	//test.doTest();
	
}

void loop(){
	lineTracking.update();
}