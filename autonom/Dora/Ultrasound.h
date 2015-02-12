#ifndef ULTRASOUND_H
#define ULTRASOUND_H

// #include <NewPing.h> må importere biblioteket newping

class Ultrasound
{
private:
int echo,trigger;
NewPing sonar;

public:

void setup();
unsigned int getDistance();

};

#endif

