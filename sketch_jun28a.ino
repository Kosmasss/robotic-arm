#include <Servo.h>

Servo myServo;
Servo myServo1;
Servo myServo2;
const int buttonPin = 2
const int xPin = A0;        // the number of the analog pin for X-axis
const int yPin = A1;


void setup() {
  myServo.attach(9);
  myServo1.attach(10);
  myServo2.attach(11);
  int buttonState = 0 ;
  pinMode(buttonPin, INPUT);
  }



void loop() {
  buttonState = digitalRead(buttonPin);

  int xValue = analogRead(xPin);  // read the X-axis value
  int yValue = analogRead(yPin);  // read the Y-axis value
  
  int servoAngleX = map(xValue, 0, 1023, 0, 180);  // map X-axis value to servo angle
  int servoAngleY = map(yValue, 0, 1023, 0, 180);  // map Y-axis value to servo angle


   if (buttonState == HIGH) {
    // If the button is pressed, move the second servo based on the X-axis value:
    myServo2.write(servoAngleX);
  } else {
    // If the button is not pressed, move the first servo based on the X-axis value:
    myServo1.write(servoAngleX);  // move servo based on X-axis value
    delay(5);  // delay for smoother movement
  }
}