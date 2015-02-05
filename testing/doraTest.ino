
#include "PLab_ZumoMotors.h"
#include "Pushbutton.h"
#include "QTRSensors.h"
#include "ZumoBuzzer.h"
#include "ZumoMotors.h"
#include "ZumoReflectanceSensorArray.h"


#define MAX_SPEED 400
#define SPEED 200


Pushbutton zumo_button(ZUMO_BUTTON);
ZumoMotors motors;


void setup(){
	zumo_button.waitForButton();
	motors.setSpeeds(-SPEED, SPEED);
}

void loop(){
	
}