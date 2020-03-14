/* Embedded C Program to interface 4x4 keypad with Atmega32
 * Created: 27-Nov-19 11:18:55 AM
 * Author : Rutuparn Pawar
 */
///////////////////////////////////////////////////////////////////////////////////
//Use below code for testing
// Note: Do not forget to include LCD library

#define F_CPU 8000000UL //Operating Frequency = 8MHz
#include <avr/io.h>
#include <util/delay.h>

#include "LCD.h"
#include "Keypad.h"

#define Data_Port PORTC
#define Command_Port PORTD

///////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	initLCD();
	sendCommand(0x80);
	display("Rutuparn Pawar");
	sendCommand(0xc0);
	display("Roll No:");
	
	int key = 0; //Counter for number of entered characters on keypad
	
	while(1)
	{
		sendData(scanKeyboard());
		key++;
		if (key==16)
		{
			sendCommand(0x01); 			//Clear lcd
			display("PRESS ANY KEY");
			sendCommand(0xC0);
			key=0;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////