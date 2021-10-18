/*
 * dc_motor.h
 *
 *   Created on: Oct 17, 2021
 *       Author: Kyrillos
 *  Description: this driver for sigle motor controled by system
 *  			 and share the motor state over the software scope
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "pwm.h"
#include "gpio.h"
#include "avr/io.h"

/****************************************************
 *				Types deceleration					*
 ****************************************************/
typedef enum{
	 DC_MOTOR_CW,
	 DC_MOTOR_A_CW,
	 DC_MOTOR_STOP
}DcMotor_State;
/*--------------------------------------------------*/

/****************************************************
 *  		Module macros configuration	         	*
 ****************************************************/
#define DC_MOTOR_PORT_ID PORTD_ID
#define DC_MOTOR_PIN_IN1 PIN3
#define DC_MOTOR_PIN_IN2 PIN4
/*--------------------------------------------------*/

/****************************************************
 *  			Module macros constants	         	*
 ****************************************************/
#define OFF 0u
/*--------------------------------------------------*/

/****************************************************
 *  			Module global variable	         	*
 ****************************************************/
extern volatile char* g_DC_MOTOR_state_ptr;
/*--------------------------------------------------*/

/****************************************************
 *				Functions deceleration				*
 ****************************************************/
void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);
/*--------------------------------------------------*/
#endif /* DC_MOTOR_H_ */
