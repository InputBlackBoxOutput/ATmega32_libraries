/* Embedded C program to interface 16x2 LCD (in 8 bit mode) with ATmega32
 * Created: 13-Nov-19 10:36:07 AM
 * Author : Rutuparn Pawar
 */
/////////////////////////////////////////////////////////////////////////
//Use below code for testing
#define F_CPU 8000000UL			// Operating Frequency = 8MHz
#include <avr/io.h>		
#include <util/delay.h>			
#include <string.h>
#include <stdio.h>

#include "LCD.h"

int main()
{
	initLCD();
	
	sendCommand(0x80);		           
	display("Rutuparn Pawar");
	sendCommand(0xC0);
	display("GR.No: 17U253");
	
	while(1);  //Do nothing until reset or power restart
	
}
/////////////////////////////////////////////////////////////////////////