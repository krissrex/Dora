#ifndef ULTRASOUND_H
#define ULTRASOUND_H

#include <NewPing.h> //må importere biblioteket newping
#include <Arduino.h>

class Ultrasound
{
private:
int echo,trigger;
NewPing sonar;

public:
Ultrasound();
void setup(int echo, int trigger);
unsigned int getDistance();

};

#endif

