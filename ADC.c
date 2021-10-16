 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ADC driver
 *
 * Author: Karim Mohamed
 *
 *******************************************************************************/
#include"ADC.h"
#include"common_macros.h"
#include<avr/io.h>

/*
 * description :
 * 	to initialise the ADC module and adjust the ADC Channel number
 */
void ADC_init(const ADC_configType* config_ptr){
	ADMUX = (ADMUX & 0x3F) | ((config_ptr->refrence)<<6);/*insert the reference volt*/
	CLEAR_BIT(ADMUX,ADLAR);/*to adjust the data in low section in ADC data register*/
	SET_BIT(ADCSRA,ADEN);/*to enable ADC module*/
	CLEAR_BIT(ADCSRA,ADIE);/*disable the ADC interrupt*/
	ADCSRA = (ADCSRA & 0xF8) |((config_ptr->prescaler));/*insert the prescaler select bits*/
}


/*
 * description :
 * 	this function will tell the ADC start conversion and wait till we get the result
 * 	it selects which channel will be read
 */
uint16 ADC_readChannel(uint8 channelNum)
{
	ADMUX = (channelNum & 0x07)  | (ADMUX & 0xE0);/* insert the channle number in the first five bits*/
	SET_BIT(ADCSRA,ADSC);/* start conversion*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF));/*polling design wait till finish conversion*/
	SET_BIT(ADCSRA,ADIF);
	return ADC;/*return the ADC Data register which is converted*/
}
