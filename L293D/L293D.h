/* Embedded C Program to interface DC motor using L293D
 * Created: 27 Nov 2019 4:05:39 PM
 * Author : Rutuparn Pawar
 */ 

// Uncomment to invert the control logic
#define INVERT_LOGIC 

#define MOTOR_PORT      PORTA
#define DDR_MOTOR_PORT  DDRA

//MOTOR 1
#define A1 0  
#define A2 1
//MOTOR 2
#define A3 2
#define A4 3

#define DIR1   1<<A3| 1<<A1
#define DIR2   1<<A4| 1<<A2
#define TURN1  1<<A4| 1<<A1
#define TURN2  1<<A3| 1<<A2

#define ALL   1<<A4| 1<<A3| 1<<A2| 1<<A1

void initMotor(void);

void moveForward(void);
void moveBackward(void);
void moveRight(void);
void moveLeft(void);

void stop(void);