/* Embedded C Program to interface DC motor using L293D
 * Created: 27 Nov 2019 4:05:39 PM
 * Author : Rutuparn Pawar
 */ 

#include <avr/io.h>
#include <util/delay.h>

#include "L293D.h"

//////////////////////////////////////////////////////////////////////////////////////
void initMotor() {
	DDR_MOTOR_PORT |= ALL;
}

void moveForward() {
	MOTOR_PORT &= ~(ALL); 
	
	#ifdef INVERT_LOGIC 
	MOTOR_PORT |= DIR1;
	#else
	MOTOR_PORT |= DIR2;
	#endif	
}

void moveBackward() {
	MOTOR_PORT &= ~(ALL);
		
	#ifdef INVERT_LOGIC
	MOTOR_PORT |= DIR2;
	#else
	MOTOR_PORT |= DIR1;
	#endif
}

void moveRight() {
	MOTOR_PORT &= ~(ALL);
	
	#ifdef INVERT_LOGIC
	MOTOR_PORT |= TURN1;
	#else
	MOTOR_PORT |= TURN2;
	#endif
}

void moveLeft() {
	MOTOR_PORT &= ~(ALL);
	
	#ifdef INVERT_LOGIC
	MOTOR_PORT |= TURN2;
	#else
	MOTOR_PORT |= TURN1;
	#endif
}

void stop() {
	MOTOR_PORT &= ~ALL;
}

//////////////////////////////////////////////////////////////////////////////////////