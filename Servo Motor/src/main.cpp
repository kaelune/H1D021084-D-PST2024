#include <Arduino.h>
#include <Servo.h>

Servo motor;

// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  motor.attach(D4);
}

void loop() {
  // put your main code here, to run repeatedly:
  // motor.write(180);
  // delay(1000);
  // motor.write(0);
  // delay(1000);
  for(int pos = 0; pos <= 180; pos += 1) {
    motor.write(pos);
    delay(15);
  }
  for(int pos = 180; pos >= 0; pos -= 1) {
    motor.write(pos);
    delay(15);
  }
}

// put function definitions here:
