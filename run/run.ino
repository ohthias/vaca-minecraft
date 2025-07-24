#include <Servo.h>
Servo servo;

int const trigPin = 9;
int const echoPin = 10;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.attach(6);
}

void loop() {
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(1);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance <= 5 && distance >= 0) {
    servo.write(100);
    delay(3000);
  } else {
    servo.write(20);
  }
  delay(60);
}