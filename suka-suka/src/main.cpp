#include <Arduino.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

// put function declarations here:
int trigPin = D1;
int echoPin = D0; 
int SDA_pin = D5;
int SCL_pin = D6;
int redLED = D7;
int greLED = D8;
long duration;
int distance;
Servo motor;  

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
  pinMode(greLED, OUTPUT);
  pinMode(trigPin, OUTPUT);  // put your setup code here, to run once:
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  motor.attach(D4);
  Wire.begin(SDA_pin, SCL_pin);
  lcd.init();
  lcd.backlight();
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
  Serial.println("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");
  lcd.clear(); 
  lcd.setCursor(0,0);
  lcd.print("Jarak:");    
  lcd.print(distance);
  lcd.print(" cm");
  if(distance <= 10){
    digitalWrite(redLED, LOW);
    digitalWrite(greLED, HIGH); 
    motor.write(180);
  } else {
    digitalWrite(greLED, LOW);
    digitalWrite(redLED, HIGH);
    motor.write(0);
  }
}

// put function definitions here:
