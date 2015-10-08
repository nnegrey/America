#define LEFT_LIGHT_SENSOR     A1 	// Analog pin for the left light sensor
#define RIGHT_LIGHT_SENSOR    A0	// Anlog pin for the right light sensor

#define SCISSOR_ANALOG        9 	// Analong pin for variable speed for arm
#define SCISSOR_MOTOR         7 	// Needs to always be opposite the SCISSOR_MOTOR_REVERSE value
#define SCISSOR_MOTOR_REVERSE 8

#define RIGHT_MOTOR		   4		// pin to control the right servo motor
#define LEFT_MOTOR		   5		// pin to control the right servo motor

#define SERVO_RIGHT_FORWARD        0
#define SERVO_RIGHT_BACKWARD       180
#define SERVO_LEFT_FORWARD         180
#define SERVO_LEFT_BACKWARD        0
#define SERVO_STOP                 90


#define	FRONT_LEFT_BUTTON	  12 	// the front left touch sensor that determines when the robot has rammed the wall
#define	FRONT_RIGHT_BUTTON	  13 	// the front right touch sensor that determines when the robot has ramed the wall
#define	GEAR_BUTTON_1		  2		// a button on the gear to determine how high the scissor has travelled
#define GEAR_BUTTON_2		  3		// a button on the gear to determine how low the scissor has travelled

#define LED_ORANGE			  10	// orange LED used for debugging or just general awesomeness
#define	LED_BLUE			  11	// blue led used for programming or just general awesomeness

#define TOGGLE_ON             6	    // toggle switch

void midlineToScore();
void scoreToMidline();
void midlineToRing();
void ringToMidline();
void moveStraight();
void moveReverse();
void turnAround();
void turnRight();
void turnLeft();
void liftScissor();
void stopScissor();
void lowerScissor();
void motorStraight();   //Should be a set amount of speeds, probably three
void motorReverse();
void motorRight();      //Always move 90 degrees, Needs More Work
void motorLeft();       //Always move 90 degrees, Needs More Work
void motorStop();
int checkSensorRight();
int checkSensorLeft();
int checkBumperRight();
int checkBumperLeft();
void checkLowerButton();
void checkLiftButton();

