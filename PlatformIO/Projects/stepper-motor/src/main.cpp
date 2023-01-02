#include <Arduino.h>
// AccelStepper Library
// #include <AccelStepper.h>
#include <Stepper.h>

#define FULLSTEP 4

const int stepsPerRevolution = 2048;

// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
// AccelStepper stepper(FULLSTEP, 11, 9, 10, 8);

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // put initial code here to run once:
  // Set the speed to 5 rpm:
  myStepper.setSpeed(6);
  Serial.begin(9600);


  // stepper.setMaxSpeed(1000.0);    // set max speed
  // stepper.setAcceleration(50.0);  // set acceleration
  // stepper.setSpeed(200);          // set inital speed
  // stepper.setCurrentPosition(0);  // set original position
  // stepper.moveTo(STEP_PER_REVOLUTION); // set target position: 64 steps <=> one revolution
}

void loop() {
  // put your main code here, to run repeatedly:
  // change direction once the motor reaches the target position
  // if (stepper.distanceToGo() == 0) {
  //   stepper.moveTo(-stepper.currentPosition());
  // }

  // stepper.run(); // must be called in loop function

  // Serial.print(F("CurrentPosition: "));
  // Serial.println(stepper.currentPosition());


  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);

   // Step one revolution in the other direction:
  // Serial.println("counterclockwise");
  // myStepper.step(-stepsPerRevolution);
  // delay(500);

}