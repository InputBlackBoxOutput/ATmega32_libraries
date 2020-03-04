/* C Program to interface DC motor using L293D
 * Created: 27 Nov 2019 4:05:39 PM
 * Author : Rutuparn Pawar
 */ 

/*
Pin connections for testing
PORTA   PIN 0   IN1  
        PIN 1   IN2  
		PIN 2   IN3 
		PIN 3   IN4
*/

//////////////////////////////////////////////////////////////////////////////////////
#define F_CPU 8000000UL // 8MHz clock speed
#include <avr/io.h>
#include <util/delay.h>

#include "L293D.h"

#define DELAY  5000

//////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
		
	while(1)
	{
		_delay_ms(DELAY);
		void initMotor();
		
		_delay_ms(DELAY);
		void moveForward();
		
		_delay_ms(DELAY);
		void moveBackward();
		
		_delay_ms(DELAY);
		void moveRight();
		
		_delay_ms(DELAY);
		void moveLeft();
		
		_delay_ms(DELAY);
		void stop();		
	}
}

//////////////////////////////////////////////////////////////////////////////////////