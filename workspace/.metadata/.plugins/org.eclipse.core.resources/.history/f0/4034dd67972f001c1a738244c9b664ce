/*
 * TODO documenting adc.h
 *
 *  Created on: Oct 16, 2021
 *      Author: Kyrillos
 */

#ifndef ADC_H_
#define ADC_H_

#include "common_macros.h"
#include "std_types.h"
#include "gpio.h"
#include <avr/io.h>
/****************************************************
 *				Types deceleration					*
 ****************************************************/
typedef enum{
	ADC_SELECT_ADC0,
	ADC_SELECT_ADC1,
	ADC_SELECT_ADC2,
	ADC_SELECT_ADC3,
	ADC_SELECT_ADC4,
	ADC_SELECT_ADC5,
	ADC_SELECT_ADC6,
	ADC_SELECT_ADC7
	/*TODO complete all options*/
}ADC_OptionType;

typedef enum{
	ADC_CHANEL0,
	ADC_CHANEL1,
	ADC_CHANEL2,
	ADC_CHANEL3,
	ADC_CHANEL4,
	ADC_CHANEL5,
	ADC_CHANEL6,
	ADC_CHANEL7
}ADC_ChannelType;


typedef enum{
	ADC_DEFAULT_DIVISION_2 ,
	ADC_DEFAULT_PRESCALER =0,
	ADC_FACTOR_2,
	ADC_FACTOR_4,
	ADC_FACTOR_8,
	ADC_FACTOR_16,
	ADC_FACTOR_32,
	ADC_FACTOR_64,
	ADC_FACTOR_128
}ADC_ClockDivisionType;

typedef enum{
	ADC_USE_AREF,
	ADC_USE_AVCC,
	ADC_USE_INTERNAL_2_56V=3
}ADC_ReferenceType;
/*--------------------------------------------------*/



/****************************************************
 *  			Module macros constants	         	*
 ****************************************************/
#define ADC_MAX_VALUE (1023)
#define ADC_MIN_VALUE (0)
#define ADC_REF_VALUE_X10 (50)

/*--------------------------------------------------*/


/****************************************************
 *  		Module macros configuration	         	*
 ****************************************************/
/*
 * usage : depend on modifing sources implementation
 */
#define ADC_INTERRUPT FALSE
/*--------------------------------------------------*/


/****************************************************
 *  			Module macro functions	         	*
 ****************************************************/
#define ADC_WAIT_CONVERSION() while((ADCSRA>>ADSC));
/*--------------------------------------------------*/


/****************************************************
 *  			Module global variable	         	*
 ****************************************************/
extern volatile uint16 g_adcLastRead;
/*--------------------------------------------------*/


/****************************************************
 *				Functions deceleration				*
 ****************************************************/
void ADC_init();
void ADC_readChannel(ADC_ChannelType a_channel_num);
void ADC_startConversion(ADC_ChannelType a_channel_num);

/*--------------------------------------------------*/




#endif /* ADC_H_ */
