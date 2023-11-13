#include <Servo.h>

Servo panServo;           // Servo for pan movement
Servo tiltServo;          // Servo for tilt movement

const int panPotPin = A0;  // Pin for the pan potentiometer
const int tiltPotPin = A1; // Pin for the tilt potentiometer

// Define constants for servo angles
const int leftAngle = 0;
const int centerAngle = 45;
const int rightAngle = 90;

const int topAngle = 0;
const int centerTiltAngle = 60;
const int downAngle = 120;

// Function to map potentiometer value to servo position
int mapPotToServo(int potValue, int lowerThreshold, int upperThreshold, int minAngle, int maxAngle) {
  if (potValue < lowerThreshold) {
    return minAngle;
  } else if (potValue < upperThreshold) {
    return centerAngle;
  } else {
    return maxAngle;
  }
}

void setup() {
  Serial.begin(9600);     // Initialize serial communication for debugging
  panServo.attach(9);     // Attach the pan servo to pin 9
  tiltServo.attach(10);   // Attach the tilt servo to pin 10
}

void loop() {
  // Read the value from the pan potentiometer
  panPotValue = analogRead(panPotPin);

  // Map the pan potentiometer value to predefined angles for left, center, and right positions
  int panServoPos = mapPotToServo(panPotValue, 341, 682, leftAngle, rightAngle);

  // Set the pan servo position
  panServo.write(panServoPos);

  // Read the value from the tilt potentiometer
  tiltPotValue = analogRead(tiltPotPin);

  // Map the tilt potentiometer value to predefined angles for top, center tilt, and down positions
  int tiltServoPos = mapPotToServo(tiltPotValue, 341, 682, topAngle, downAngle);

  // Set the tilt servo position
  tiltServo.write(tiltServoPos);

  delay(100);  // Adjust the delay based on your application (increased to slow down rotation)
}
