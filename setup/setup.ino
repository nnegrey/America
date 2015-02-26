/** Main Functions
 * 1) Line Tracing
 * 2) Movement
 * 3) Off line movement (SOS)
 * 4) Pickup Rings
 * 5) Place Rings
 * 6) Center Rings
 * 7) Music
 * Center Peg - Last 5 minutes 
 */

void setup() {
  initialMovement();
}


void loop() {
  
}

/** Initial Start Movement
 * -Get to the middle line
 * -Rotate toward the horizontal rings (to the right)
 */
void initialMovement() {
  // Get to the middle line
  while(getSensorData()) {
    Robot.motorsWrite(255, 255); //Make the robot go forward, full speed
  }
  Robot.motorsWrite(0, 0);

  // Rotate toward the horizontal rings (to the right)
  Robot.motorsWrite(255, -255);//Make the robot rotate right, full speed
  delay(1000); // determine how long it takes to turn 90 degrees to the right
  Robot.motorsWrite(0, 0);

  alignSensors();
  getRingsMovement();
}


/** Pickup Rings Movement
 * -Move to the horizontal line (before the horizontal rings)
 * -Confirm that the arm is at a height of 6 inches. (create lowerTheArm()
 * -Move toward the wall
 * -pickupRings()
 * -placeRingsMovement()
 */
void getRingsMovement() {
  // Move to the horizontal line (before the horizontal rings)
  while(getSensorData()) {
    Robot.motorsWrite(255, 255);
  }
  Robot.motorsWrite(0, 0);

  // Confirm that the arm is at a height of 6 inches.
  lowerTheArm();

  // Move toward the wall
  Robot.motorsWrite(255, 255);
  delay(1000);
  Robot.motorsWrite(0, 0);

  // pickupRings()
  pickupRings();

  // placeRingsMovement()
  placeRingsMovement();
}


/** Move To The Middle With The Rings and Place Them
 * -Full reverse until at the center line
 * -Rotate 180 degrees
 * -Move to the horizontal line (before the vertical rings)
 * -raiseTheArm()
 * -Move toward the wall
 * -placeRings()
 * -returnToMidLine
 * -rotate 180 degrees
 * -getRingsMovement()
 */
void placeRingsMovement() {
  // Full reverse until at the center line
  while(getSensorData()) {
    Robot.motorsWrite(-255, -255);
  }
  Robot.motorsWrite(0, 0);

  // Rotate 180 degrees
  Robot.motorsWrite(255, -255);
  delay(1000);
  Robot.motorsWrite(0, 0);

  // Move to the horizontal line (before the vertical rings)
  while(getSensorData()) {
    Robot.motorsWrite(255, 255);
  }
  Robot.motorsWrite(0, 0);

  // raiseTheArm()
  raiseTheArm();

  // Move toward the wall
  Robot.motorsWrite(255, 255);
  delay(1000);
  Robot.motorsWrite(0, 0);

  // placeRings()
  placeRings();

  // returnToMidLine
  while(getSensorData()) {
    Robot.motorsWrite(-255, -255);
  }
  Robot.motorsWrite(0, 0);

  // rotate 180 degrees
  Robot.motorsWrite(255, -255);
  delay(1000);
  Robot.motorsWrite(0, 0);

  // getRingsMovement()
  getRingsMovement();
}

