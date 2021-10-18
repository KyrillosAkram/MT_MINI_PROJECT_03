/*
 * pwm.c
 *
 *  Created on: Oct 17, 2021
 *      Author: Kyrillos
 */
#include "pwm.h"
#include "avr/io.h"

/*
 * Description :
 * 		initialize Timer 0 and output compare unit on the fly to
 * 		get PWM on OC0 with feeded duty cycle
 * Args:
 * 		In:
 * 			uint8 duty_cycle:
 *
 * 				* the precentage value of the desired duty cycle
 *
 * 				* the type of unsigned intger of 1 byte
 * */
void PWM_Timer0_Start(uint8 duty_cycle){
	OCR0=((uint8)(((uint32)(duty_cycle*255))/100));
	TCCR0|=
			(1<<WGM01)|(1<<WGM00)|
			(1<<COM01)|
			(1<<CS01);
}
