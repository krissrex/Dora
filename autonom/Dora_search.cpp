#include "Dora.h"


void Dora::search(){
	motion.setSpeeds(0,0); //Stop fart
	//begin:
	while (true){
		unsigned int left = usSensor1.getDistance(); //bruker _ fordi dist1 ser ut som distl
		unsigned int right = usSensor2.getDistance();
		sensorArray.readCalibrated(sensorValues); //int sensorValues[6]
		// sensor 0 og 5 funker ikke!
		if (lineDetected()){
			state = DODGE;
			return;
		}
		if (left > 0 || right > 0){
			//Funnet
			state = FOUND;
		}
		//debug(sensorValues);
	}
}

void debug(int* sensorValues){
		Serial.print("Sensor array: ");
		for (int i=0; i<5; i++){
			Serial.print(sensorValues[i]);
			Serial.print(", ");
		}
		Serial.print(sensorValues[5]);
		Serial.print("\n");
}