#include <Arduino.h>

int trigPin = D1;
int echoPin = D0;
int led =D2;

long duration;
int distance;

// put function declarations here:
void setup() {
  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT);  // put your setup code here, to run once:
  pinMode(echoPin, INPUT); // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = 0.034 * duration / 2;
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.print(" cm");
  if(distance <= 10){
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  delay(1000);
}
