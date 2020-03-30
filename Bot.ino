#include <Servo.h>
#include <NewPing.h>
int LeftMotorForward = 7;
int LeftMotorBackward = 6;
int RightMotorForward = 4;
int RightMotorBackward = 5;
#define trig_pin A1
#define echo_pin A2
#define maximum_distance 200
int distance = 100;
NewPing sonar(trig_pin, echo_pin, maximum_distance);
Servo servo_motor;
void setup() {
  Serial.begin(9600);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  servo_motor.attach(10);
  servo_motor.write(60);
  delay(2000);
  distance = readistance();
  delay(100);
  distance = readistance();
  delay(100);
  distance = readistance();
  delay(100);
  distance = readistance();
  delay(100);
}
int lookRight() {
  servo_motor.write(20);
  delay(500);
  int distance = readistance();
  delay(100);
  servo_motor.write(60);
  return distance;
}
int lookLeft() {
  servo_motor.write(100);
  delay(500);
  int distance = readistance();
  delay(100);
  servo_motor.write(60);
  return distance;
  delay(100);
}
int readistance() {
  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0) {
    cm = 250;
  }
  return cm;
}
void moveStop() {
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward() {
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);
}
void moveBackward() {
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
}
void turnRight() {
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  delay(400);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}
void turnLeft() {
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  delay(400);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}
void loop() {
  int distanceRight = 0;
  int distanceLeft = 0;
  distance = readistance();
  delay(60);
  if (distance <= 20) {
    moveStop();
    delay(400);
    moveBackward();
    delay(500);
    moveStop();
    delay(400);
    distanceRight = lookRight();
    delay(400);
    distanceLeft = lookLeft();
    delay(400);
    if (distance >= distanceLeft) {
      turnRight();
      moveStop();
    }
    else {
      turnLeft();
      moveStop();
    }
  }
  else {
    moveForward();
  }
 
  Serial.println(distance);
 Serial.print(" cm");
}




