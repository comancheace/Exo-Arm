#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
Servo myservo3;  // create servo object to control a servo
Servo myservo4;  // create servo object to control a servo
Servo myservo5;  // create servo object to control a servo

const int flexPin = A0; //pin A0 to read analog input
const int flexPin2 = A1; //pin A0 to read analog input
const int flexPin3 = A2; //pin A0 to read analog input
const int flexPin4 = A3; //pin A0 to read analog input
const int flexPin5 = A4; //pin A0 to read analog input

int val1;    // variable to read the value from the analog pin
int val1B;
int val2;    // variable to read the value from the analog pin
int val2B;
int val3;    // variable to read the value from the analog pin
int val3B;
int val4;    // variable to read the value from the analog pin
int val4B;
int val5;    // variable to read the value from the analog pin
int val5B;

void setup() {
  myservo.attach(8); // attaches the servo on pin 8 to the servo object
  myservo2.attach(9); // attaches the servo on pin 8 to the servo object
  myservo3.attach(10); // attaches the servo on pin 8 to the servo object
  myservo4.attach(11); // attaches the servo on pin 8 to the servo object
  myservo5.attach(12); // attaches the servo on pin 8 to the servo object
  Serial.begin(9600); //Begin serial communication
}

void loop() {
  val1 = analogRead(flexPin);
  val1B = map(val1, 0, 1023, 0, 180); //scale it for use with the servo (value between 0 and 180)
  val2 = analogRead(flexPin2);
  val2B = map(val2, 0, 1023, 0, 180); //scale it for use with the servo (value between 0 and 180)
  val3 = analogRead(flexPin3);
  val3B = map(val3, 0, 1023, 0, 180); //scale it for use with the servo (value between 0 and 180)
  val4 = analogRead(flexPin4);
  val4B = map(val4, 0, 1023, 0, 180); //scale it for use with the servo (value between 0 and 180)
  val5 = analogRead(flexPin5);
  val5B = map(val5, 0, 1023, 0, 180); //scale it for use with the servo (value between 0 and 180)
  
  Serial.println(val1); //Print value
  Serial.println(val2); //Print value
  Serial.println(val3); //Print value
  Serial.println(val4); //Print value
  Serial.println(val5); //Print value
  
  myservo.write(val1B); // sets the servo position according to the scaled value
  myservo2.write(val2B); // sets the servo position according to the scaled value
  myservo3.write(val3B); // sets the servo position according to the scaled value
  myservo4.write(val4B); // sets the servo position according to the scaled value
  myservo5.write(val5B); // sets the servo position according to the scaled value
  delay(15); // waits for the servo to get there
}
