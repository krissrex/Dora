
#include "Motion.h"
#include "Dora.h"
#include "Ultrasound.h"

#include "Pushbutton.h"
#include <NewPing.h>
#include "QTRSensors.h"
#include "ZumoReflectanceSensorArray.h"
//Det viser seg at man må inkludere dette her for at Motion-klassen skal kunne arve den
#include <ZumoMotors.h>

//#include ALL the libraries! =D


Dora doraTheExplorer;

void setup(){
	Serial.begin(9600); //TODO fjern serial for å få pinne 0 og 1 ledig.
	doraTheExplorer.init();
}

void loop(){
	doraTheExplorer.loop();
}
