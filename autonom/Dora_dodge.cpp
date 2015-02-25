#include "Dora.h"

void Dora::dodge()
{
	unsigned long start = millis();
	while (millis()-start < 2000){
		Direction dir = lastSeen;
		if (sensorValues[1] < 100) //Same side as reset button
		{
			dir = RIGHT;
		} 
		else if (sensorValues[4] < 100)
		{
			dir = LEFT;
		}

		motion.turnWithSpeed(dir, -0.7, 400, 2000);
	}
}