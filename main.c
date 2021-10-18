/*
 * main.c
 *
 *  Created on: Oct 17, 2021
 *      Author: Kyrillos
 */
//#include "avr/io.h"
#include "avr/interrupt.h"
#include "std_types.h"
#include "common_macros.h"
#include "lm35_sensor.h"
#include "lcd.h"
#include "dc_motor.h"
#include "util/delay.h"
#include <stdlib.h>
void adjustFanSpeed(uint8 a_temp);

int main(){
	/*	setup section	*/
	LCD_init();
	DcMotor_Init();
	LM35_init();
	char temp_string[5];
	char fan_string[5];
	uint8 temp;
	sei();
	/*------------------*/

	/*super loop section*/
	loop_for_ever{
		/* implementation */
		temp=LM35_getTemperature();
		adjustFanSpeed(temp);
		itoa(temp,temp_string,10);
		LCD_clearScreen();
		LCD_displayStringRowColumn(0,0,temp_string);
		_delay_ms(1000);

	}
	/*------------------*/
}


void adjustFanSpeed(uint8 a_temp){
	if      (a_temp < 30 ) DcMotor_Rotate(DC_MOTOR_CW,OFF);
	else if (a_temp >=30 ) DcMotor_Rotate(DC_MOTOR_CW,25 );
	else if (a_temp >=60 ) DcMotor_Rotate(DC_MOTOR_CW,50 );
	else if (a_temp >=90 ) DcMotor_Rotate(DC_MOTOR_CW,75 );
	else if (a_temp >=120) DcMotor_Rotate(DC_MOTOR_CW,100);

}
