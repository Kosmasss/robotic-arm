#include <Servo.h>


Servo servo1;
Servo servo2;
Servo servo3;


const int joystickXPin = A0;
const int joystickYPin = A1;
const int buttonPin = 6;
const int servo1Pin = 9;
const int servo2Pin = 10;
const int servo3Pin = 11;


int servo1Pos = 90;
int servo2Pos = 90;
int servo3Pos = 90;


bool buttonPressed = false;

void setup() {
  
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);

  
  servo1.write(servo1Pos);
  servo2.write(servo2Pos);
  servo3.write(servo3Pos);

  
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  int joystickXValue = analogRead(joystickXPin);
  int joystickYValue = analogRead(joystickYPin);


  servo1Pos = map(joystickXValue, 0, 1023, 0, 180);
  servo2Pos = map(joystickYValue, 0, 1023, 0, 180);

  
  servo1.write(servo1Pos);
  servo2.write(servo2Pos);

  
  if (digitalRead(buttonPin) == HIGH && !buttonPressed) {
    buttonPressed = true;
    // Κίνηση του τρίτου σερβο
    servo3Pos = (servo3Pos == 90) ? 0 : 90; 
    servo3.write(servo3Pos);
  }

 
  if (digitalRead(buttonPin) == LOW && buttonPressed) {
    buttonPressed = false;
  }

  
  delay(15);
}
