/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 15 Apr. 2019
 Modified 16 Apr. 2019
 by Betas

 */

#include <Stepper.h>

// the number of steps per revolution for the motor
const int stepsPerRevolution = 200;  


// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 10, 11, 12, 13); 
Stepper myStepper2(stepsPerRevolution, 2, 3, 4, 5); 


void setup() {
  pinMode(24,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  // set the speed at 100 rpm:
  myStepper.setSpeed(10);
  myStepper2.setSpeed(10);
  //myStepper3.setSpeed(100);
 // myStepper4.setSpeed(100);
  
  // initialize the serial port:
  Serial.begin(9600);
  
}


void powerBoth(int steps){
  
  myStepper.step(1);
  myStepper2.step(1);
//  myStepper3.step(steps);
  //myStepper4.step(steps);
  
  }

void loop() {
  digitalWrite(24,HIGH);

  int state;
  
  if(Serial.available() > 0) // Checks whether data is comming from the serial port
  
  { 
   
    state = Serial.read(); // Reads the data from the serial port

  }
  

    if (state == '0') 
    {
   
      // step one revolution  in one direction:
      Serial.println("clockwise");
      
      // running both motors forward
      powerBoth(stepsPerRevolution);

      
      state = 0;
    }
 
  else if (state == '1') 
    {
  
      // step one revolution in the other direction:
      Serial.println("counterclockwise");

      // running both motors backward
      powerBoth(-stepsPerRevolution);
      
      state = 0;
    } 
  
  //powerBoth(200);
  }
