 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#include <util/delay.h> /* For the delay functions */
#include "lm35_sensor.h"
#include "gpio.h"

const ADC_ConfigType g_LM35_ADC_Config={
		ADC_REF_INTERNAL_2_56V,
		ADC_FACTOR_8
};

/*
 * Description :
 * Function responsible for preparing the required hardware specificlly ADC
 * feeding it with g_LM35_ADC_Config
 */
void LM35_init(void){
	GPIO_setupPinDirection(SENSOR_PORT_ID,SENSOR_CHANNEL_ID,PIN_INPUT);
	ADC_init(&g_LM35_ADC_Config);
}

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Make delay for some time until g_adcResult value is updated with the ADC interrupt */
	_delay_ms(5);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)g_adcResult*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}

