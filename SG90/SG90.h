/*C Program to interface SG90 servo motor with Atmega32
 * Created: 27-Nov-19 10:34:07 AM
 * Author : Rutuparn Pawar
 */ 

#ifndef SG90_H
#define SG90_H

//Change these as per connection
#define DDR_SERVO_PORT DDRB
#define SERVO_PORT     PORTB
#define SERVO          7     //Pin

// Note: Values adjusted to maintain signal integrity
#define PULSE_MIN_ANGLE   500
#define PULSE_MAX_ANGLE   2500

#define T_TOTAL 20000 
#define PULSES 100

void initServo(void);
void moveServo(int angle);

#endif