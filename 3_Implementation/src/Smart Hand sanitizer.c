
#include <Servo.h>  // include the library for Servo Motor
/**
 * @file Hand Sanitizer.h
 * @author ARAVINTH A  (aravinth.18ece@sonatech.ac.in)
 * @brief SMART HAND SANITIZER 
 * @version 0.1
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

{
  Serial.begin(9600); // Starting Serial Terminal

  Myservo.attach(3);  // Signal Pin of Servo      
                                       
  pinMode(trigPin, OUTPUT);  // Set trig pin as output
  pinMode(echoPin, INPUT);  // Set echo pin as input
  
  Serial.print("  Distance    ");  
  Serial.print("  Measurement  ");
  delay(2000);

}

void loop()
{
  long duration, cm; // Declaring a variable
  
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);      //To keep the trig pin high for 10us
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);  //Taking input from echo pin
  cm = microsecondsToCentimeters(duration);
  Myservo.write(0);

  Serial.print("Distance:");
  Serial.print(cm);
  Serial.print("cm");
  delay(100);
  
  if(cm >= 10)  // Distance should be less than 10cm
  {
    Myservo.write(0);  // Neutral Position of shaft
  }
  else 
  {
    Myservo.write(90);  // Turn left
  }

  Serial.println();
  delay(100);

}


long microsecondsToCentimeters(long microseconds)
{
   return microseconds / 29 / 2;   // To convert microseconds to centimeters
}
