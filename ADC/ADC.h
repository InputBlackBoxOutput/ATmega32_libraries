/* Embedded C program to get data from ADC of Atmega32
 * Created: 20-Nov-19 11:27:15 AM
 * Author : Rutuparn Pawar
 */ 


#ifndef ADC_H
#define ADC_H

// Function to initialize ADC
void initADC(void);

// Function to get value from specific ADC channel
int ReadADC(char channel);

#endif