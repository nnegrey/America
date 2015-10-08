#include "America.h"
#include <Servo.h>

Servo right_motor;
Servo left_motor;

void setup() {
   Serial.begin(9600);  // begin serial 9600 baud for debugging
   
   pinMode(TOGGLE_ON,INPUT);

   pinMode(RIGHT_LIGHT_SENSOR, INPUT);
   pinMode(LEFT_LIGHT_SENSOR, INPUT);
   pinMode(SCISSOR_MOTOR, OUTPUT);
   pinMode(SCISSOR_MOTOR_REVERSE, OUTPUT);
   analogWrite(SCISSOR_ANALOG, 255);

   pinMode(LED_BLUE, OUTPUT);
   digitalWrite(LED_BLUE, LOW);
   pinMode(LED_ORANGE, OUTPUT);
   digitalWrite(LED_ORANGE, LOW);

   pinMode(LEFT_MOTOR, OUTPUT);
   pinMode(RIGHT_MOTOR, OUTPUT);

   pinMode(FRONT_LEFT_BUTTON, INPUT);
   pinMode(FRONT_RIGHT_BUTTON, INPUT);
   pinMode(GEAR_BUTTON_1, INPUT);
   pinMode(GEAR_BUTTON_2, INPUT);
 
   right_motor.attach(RIGHT_MOTOR);
   left_motor.attach(LEFT_MOTOR);
   motorStop();
      
   lowerScissor();
   while(!digitalRead(GEAR_BUTTON_1));
   stopScissor();
}

void loop() {   
     checkLowerButton();
     checkLiftButton();
     midlineToRing();
     ringToMidline();  
     midlineToScore();  
     scoreToMidline();   
}

void passDoubleBlack() {  
   unsigned long time = millis() + 250;
   while(millis() < time) {
      checkLowerButton();
      checkLiftButton();
   }
}

void midlineToScore() {
     straight();
     // From Mid line go and Ram
     ram();
     motorStop();
     
    unsigned long time = millis() + 2250;
    while(millis() < time)
       lowerScissor();
    
    stopScissor();
}

void scoreToMidline() {
     
//     Reverse();
     timedReverse();
     timedReverse();
     lowerScissor();
     // Turn Around
     turnAround();
     straight();
     passDoubleBlack();
     motorStop();
}

void midlineToRing()  {
     straight(); 
     ram();
     motorStop();
     
     unsigned long time = millis() + 75;
     motorReverse(0, 90);
     while(millis() < time);
     motorStop();

    time = millis() + 2350;
    while(millis() < time) 
       liftScissor();  
    
    stopScissor();
}

void ringToMidline() {
//     Reverse();
     timedReverse();
     turnAroundAtRing();
     liftScissor();
     // Move away from wall
 
     // Turn Around
//     turnAround();
     straight();
     passDoubleBlack();
     motorStop();     
}

// Standard Calls
void straight() {
      
   while(checkSensorRight() < 900 || checkSensorLeft() < 900) {
      
      if(checkSensorLeft() >= 800) {
         motorStraight(5, 90);
      }
      else if(checkSensorRight() >= 800) {
         motorStraight(90, 5); 
      }
      else {
         motorStraight(90, 90);
      }
   }
}

void ram() {
   while(!checkBumperLeft() || !checkBumperRight()) {
      
      if(checkSensorLeft() >= 800) {
         motorStraight(3, 10);
      }
      else if(checkSensorRight() >= 800) {
         motorStraight(10, 3); 
      }
      else {
         motorStraight(10, 10);
      }
   }
   
   motorStop();
}

void Reverse() {
  while(checkSensorRight() < 950 || checkSensorLeft() < 950) {
        motorReverse(90, 10);        
  }
 
  motorStop();
}

void timedReverse() {
  unsigned long time = millis() + 1000;
//  motorReverse(90, 90);
  while(millis() < time) {
        motorReverse(90, 10);        
  }
 
  motorStop();
}


void turnAround() {     
  unsigned long time = millis() + 500;
  
  while(millis() < time) 
     motorRight();
     
  while(checkSensorRight() < 700)// 950 TODO
//    while(checkSensorLeft() < 700)// 950
     motorRight();
  
  motorStop();
}

void turnAroundAtRing() {     
  turnAround();
  turnAround();
}

//// SCISSOR Methods
void liftScissor() {
  analogWrite(SCISSOR_ANALOG, 255);

  digitalWrite(SCISSOR_MOTOR, LOW);
  digitalWrite(SCISSOR_MOTOR_REVERSE, HIGH);   
}

void stopScissor() {
  digitalWrite(SCISSOR_MOTOR, LOW);
  digitalWrite(SCISSOR_MOTOR_REVERSE, LOW);
}

void lowerScissor() {
  analogWrite(SCISSOR_ANALOG, 255);

  digitalWrite(SCISSOR_MOTOR, HIGH);
  digitalWrite(SCISSOR_MOTOR_REVERSE, LOW);     
}

// MOVEMENT Methods
//Speeds to be given from 0 to 90
void motorStraight(int leftServoSpeed, int rightServoSpeed) {
  rightServoSpeed = 90 - rightServoSpeed;
  leftServoSpeed = leftServoSpeed + 90;
  
  if (rightServoSpeed < 0) {
     rightServoSpeed = 0;
  }
  if (leftServoSpeed > 180) {
     leftServoSpeed = 180;
  }
  
  
  // set speed
  right_motor.write(rightServoSpeed);
  left_motor.write(leftServoSpeed);
}

void motorReverse(int leftServoSpeed, int rightServoSpeed) {
  leftServoSpeed = SERVO_STOP - leftServoSpeed;
  rightServoSpeed = rightServoSpeed + 90;
  
  if (leftServoSpeed < 0) {
     leftServoSpeed = 0;
  }
  if (rightServoSpeed > 180) {
     rightServoSpeed = 180;
  }
  //set speed
  right_motor.write(rightServoSpeed);
  left_motor.write(leftServoSpeed);
}

void motorRight() {
  // set speed
  // Give outer wheel more power to create on point turn
  right_motor.write(SERVO_RIGHT_BACKWARD - 45);
  left_motor.write(SERVO_LEFT_FORWARD - 45);
}

void motorStop() {
  right_motor.write(90);
  left_motor.write(90);
}
