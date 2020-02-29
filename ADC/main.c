/* Embedded C program to get data from ADC of Atmega32
 * Created: 20-Nov-19 11:27:15 AM
 * Author : Rutuparn Pawar
 */ 
////////////////////////////////////////////////////////////////////////////////////
// Use below code for testing
// Note: Do not forget to include LCD library

#define F_CPU 8000000UL			// Operating Frequency = 8MHz 
#include <avr/io.h>		
#include <util/delay.h>			
#include <string.h>
#include <stdio.h>

#include "ADC.h"
#include "LCD.h"

#define Data_Port      PORTC 
#define Command_Port   PORTD
#define Degree_Symbol 0xDF

int main()
{
	char Temperature[10];
	float C;

	initLCD();                 
	initADC();                 
	
	while(1)
	{
		sendCommand(0x80);		
		display("Temperature");
		
		sendCommand(0xC0);
		C = (ReadADC(0)*4.88);                                  // Read channel 0 where LM35 connected
		C = (C/10.00);

		sprintf(Temperature,"%d%cC  ", (int)C, Degree_Symbol);  // Convert integer value to ASCII string 
		display(Temperature);
		
		_delay_ms(1000);
		
	}
	return 0;
}
// ////////////////////////////////////////////////////////////////////////////////////





