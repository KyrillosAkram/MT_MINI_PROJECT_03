/*
 * TODO documenting adc.c
 *
 *  Created on: Oct 16, 2021
 *      Author: Kyrillos
 */


#include "adc.h"

volatile g_adcLastRead=0;

ISR(ADC_vect){
	g_adcLastRead=ADC;
}

void ADC_init(){
	ADCSRA|=
			(ADC_DEFAULT_PRESCALER)|
			(1<<ADEN);
}

void ADC_readChannel(ADC_ChannelType a_channel_num){
	ADCSRA|=(1<<ADEN);		/*start reading proccess or conversion*/
	while((ADCSRA>>ADEN));	/*waits until the conversion to be finished*/
	g_adcLastRead=ADC;
}

