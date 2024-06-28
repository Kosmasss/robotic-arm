#include <Servo.h>

Servo myServo;  // create servo object to control a servo

int xPin = A0;  // analog input pin for X-axis of the joystick
int yPin = A1;  // analog input pin for Y-axis of the joystick

void setup() {
  myServo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  int xValue = analogRead(xPin);  // read the X-axis value
  int yValue = analogRead(yPin);  // read the Y-axis value
  
  int servoAngleX = map(xValue, 0, 1023, 0, 180);  // map X-axis value to servo angle
  int servoAngleY = map(yValue, 0, 1023, 0, 180);  // map Y-axis value to servo angle
  
  myServo.write(servoAngleX);  // move servo based on X-axis value
  delay(5);  // delay for smoother movement
  
  myServo.write(servoAngleY);  // move servo based on Y-axis value
  delay(15);  // delay for smoother movement
}
