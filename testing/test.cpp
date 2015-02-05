#include "test.h"
#include "Arduino.h"

Test::Test(int a){
	Serial.println("Constructor");
}

void Test::doTest(){
	Serial.println("Test123");
}