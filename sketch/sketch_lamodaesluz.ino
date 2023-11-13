#include <Servo.h>

Servo panServo;           // Servo for pan movement
Servo tiltServo;          // Servo for tilt movement

const int panPotPin = A0;  // Pin for the pan potentiometer
const int tiltPotPin = A1; // Pin for the tilt potentiometer

int panPotValue = 0;       // Variable to store the pan potentiometer value
int tiltPotValue = 0;      // Variable to store the tilt potentiometer value

int leftAngle = 0;        // Angle for the left position
int centerAngle = 45;     // Angle for the center position
int rightAngle = 90;      // Angle for the right position

int topAngle = 0;         // Angle for the top position
int centerTiltAngle = 60; // Angle for the center tilt position
int downAngle = 120;      // Angle for the down position

void setup() {
  Serial.begin(9600);     // Initialize serial communication for debugging
  panServo.attach(9);     // Attach the pan servo to pin 9
  tiltServo.attach(10);   // Attach the tilt servo to pin 10
}

void loop() {
  // Read the value from the pan potentiometer
  panPotValue = analogRead(panPotPin);

  // Map the pan potentiometer value to predefined angles for left, center, and right positions
  int panServoPos;

  if (panPotValue < 341) {
    // If analog value is in the lower third
    panServoPos = leftAngle;
  } else if (panPotValue < 682) {
    // If analog value is in the middle third
    panServoPos = centerAngle;
  } else {
    // If analog value is in the upper third
    panServoPos = rightAngle;
  }

  // Set the pan servo position
  panServo.write(panServoPos);

  // Read the value from the tilt potentiometer
  tiltPotValue = analogRead(tiltPotPin);

  // Map the tilt potentiometer value to predefined angles for top, center tilt, and down positions
  int tiltServoPos;

  if (tiltPotValue < 341) {
    // If analog value is in the lower third
    tiltServoPos = topAngle;
  } else if (tiltPotValue < 682) {
    // If analog value is in the middle third
    tiltServoPos = centerTiltAngle;
  } else {
    // If analog value is in the upper third
    tiltServoPos = downAngle;
  }

  // Set the tilt servo position
  tiltServo.write(tiltServoPos);

  delay(100);  // Adjust the delay based on your application (increased to slow down rotation)
}
