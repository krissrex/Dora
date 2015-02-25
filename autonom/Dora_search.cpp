#include "Dora.h"


void Dora::search(){
	motion.abortOperation(); //Stop fart
	//begin:
	while (true){
		unsigned int left = usSensor1.getDistance(); //bruker _ fordi dist1 ser ut som distl
		unsigned int right = usSensor2.getDistance();
		sensorArray.readCalibrated(sensorValues); //int sensorValues[6]
		setLastSeen(left, right);

		// sensor 0 og 5 funker ikke!
		if (lineDetected()){
			state = DODGE;
			return;
		}
		if (left > 0 || right > 0){
			//Funnet
			state = FOUND;
			motion.setSpeeds(400, 400);
			return;
		}
		
		motion.turnWithSpeed(lastSeen, -1, 400, 999999); //(Direction d, float factor, int speed, unsigned long time)
		motion.update();
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