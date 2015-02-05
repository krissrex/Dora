
#include "PLab_ZumoMotors.h"
#include "Pushbutton.h"
#include "QTRSensors.h"
#include "ZumoBuzzer.h"
#include "ZumoMotors.h"
#include "ZumoReflectanceSensorArray.h"
#include "test.h"



#define MAX_SPEED 400
#define SPEED 400


Pushbutton zumo_button(ZUMO_BUTTON);
ZumoMotors motors;
Test test(10);


void setup(){
	Serial.begin(9600);
	//zumo_button.waitForButton();
	//long time = millis();
	test.doTest();
	
}

void loop(){
	
}