#include "America.h"

int checkSensorRight() {
   int sensor = analogRead(RIGHT_LIGHT_SENSOR);
   
   checkLowerButton();
   checkLiftButton();
   
   if(sensor >= 700) 
     digitalWrite(LED_BLUE, HIGH);
   else
     digitalWrite(LED_BLUE, LOW);
   return sensor;
}

int checkSensorLeft() {
   int sensor = analogRead(LEFT_LIGHT_SENSOR);
   
   checkLowerButton();
   checkLiftButton();
   
   if(sensor >= 700) 
     digitalWrite(LED_ORANGE, HIGH);
   else
     digitalWrite(LED_ORANGE, LOW);
   return sensor;  
}

int checkBumperRight() {
   int bumper = digitalRead(FRONT_RIGHT_BUTTON);
   
   checkLowerButton();
   checkLiftButton();
   
   if(bumper) 
     digitalWrite(LED_BLUE, HIGH);
   else
     digitalWrite(LED_BLUE, LOW);
          
   return bumper;
}

int checkBumperLeft() {
   int bumper = digitalRead(FRONT_LEFT_BUTTON);
      
   checkLowerButton();
   checkLiftButton();
   
   if(bumper) 
     digitalWrite(LED_ORANGE, HIGH);
   else
     digitalWrite(LED_ORANGE, LOW);
   
   return bumper;  
}

void checkLowerButton() {
   if(digitalRead(GEAR_BUTTON_1)) {
      stopScissor();
   }
}

void checkLiftButton() {
   if(digitalRead(GEAR_BUTTON_2)) {
      stopScissor();
   }
 }
