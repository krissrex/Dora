#include "Dora.h"

void Dora::dodge()
{
	unsigned long start = millis();

	while (millis()-start < 300){
		//motion.update();
		unsigned int left = usSensor1.getDistance();
		unsigned int right = usSensor2.getDistance();
		setLastSeen(left, right);

		if (left != 0 || right != 0)
		{
			state = FOUND;
			//motion.setSpeeds(400, 400);
			return;
		}

		Direction dir = lastSeen;
		if (sensorValues[1] < 100) //Same side as reset button
		{
			if (sensorValues[4] < 100){
				motion.setSpeeds(-400, -400);
			} else {
				dir = RIGHT;
				motion.setSpeeds(-400, -150);
			}
			
		} 
		else if (sensorValues[4] < 100)
		{
			dir = LEFT;
			motion.setSpeeds(-150, -400);
		}


		 //turnWithSpeed(dir, -0.7, 400, 2000);
	}

	state = SEARCH;
}