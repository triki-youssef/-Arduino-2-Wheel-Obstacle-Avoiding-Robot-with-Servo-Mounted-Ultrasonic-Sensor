#include <Servo.h>

// Motor pins
const int motorLeftForward = 4;
const int motorLeftBackward = 7;
const int motorRightForward = 9;
const int motorRightBackward = 10;
const int ena = 6;
const int enb = 12;

// Ultrasonic sensor pins
const int trigPin = 2;
const int echoPin = 3;

// Servo
Servo myServo;
const int servoPin = 11;

// Variables
long duration;
int distance;
int leftDistance;
int rightDistance;

// Movement functions
void moveForward() {
  digitalWrite(ena, HIGH); 
  digitalWrite(enb, HIGH);
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightBackward, LOW);
}

void turnRight() {
  digitalWrite(ena, HIGH);
  digitalWrite(enb, HIGH);
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightBackward, LOW);
}

void turnLeft() {
  digitalWrite(ena, HIGH);
  digitalWrite(enb, HIGH);
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftBackward, HIGH);
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightBackward, LOW);
}

void stopMoving() {
  digitalWrite(ena, LOW);
  digitalWrite(enb, LOW);
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightBackward, LOW);
}

// Reads distance in cm from ultrasonic sensor
int readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000); // 30ms timeout
  if (duration == 0) {
    return 0; // no echo received
  }
  distance = duration * 0.034 / 2; // Convert to cm
  return distance;
}

void setup() {
  // Motor pins
  pinMode(motorLeftForward, OUTPUT);
  pinMode(motorLeftBackward, OUTPUT);
  pinMode(motorRightForward, OUTPUT);
  pinMode(motorRightBackward, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  digitalWrite(ena, LOW);
  digitalWrite(enb, LOW);

  // Ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Servo setup
  myServo.attach(servoPin);
  myServo.write(90); // Center position

  Serial.begin(9600);
}

void loop() {
  int frontDistance = readDistance();
  Serial.print("Front Distance: ");
  Serial.println(frontDistance);

  // Use 20 cm as the front obstacle threshold
  if (frontDistance > 20 || frontDistance == 0) {
    moveForward();
  } else {
    stopMoving();
    delay(300);

    // Check right side
    myServo.write(20);
    delay(300);
    rightDistance = readDistance();
    delay(300);
    Serial.print("Right Distance: ");
    Serial.println(rightDistance);

    // Check left side
    myServo.write(160);
    delay(300);
    leftDistance = readDistance();
    delay(300);
    Serial.print("Left Distance: ");
    Serial.println(leftDistance);

    // Return servo to center
    myServo.write(90);
    delay(300);

    // Use 20 cm as side threshold
    bool rightClear = (rightDistance > 20 || rightDistance == 0);
    bool leftClear = (leftDistance > 20 || leftDistance == 0);

    if (rightClear && leftClear) {
      turnRight();
      delay(500);
      stopMoving();
      delay(500);
    } else if (rightClear) {
      turnRight();
      delay(500);
      stopMoving();
      delay(500);
    } else if (leftClear) {
      turnLeft();
      delay(500);
      stopMoving();
      delay(500);
    } else {
      // Both sides blocked, do a U-turn
      turnRight();
      delay(1000); // Longer turn for 180 degrees
      stopMoving();
      delay(500);
    }
  }
}
