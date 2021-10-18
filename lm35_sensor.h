 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: header file for the LM35 Temperature Sensor driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"
#include "adc.h"
#include "gpio.h"
/*******************************************************************************
 *                               Definitions                                   *
 *******************************************************************************/
#define SENSOR_PORT_ID			  PORTA_ID
#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150


/*******************************************************************************
 *                          Shared global variables                            *
 *******************************************************************************/
extern const ADC_ConfigType g_LM35_ADC_Config;



/*******************************************************************************
 *                           Functions Prototypes                              *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
void LM35_init(void);
uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */
