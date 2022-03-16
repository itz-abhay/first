#include<NewPing.h>

#define MLa 8                   //left motor 1st pin
#define MLb 9                  //left motor 2nd pin
#define MRa 10               //right motor 1st pin
#define MRb 11               //right motor 2nd pin

#define trigPin  6  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define echoPin  7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500Distance.
long duration, distance;
NewPing sonar(trigPin, echoPin, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(MLa, OUTPUT);
pinMode(MLb, OUTPUT);
pinMode(MRa, OUTPUT);
pinMode(MRb, OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop()
{
    digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); //Transmits waves for 10us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);  //Receive reflected waves
  distance = duration / 58.2;        //Get distance
  delay(10);
 if(distance > 25 )    // Condition for absence of Obstacle
 {
  digitalWrite(MRb, LOW); //Move forward
  digitalWrite(MRa, HIGH);
  digitalWrite(MLb, LOW);
  digitalWrite(MLa, HIGH);
 }
 if(distance < 24)    //Condition for presence of obstacle
 {
  
  digitalWrite(MRb, HIGH);   //Move Left
  digitalWrite(MRa, LOW);
  digitalWrite(MLb, LOW);
  digitalWrite(MLa, LOW);
  delay(300);
 }
}
