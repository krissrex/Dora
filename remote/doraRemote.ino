#include <PLabBTSerial.h>
#include <PLab_ZumoMotors.h>
#include <ZumoMotors.h>
#include <SoftwareSerial.h>

// Define I/O ports used for transmit (TX) and receive (RX)
const int BT_RX = 2;//RX cable however goes to 6
const int BT_TX = 6;//TX cable however goes to 2

PLabBTSerial btSerial (BT_RX, BT_TX);
PLab_ZumoMotors PLab_motors;

void setup(){ 
  PLab_motors.setSpeeds(0, 0);
  Serial.begin (9600);
  btSerial.begin (9600);
}

void loop()
{
  int availableCount = btSerial.available();
  if (availableCount > 0) {
    char text[availableCount];
    btSerial.read (text, availableCount);
    readCommand(text);
  }
  if (Serial.available () > 0) {
    btSerial.write (Serial.read ());
  }
}

void readCommand (char *text) {
  String newString =  String(text);
  int pos = newString.indexOf(':');
  int leftSpeed = newString.substring(0,pos).toInt();
  int rightSpeed = newString.substring(pos + 1).toInt();
  PLab_motors.setSpeeds(leftSpeed, rightSpeed);
  //Serial.println(leftSpeed);
  //Serial.println(rightSpeed);
}
