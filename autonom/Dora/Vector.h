#ifndef VECTOR_H
#define VECTOR_H

class Vector{
public:
float x,y;
Vector();

Vector operator+(Vector other);
Vector toVector(float sensorLeft, float sensorRight);

};

#endif
