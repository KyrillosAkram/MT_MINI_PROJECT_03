/*
 * pwm.c
 *
 *  Created on: Oct 17, 2021
 *      Author: Kyrillos
 */
#include "pwm.h"
#include "avr/io.h"
/*

void PWM_Timer0_init(){
	TCCR0|=
			(1<<WGM01)|(1<<WGM00)|
			(1<<COM01)|
			(1<<CS01);
}
*/

void PWM_Timer0_Start(uint8 duty_cycle){
	OCR0=((uint8)(((uint32)(duty_cycle*255))/100));
	TCCR0|=
			(1<<WGM01)|(1<<WGM00)|
			(1<<COM01)|
			(1<<CS01);
}
