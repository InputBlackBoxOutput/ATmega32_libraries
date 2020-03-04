/*C Program to interface SG90 servo motor with Atmega32
 * Created: 27-Nov-19 10:34:07 AM
 * Author : Rutuparn Pawar
 */ 

// Servo Control Pin connected to PORTB PIN 3
//////////////////////////////////////////////////////////////////////////////////////////
//Use below code for testing
#define F_CPU 8000000UL // 8 MHz clock speed
#include <avr/io.h>
#include <util/delay.h>

#include "SG90.h"

//////////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	while(1)
	{
		moveServo(0);
		_delay_ms(1000);
		
		moveServo(90);
		_delay_ms(1000);

		moveServo(180);
		_delay_ms(1000);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////


