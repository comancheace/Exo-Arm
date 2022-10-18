#include <Servo.h> // Arduino Servo Motor Library

Servo myservo; // create servo object to control a servo
Servo myservo_2; // create servo object to control a servo

int potpin = A0; // analog pin used to connect the potentiometer
int potpin_2 = A1; // analog pin used to connect the potentiometer 2
int val; // variable to read the value from the analog pin
int val_2; // variable to read the value from the analog pin 2

void setup() {
  myservo.attach(8); // attaches the servo on pin 8 to the servo object
  myservo_2.attach(9); // attaches the servo on pin 9 to the servo object
}

void loop() {
  val = analogRead(potpin); // reads the value of the potentiometer (value between 0 and 1023)
  val_2 = analogRead(potpin_2); // reads the value of the potentiometer 2 (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180); // scale it for use with the servo (value between 0 and 180)
  val_2 = map(val_2, 0, 1023, 0, 180); // scale it for use with the servo (value between 0 and 180)
  myservo.write(val); // sets the servo position according to the scaled value
  myservo_2.write(val_2); // sets the servo position according to the scaled value
  delay(150); // waits for the servo to get there
}
