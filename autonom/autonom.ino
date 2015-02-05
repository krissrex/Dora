#include <ZumoMotors.h> //Det viser seg at man må inkludere dette her for at Motion-klassen skal kunne arve den


#include <Dora.h>


//Nice project
Dora doraTheExplorer;

void setup(){
doraTheExplorer.init();
}

void loop(){

doraTheExplorer.loop();
	
}
