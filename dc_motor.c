/*
 * dc_motor.c
 *
 *  Created on: Oct 17, 2021
 *      Author: Kyrillos
 */


#include "dc_motor.h"

void DcMotor_Init(void){
	GPIO_setupPinDirection(PORTB_ID,PIN3,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN1,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN2,PIN_OUTPUT);
	PWM_Timer0_Start(OFF);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	PWM_Timer0_Start(speed);
	if(!speed)state=DC_MOTOR_STOP;
	switch (state) {
		case DC_MOTOR_CW:
			GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN1,LOGIC_HIGH);
			GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN2,LOGIC_LOW );
			break;
		case DC_MOTOR_A_CW:
			GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN1,LOGIC_LOW );
			GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN2,LOGIC_HIGH);
			break;
		case DC_MOTOR_STOP:
			GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN1,LOGIC_LOW );
			GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN_IN2,LOGIC_LOW );
			break;

	}
}

