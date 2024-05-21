#include <Servo.h>

Servo servo0;
int dir = 1;
int target = 0;

const unsigned int SERVO_PIN = 9;

void setup() {
  servo0.attach(SERVO_PIN);
  Serial.begin(9600);
}

void loop() {
  Serial.println(target);
  servo0.write(target);
  target+=dir;
  if ((target == 0) || (target == 180)) dir=-dir;

  delay(100);

}