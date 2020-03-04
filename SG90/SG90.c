/*C Program to interface SG90 servo motor with Atmega32
 * Created: 27-Nov-19 10:34:07 AM
 * Author : Rutuparn Pawar
 */ 

// Servo Control Pin connected to PORTB PIN 3

//////////////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>
#include <util/delay.h>

#include "SG90.h"
//////////////////////////////////////////////////////////////////////////////////////
// Helper function to generate delay in us
void delay(int times)
{
	for(unsigned int i=0; i<times; i++)
		_delay_us(1);
}

//////////////////////////////////////////////////////////////////////////////////////
void initServo()
{
	DDR_SERVO_PORT |= 1<<SERVO;          
	SERVO_PORT &= ~(1<<SERVO);
}

void moveServo(int angle)
{
	unsigned int T_ON =(int)angle * (PULSE_MAX_ANGLE - PULSE_MIN_ANGLE)/180;

	for(unsigned char x =0; x<PULSES; x++)
	{
		SERVO_PORT |= 1<<SERVO;
		delay(T_ON);
		
		SERVO_PORT &= ~(1<<SERVO);
		delay(T_TOTAL - T_ON);
	}
	
}

//////////////////////////////////////////////////////////////////////////////////////



