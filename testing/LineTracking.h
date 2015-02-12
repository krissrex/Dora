#ifndef LineTracking_h
#define LineTracking_h

#include <Arduino.h>
#include <ZumoMotors.h>
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>

class LineTracking
{
public:
	LineTracking();
	void init(ZumoMotors motors);
	void calibrate();
	void update();

private:
	ZumoReflectanceSensorArray sensorArray;
	ZumoMotors motors;
	unsigned int sensors[6];
	int lastError;
};

#endif
