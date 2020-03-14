/* Embedded C Program to interface 4x4 keypad with Atmega32
 * Created: 27-Nov-19 11:18:55 AM
 * Author : Rutuparn Pawar
 */
///////////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>
#include <util/delay.h>

#include "Keypad.h"

///////////////////////////////////////////////////////////////////////////////////

#define KEY_PRT PORTA
#define KEY_DDR DDRA
#define KEY_PIN PINA
#define DEBOUNCE_TIME 200  //Debounce Delay Time

unsigned char keypad[4][4] ={{'0','1','2','3'},
	                         {'4','5','6','7'},
	                         {'8','9','A','B'},
	                         {'C','D','E','F'}};

unsigned char colloc, rowloc;		
/////////////////////////////////////////////////////////////////////////////////
char scanKeyboard()
{
	
	while(1)
	{
		KEY_DDR = 0xF0;
		KEY_PRT = 0xFF;
		do
		{
			KEY_PRT &= 0x0F;
			colloc = (KEY_PIN & 0x0F);
		}while(colloc != 0x0F);
		
		do
		{
			do
			{
				_delay_ms(DEBOUNCE_TIME);
				colloc = (KEY_PIN & 0x0F);
			}while(colloc == 0x0F);
			
			_delay_ms (DEBOUNCE_TIME);
			colloc = (KEY_PIN & 0x0F);

		}while(colloc == 0x0F);

		KEY_PRT = 0xEF; // check for pressed key in 4th row
		_delay_ms (20);
		colloc = (KEY_PIN & 0x0F);
		if(colloc != 0x0F)
		{
			rowloc = 0;
			break;
		}

		KEY_PRT = 0xDF; // check for pressed key in 2nd row
		_delay_ms (20);
		colloc = (KEY_PIN & 0x0F);
		if(colloc != 0x0F)
		{
			rowloc = 1;
			break;
		}

		KEY_PRT = 0xBF; // check for pressed key in 3rd row
		_delay_ms (20);
		colloc = (KEY_PIN & 0x0F);
		if(colloc != 0x0F)
		{
			rowloc = 2;
			break;
		}

		KEY_PRT = 0x7F; // check for pressed key in 4th row
		_delay_ms (20);
		colloc = (KEY_PIN & 0x0F);
		if(colloc != 0x0F)
		{
			rowloc = 3;
			break;
		}
	}
	
	if(colloc == 0x0E)
	return(keypad[rowloc][0]);
	else if(colloc == 0x0D)
	return(keypad[rowloc][1]);
	else if(colloc == 0x0B)
	return(keypad[rowloc][2]);
	else
	return(keypad[rowloc][3]);
	
}

/////////////////////////////////////////////////////////////////////////////////