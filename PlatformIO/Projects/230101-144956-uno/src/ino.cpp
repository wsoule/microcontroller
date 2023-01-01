#include <Arduino.h>
//Define Trig and Echo pin:
#define trigPin 7
#define echoPin 6

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Clear the trigPin by setting it to LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);

  // Trigger the sensor by settign the trigPin high for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, pulseInt() return the duration (length of the pulse) in microseconds 
  duration = pulseIn(echoPin, HIGH);
  // Calculate the distance:
  distance = duration * 0.034 / 2;

  // print the distance
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(50);
}
