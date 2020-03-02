/* Embedded C program to interface 16x2 LCD (in 8 bit mode) with ATmega32
 * Created: 13-Nov-19 10:36:07 AM
 * Author : Rutuparn Pawar
 */
//////////////////////////////////////////////////////////////////////////////// 		     
#include <avr/io.h>
#include <util/delay.h>

#include "LCD.h"

////////////////////////////////////////////////////////////////////////////////
void initLCD(void)			
{
	DDR_CommandPort |= 1<<RS|1<<RW|1<<EN;		  
	DDR_DataPort = 0xFF;		 

	_delay_ms(20);				
	sendCommand(0x38);			// Initialization of 16X2 LCD in 8bit mode 
	sendCommand(0x0C);			// Display ON Cursor OFF 
	sendCommand(0x06);			// Auto Increment cursor 
	sendCommand(0x01);			// Clear display 
	
	_delay_ms(2);				 
	sendCommand(0x80);			
}

/////////////////////////////////////////////////////////////////////////////////
void sendCommand(unsigned char command)
{
	dataPort = command;

	//RS=0   Rw=0  
	commandPort &= ~(1<<RS|1<<RW);
	
	commandPort |= 1<<EN;    //EN=1 	  
	_delay_us(1);
	commandPort &= ~(1<<EN); //EN=0
	
	_delay_ms(2);
}

/////////////////////////////////////////////////////////////////////////////////
void sendData(unsigned char data)  // LCD data write function 
{
	dataPort= data;
	//RS=1   RW=0  
	commandPort &= ~(1<<RW);
	commandPort |= 1<<RS;
	
	commandPort |= 1<<EN;    //EN=1 	  
	_delay_us(1);
	commandPort &= ~(1<<EN); //EN=0
	
	_delay_ms(2);
}

//////////////////////////////////////////////////////////////////////////////////
void display(char *str)		
{
	int i;
	for(i=0;str[i]!=0;i++)		
		sendData (str[i]);
}

////////////////////////////////////////////////////////////////////////////////
void displayAtPosition(int row, int column, char* str)
{
	unsigned char pos;

	if(row == 1)
		pos = 0x80 | (column-1);			//set cursor at 1st line pos position
	else
		pos = 0xC0 | (column-1);			//set cursor at 2nd line pos position
	sendCommand(pos);
	display(str);
}
////////////////////////////////////////////////////////////////////////
