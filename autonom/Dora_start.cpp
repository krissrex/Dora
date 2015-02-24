#include "Dora.h"

void Dora::start()
{
	motion.setSpeeds(0, 0); // Stop robot.
	zumoButton.waitForButton();
	state = CALIBRATE;
}

