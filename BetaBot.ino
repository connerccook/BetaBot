/*
 Stepper Motors and DC Motor Control with Bluetooth Module.

 This program drives two unipolar or bipolar stepper motor.
 The motor is attached to digital pins 10 - 13, 2 - 5 of the Arduino.
 The program aslo runs one DC motor which is attached to pin 24.

 Created 15 Apr. 2019
 Modified 17 Apr. 2019
 by Betas

 */

#include <Stepper.h>

// the number of steps per revolution for the motor
const int stepsPerRevolution = 200;  



// initialize the stepper library on pins 2 to 13, 22, 24, 26, 28:
Stepper myStepper(stepsPerRevolution, 10, 11, 12, 13); 
Stepper myStepper2(stepsPerRevolution, 2, 3, 4, 5); 
Stepper myStepper3(stepsPerRevolution, 6, 7, 8, 9);
Stepper myStepper4(stepsPerRevolution, 22, 24, 26, 28);  


void setup() {
  pinMode(30,OUTPUT); // dc motor
  
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT); //motor 1
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT); //motor 2
  pinMode(9,OUTPUT);
  
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT); //motor 3
  pinMode(13,OUTPUT);
  
  pinMode(22,OUTPUT);
  pinMode(24,OUTPUT);  //motor 4
  pinMode(26,OUTPUT);
  pinMode(28,OUTPUT);
 
  
  // initialize the serial port:
  Serial.begin(9600);
  
}


void powerForward(int steps){   //For front and back movements

   // set the speed at 100 rpm:
  myStepper.setSpeed(100);
  myStepper2.setSpeed(100);
  myStepper3.setSpeed(100);
  myStepper4.setSpeed(100);
  
  myStepper.step(1);
  myStepper2.step(1);
  myStepper3.step(1);
  myStepper4.step(1);
  
  }

  void powerBackward(int steps){   //For front and back movements

   // set the speed at 100 rpm:
  myStepper.setSpeed(100);
  myStepper2.setSpeed(100);
  myStepper3.setSpeed(100);
  myStepper4.setSpeed(100);
  
  myStepper.step(-1);
  myStepper2.step(-1);
  myStepper3.step(-1);
  myStepper4.step(-1);
  
  }

  void powerLeft(int steps){   //function for left turn
   
    // set the speed at 100 rpm:
  myStepper.setSpeed(100);
  myStepper2.setSpeed(100);
  myStepper3.setSpeed(100);
  myStepper4.setSpeed(100);
    
    myStepper.step(-1);
    myStepper2.step(1);
    myStepper3.step(-1);
    myStepper4.step(1);
  }

   void powerRight(int steps){  //function for right turn

    // set the speed at 100 rpm:
  myStepper.setSpeed(100);
  myStepper2.setSpeed(100);
  myStepper3.setSpeed(100);
  myStepper4.setSpeed(100);
    
    myStepper.step(1);
    myStepper2.step(-1);
    myStepper3.step(1);
    myStepper4.step(-1);
  }

  
   void powerForwardRight(int steps){  //function for forward right turn

    // set the speed at 100 rpm:
  myStepper.setSpeed(100);
  myStepper2.setSpeed(50);
  myStepper3.setSpeed(100);
  myStepper4.setSpeed(50);
    
    myStepper.step(1);
    myStepper2.step(1);
    myStepper3.step(1);
    myStepper4.step(1);
  }

void powerForwardLeft(int steps){  //function for forward right turn

    // set the speed at 100 rpm:
  myStepper.setSpeed(50);
  myStepper2.setSpeed(100);
  myStepper3.setSpeed(50);
  myStepper4.setSpeed(100);
    
    myStepper.step(1);
    myStepper2.step(1);
    myStepper3.step(1);
    myStepper4.step(1);
  }

  void powerBackwardRight(int steps){  //function for forward right turn

    // set the speed at 100 rpm:
  myStepper.setSpeed(100);
  myStepper2.setSpeed(50);
  myStepper3.setSpeed(100);
  myStepper4.setSpeed(50);
    
    myStepper.step(-1);
    myStepper2.step(-1);
    myStepper3.step(-1);
    myStepper4.step(-1);
  }

  void powerBackwardLeft(int steps){
    myStepper.setSpeed(50);
    myStepper2.setSpeed(100);
    myStepper3.setSpeed(50);
    myStepper4.setSpeed(100);

      myStepper.step(-1);
      myStepper2.step(-1);
      myStepper3.step(-1);
      myStepper4.step(-1);
  }

 /* void weaponStart ( ){   //function for toggling weapon
    
    
  }*/

    
void loop() {
  digitalWrite(30,HIGH);

  int state, up, down, left, right, weapon, music; // integer variable declaration
  
  
  if(Serial.available() > 0) // Checks whether data is comming from the serial port
  
  { 
   
    state = Serial.read(); // Reads the data from the serial port

  }//end of reading data from port
  

    if (state == '1')   //Forward 
    {
      Serial.print("Forward On");
      
      up = 1;
    } 
 
  else if (state == '2') //Forward
    {
      Serial.print("Forward Off ");

      up = 0;

    } 
  

    else if(state == '3')  //Left
  {
      Serial.print("Left On");

    left = 1;
  } 

    else if(state == '4') //Left
  {
      Serial.print("Left Off"); 

      left = 0;

  }
  
    else if(state == '5') //Backward
  {
      Serial.print("Backward On");

      down = 1;
    
  }

else if(state == '6') //Backward
  {
      Serial.print("BackWard Off");

      down = 0;
  }
  
  else if(state == '7') //Weapon
  {
      Serial.print("Weapon On");

     
  weapon = 1;
  }
  
  else if(state == '8') //Weapon
  {
      Serial.print("Weapon Off");


   weapon = 0;
  }
  
  else if(state == '9') //Right
  {
      Serial.print("Right On");

      right = 1;
  }
  

  else if(state == '10')  //Right
  {
      Serial.print("Right Off");

      right = 0;
  }

/*
  else if(state == '11')
  {
      Serial.printIn("Music On");

      music = 1;
  }

  else if(state == '12')
  {
      Serial.printIn("Music Off");

     music = 0;
  }

*/


  if(up == 1){
    
    powerForward(1); // move forward
  }
  

  else if(right == 1){
    
    powerRight(1); // move right
  }

  else if(left == 1){
    
    powerLeft(1); // move left
  }

  else if(down == 1){
    
    powerBackward(1); // move backward
  }

  else if(up == 1 && left == 1){

    powerForwardLeft(1);  // move forward and left
    }

    else if(up == 1 && right == 1){

      powerForwardRight(1); // move forward and right
    }

    else if(down == 1 && left == 1){

      powerBackwardLeft(1);  // move backward and left
    }

    else if(down == 1 && right == 1){

      powerBackwardRight(1); // move backward and right
    }

  /*else if(weapon == 1){
    
    weaponStart();
   } */
  
  } //end of the loop 




