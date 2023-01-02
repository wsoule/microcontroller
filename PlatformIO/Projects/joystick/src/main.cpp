// #include <Arduino.h>
// #include <ezButton.h>
// #include <Servo.h>

// #define VRX_PIN A0 // arduino pin connected to vrx
// #define VRY_PIN A1 // arduiono pin connected to vry
// #define SW_PIN 7
// #define SERVO_X_PIN 2
// #define SERVO_Y_PIN 3

// #define COMMAND_NO 0x00
// #define COMMAND_LEFT 0x01
// #define COMMAND_RIGHT 0x02
// #define COMMAND_UP 0x04
// #define COMMAND_DOWN 0x08

// #define LEFT_THRESHOLD 400
// #define RIGHT_TRESHOLD 800
// #define UP_THRESHOLD 400
// #define DOWN_THRESHOLD 600

// #define UPDATE_INTERVAL 200 // 100ms

// Servo xServo;
// Servo yServo;
// ezButton button(SW_PIN);

// int xValue = 0;
// int yValue = 0;
// int xAngle = 90;
// int yAngle = 90;
// int command = COMMAND_NO;

// unsigned long lastUpdateTime = 0;

// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   xServo.attach(SERVO_X_PIN);
//   yServo.attach(SERVO_Y_PIN);
//   button.setDebounceTime(50);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   button.loop();

//   if (millis() - lastUpdateTime > UPDATE_INTERVAL) {
//     lastUpdateTime = millis();

//     // read x and y vals
//     xValue = analogRead(VRX_PIN);
//     yValue = analogRead(VRY_PIN);

//     // convert the analog value to commands 
//     // reset commands
//     command = COMMAND_NO;

//     // check left/right commands
//     if(xValue < LEFT_THRESHOLD)
//       command = command | COMMAND_LEFT;
//     else if (xValue > RIGHT_TRESHOLD)
//       command = command | COMMAND_RIGHT;
    
//     // check up/down commands
//     if (yValue < UP_THRESHOLD)
//       command = command | COMMAND_UP;
//     else if (yValue > DOWN_THRESHOLD)
//       command = command | COMMAND_DOWN;

//     // NOTE: AT A TIME, THERE MAY BE NO COMMAND, ONE COMMAND OR TWO COMMANDS

//     // print command to serial and process command
//     if (command & COMMAND_LEFT) {
//       Serial.println("COMMAND RIGHT");
//       xAngle -= 10;
//     }

//     if (command & COMMAND_RIGHT) {
//       Serial.println("COMMAND RIGHT");
//       xAngle += 10;
//     }

//     if (command & COMMAND_UP) {
//       Serial.println("COMMAND UP");
//       yAngle -= 10;
//     }

//     if (command & COMMAND_DOWN) {
//       Serial.println("COMMAND DOWN");
//       yAngle += 10;
//     }
//   // }

//   if (button.isPressed()) {
//     Serial.println("button pressed");
//     xAngle = 90;  // back to center
//     yAngle = 90;  // back to center
//   }
// }
//   xServo.write(xAngle);   // rotate servo motor 1
//   yServo.write(yAngle);   // rotate servo motor 2

//   // Serial.print(F("Servo Motor angle: "));
//   Serial.print(xValue);
//   Serial.print(F(", "));
//   Serial.print(yValue);
//   Serial.print(F(" => Servo Motor: "));
//   Serial.print(xAngle);
//   Serial.print(F(", "));
//   Serial.println(yAngle);
// }

#include <Arduino.h>
#include <Servo.h>

#define VRX_PIN      A0 // Arduino pin connected to VRX pin
#define VRY_PIN      A1 // Arduino pin connected to VRY pin
#define SERVO_X_PIN  2  // Arduino pin connected to Servo motor 1
#define SERVO_Y_PIN  3  // Arduino pin connected to Servo motor 2

Servo xServo;  // create servo object to control a servo 1
Servo yServo;  // create servo object to control a servo 2

void setup() {
  Serial.begin(9600) ;
  xServo.attach(SERVO_X_PIN);
  yServo.attach(SERVO_Y_PIN);
}

void loop() {
  // read analog X and Y analog values
  int xValue = analogRead(VRX_PIN);
  int yValue = analogRead(VRY_PIN);

  int xAngle = map(xValue, 0, 1023, 0, 180); // scale it to the servo's angle (0 to 180)
  int yAngle = map(yValue, 0, 1023, 0, 180); // scale it to the servo's angle (0 to 180)

  xServo.write(xAngle); // rotate servo motor 1
  yServo.write(yAngle); // rotate servo motor 2

  // print data to Serial Monitor on Arduino IDE
  Serial.print("Joystick: ");
  Serial.print(xValue);
  Serial.print(", ");
  Serial.print(yValue);
  Serial.print(" => Servo Motor: ");
  Serial.print(xAngle);
  Serial.print("°, ");
  Serial.print(yAngle);
  Serial.println("°");
}


