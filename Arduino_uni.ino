#include <Servo.h>

Servo servo1;
Servo servo2;
const int servomin=500;
const int servomax=2400;

void setup() {
  Serial.begin(9600);
  servo1.attach(9,servomin,servomax);
  servo2.attach(10,servomin,servomax);
  pinMode(LED_BUILTIN, OUTPUT);
}

#define errormessage(message) {Serial.println(message); return;}

void loop() {
  if (not Serial.available()) return;

  String msg = Serial.readStringUntil('\n');
  int lpos = msg.indexOf(";");
  if (-1 == lpos) errormessage("No separator in " + msg);
  if (msg.lastIndexOf(";") > lpos) errormessage("More than one separator in "+msg)
  
  String jointselectstr = msg.substring(lpos+1);
  int jointselect;
  if (jointselectstr == "1") jointselect=1;
  else if (jointselectstr == "2") jointselect=2;
  else errormessage("Invalid joint selected in " + msg)

  msg.remove(lpos);
  int angle=msg.toInt();
  if ((msg != "0") and (0 == angle)) errormessage("A number needed as joint angle instead of " + msg) 
  if ((0 > angle) or (170 < angle)) errormessage(msg + "is outside of 0-170 ")

  Serial.print("Roger: J");
  Serial.print(jointselect);
  Serial.print(" to: ");
  Serial.println(angle);  

  if (jointselect == 1) servo1.write(angle);
  else servo2.write(angle);
}