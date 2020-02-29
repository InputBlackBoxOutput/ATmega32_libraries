/* Embedded C program to get data from ADC of Atmega32
 * Created: 20-Nov-19 11:27:15 AM
 * Author : Rutuparn Pawar
 */ 

///////////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>
#include <util/delay.h>

#include "ADC.h"		
////////////////////////////////////////////////////////////////////////////////////

void initADC(void)
{
	DDRA = 0x00;	        
	ADCSRA = 0x87;             
}
////////////////////////////////////////////////////////////////////////////////////

int ReadADC(char channel)
{
	ADMUX = 0x40 | (channel & 0x07);   
	ADCSRA |= (1<<ADSC);              
	while (!(ADCSRA & (1<<ADIF)));     
	
	ADCSRA |= (1<<ADIF);                
	_delay_ms(1);                      
	return ADCW;                        
}

///////////////////////////////////////////////////////////////////////////////////





