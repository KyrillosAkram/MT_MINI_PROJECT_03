/*
 * pwm.h
 *
 *  Created on: Oct 17, 2021
 *      Author: Kyrillos
 */

#ifndef PWM_H_
#define PWM_H_
#include "gpio.h"

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
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
