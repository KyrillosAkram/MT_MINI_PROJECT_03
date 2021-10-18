/*
 * dc_motor.h
 *
 *  Created on: Oct 17, 2021
 *      Author: Kyrillos
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "pwm.h"
#include "gpio.h"
#include "avr/io.h"

typedef enum{
	 DC_MOTOR_CW,
	 DC_MOTOR_A_CW,
	 DC_MOTOR_STOP
}DcMotor_State;

#define DC_MOTOR_PORT_ID PORTD_ID
#define DC_MOTOR_PIN_IN1 PIN3
#define DC_MOTOR_PIN_IN2 PIN4
#define OFF 0u

void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state,uint8 speed);



#endif /* DC_MOTOR_H_ */
