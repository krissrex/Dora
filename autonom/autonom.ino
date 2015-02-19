
#include "Motion.h"
#include "Dora.h"
#include "Ultrasound.h"

#include <NewPing.h>

#include <ZumoMotors.h> //Det viser seg at man må inkludere dette her for at Motion-klassen skal kunne arve den


//Nice project
Dora doraTheExplorer;

void setup(){
Serial.begin(9600);
doraTheExplorer.init();
}

void loop(){

doraTheExplorer.loop();
	
}
