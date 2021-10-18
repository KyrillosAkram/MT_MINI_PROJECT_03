 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/****************************************************
 *				Types deceleration					*
 ****************************************************/

typedef enum{
	ADC_REF_AREF,
	ADC_REF_AVCC,
	ADC_REF_INTERNAL_2_56V=3
}ADC_ReferenceVolatge;

typedef enum{
	ADC_DEFAULT_DIVISION_2 ,
	ADC_DEFAULT_PRESCALER =0,
	ADC_FACTOR_2,
	ADC_FACTOR_4,
	ADC_FACTOR_8,
	ADC_FACTOR_16,
	ADC_FACTOR_32,
	ADC_FACTOR_64,
	ADC_FACTOR_128,
	ADC_PRESCALER_2=1,
	ADC_PRESCALER_4,
	ADC_PRESCALER_8,
	ADC_PRESCALER_16,
	ADC_PRESCALER_32,
	ADC_PRESCALER_64,
	ADC_PRESCALER_128
}ADC_Prescaler;

typedef struct{
 ADC_ReferenceVolatge ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;

/*--------------------------------------------------*/


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern Public global variables to be used by other modules */
extern volatile uint16 g_adcResult;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
void ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
