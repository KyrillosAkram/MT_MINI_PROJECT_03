/*
 * main.c
 *
 *  Created on: Oct 17, 2021
 *      Author: Kyrillos
 * Description:
 */

/*Software dependences*/
#include "avr/interrupt.h"
#include "std_types.h"
#include "common_macros.h"
#include "util/delay.h"
#include <stdlib.h>

/*Hardware dependences*/
#include "lm35_sensor.h"
#include "lcd.h"
#include "dc_motor.h"

/* Buffers decleration for desplay and itoa */
char temp_string[5];
char fan_string[5];


void adjustFanSpeed(uint8 a_temp);
void LCD_update(void);

int main(){
/*	setup section	*/

	LCD_init();
	DcMotor_Init();
	LM35_init();
	sei();
	LCD_displayStringRowColumn(0,0,"    FAN is OFF");
	LCD_displayStringRowColumn(1,0,"    Temp = 0   C");

	/* local variable to cache the feed back for sensor */
	register uint8 temp;
/*------------------*/

/*super loop section*/

	loop_for_ever{
		/* implementation */
		temp=LM35_getTemperature();
		adjustFanSpeed(temp);
		itoa(temp,temp_string,10);
		LCD_update();
		_delay_ms(1000);

	}
/*------------------*/
}


void adjustFanSpeed(uint8 a_temp){
	if      (a_temp >=120) DcMotor_Rotate(DC_MOTOR_CW,100);
	else if (a_temp >=90 ) DcMotor_Rotate(DC_MOTOR_CW,75 );
	else if (a_temp >=60 ) DcMotor_Rotate(DC_MOTOR_CW,50 );
	else if (a_temp >=30 ) DcMotor_Rotate(DC_MOTOR_CW,25 );
	else if (a_temp < 30 ) DcMotor_Rotate(DC_MOTOR_CW,OFF);

}
void LCD_update(void){
	LCD_displayStringRowColumn(0,12,"  ");
	LCD_displayStringRowColumn(1,11,"   ");
	LCD_displayStringRowColumn(0,12,(const char*)g_DC_MOTOR_state_ptr);
	LCD_displayStringRowColumn(1,11,(const char*)temp_string);
}
