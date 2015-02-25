#include "Dora.h"

void Dora::search(){
<<<<<<< HEAD
  
  
  

=======
	motion.setSpeeds(0,0); //set fart 0
	//begin:
	unsigned int dist_1 = usSensor1.getDistance(); //bruker _ fordi dist1 ser ut som distl
	unsigned int dist_2 = usSensor2.getDistance();
	sensorArray.readCalibrated(sensorValues); //int sensorValues[6]

	//Debug
	Serial.print("Sensor array: ");
	for (int i=0; i<5; i++){
		Serial.print(sensorValues[i]);
		Serial.print(", ");
	}
	Serial.print(sensorValues[5]);
	Serial.print("\n");
>>>>>>> master
}
