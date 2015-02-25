#include "Dora.h"

void Dora::calibrate(){
	motion.setSpeeds(0,0);

	manualCalibration(); //Her må vi selv dra roboten over de mørkeste og lyseste områdene.
	//Pass på at alle sensorene blir utsatt for mørkest og lysest verdi på bordet.

	//autoCalibration(); //Alternativ til manuel. Her vil roboten snurre rundt på egen hånd.
	//Det kan hende at auto ikke kommer over alle områdene med sensoren sin.

	zumoButton.waitForButton();
	state = FOUND;//SEARCH;
}


void Dora::manualCalibration(){
	unsigned long startTime = millis();
	//Kalibrer i 5 sekund.
	while(millis()-startTime < 5000){
		sensorArray.calibrate();
	}
	//Varsle at kalibreringen er over.
	motion.setSpeeds(100, 100);
	delay(50);
	motion.setSpeeds(0,0);
}

// Denne koden er nok fra et plab eksempel eller noe. Kopierte den over fra testprosjektet mitt. -Kristian
void Dora::autoCalibration(){
  delay(1000);
  int i;
  for(i = 0; i < 80; i++)
  {
    if ((i > 10 && i <= 30) || (i > 50 && i <= 70))
      motion.setSpeeds(-200, 200);
    else
      motion.setSpeeds(200, -200);
      
    sensorArray.calibrate();

    // Since our counter runs to 80, the total delay will be
    // 80*20 = 1600 ms.
    delay(20);
  }
  motion.setSpeeds(0,0);
}