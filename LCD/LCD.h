/* Embedded C program to interface 16x2 LCD (in 8 bit mode) with ATmega32
 * Created: 13-Nov-19 10:36:07 AM
 * Author : Rutuparn Pawar
 */ 

#ifndef LCD_H
#define LCD_H

// Change these according to connections
#define commandPort     PORTD
#define DDR_CommandPort DDRD
#define EN  5
#define RW  6
#define RS  7

#define dataPort        PORTC 	 
#define DDR_DataPort    DDRC

void initLCD(void);
void sendCommand(unsigned char command);
void sendData(unsigned char data);

void display(char *str);
void displayAtPosition(int row, int column, char* str);

#endif //LCD_H