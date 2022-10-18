#include <Servo.h>

Servo myservo; // create servo object to control a servo
Servo myservo2; // create servo object to control a servo
Servo myservo3; // create servo object to control a servo
Servo myservo4; // create servo object to control a servo
Servo myservo5; // create servo object to control a servo

const int flexPin = A0; //pin A0 to read analog input
const int flexPin2 = A1; //pin A1 to read analog input
const int flexPin3 = A2; //pin A2 to read analog input
const int flexPin4 = A3; //pin A3 to read analog input
const int flexPin5 = A4; //pin A4 to read analog input

int val1; // variable to read the value from the analog pin A0
int val1B; //scaled variable for use with the servo 1
int val2; // variable to read the value from the analog pin A1
int val2B; //scaled variable for use with the servo 2
int val3; // variable to read the value from the analog pin A2
int val3B; //scaled variable for use with the servo 3
int val4; // variable to read the value from the analog pin A3
int val4B; //scaled variable for use with the servo 4
int val5; // variable to read the value from the analog pin A4
int val5B; //scaled variable for use with the servo 5

void setup() {
  myservo.attach(8); // attaches the servo on pin 8 to the servo object
  myservo2.attach(9); // attaches the servo on pin 9 to the servo object
  myservo3.attach(10); // attaches the servo on pin 10 to the servo object
  myservo4.attach(11); // attaches the servo on pin 11 to the servo object
  myservo5.attach(12); // attaches the servo on pin 12 to the servo object
  Serial.begin(9600); //Begin serial communication
}

void loop() {
  val1 = analogRead(flexPin);
  val1B = map(val1, 0, 1023, 0, 175); //scale it for use with the servo (value between 0 and 175) -> Calibration of the first 2 values may be needed depending on the design your data glove
  val2 = analogRead(flexPin2);
  val2B = map(val2, 0, 1023, 0, 175); //scale it for use with the servo (value between 0 and 175) -> Calibration of the first 2 values may be needed depending on the design your data glove
  val3 = analogRead(flexPin3);
  val3B = map(val3, 0, 1023, 0, 175); //scale it for use with the servo (value between 0 and 175) -> Calibration of the first 2 values may be needed depending on the design your data glove
  val4 = analogRead(flexPin4);
  val4B = map(val4, 0, 1023, 0, 175); //scale it for use with the servo (value between 0 and 175) -> Calibration of the first 2 values may be needed depending on the design your data glove
  val5 = analogRead(flexPin5);
  val5B = map(val5, 0, 1023, 0, 175); //scale it for use with the servo (value between 0 and 175) -> Calibration of the first 2 values may be needed depending on the design your data glove

  String p1=";";
  Serial.println(val1 + p1 + val2 + p1 + valB + p1 + val4 + p1 + val5); // Print values of the variables from the analog inputs
  //Serial.println(val1B + p1 + val2B + p1 + val3B + p1 + val4B + p1 + val5B); // Print values of the variables from servo motors angles
  
  myservo.write(val1B); // sets the servo position according to the scaled value
  myservo2.write(val2B); // sets the servo position according to the scaled value
  myservo3.write(val3B); // sets the servo position according to the scaled value
  myservo4.write(val4B); // sets the servo position according to the scaled value
  myservo5.write(val5B); // sets the servo position according to the scaled value
  delay(15); // waits for the servo to get there
}
