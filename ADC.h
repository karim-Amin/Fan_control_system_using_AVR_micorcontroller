 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: the header file for ADC driver
 *
 * Author: Karim Mohamed
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_
#include"std_types.h"

/********************************************************************************
 * 								 Definitions									*
 **********************************************************************************/
#define ADC_MAX_VALUE 1023
#define ADC_REFRENCE_VOLT 2.56
/********************************************************************************
 * 								 Type Definitions									*
 **********************************************************************************/
typedef enum{
	AREF_refrence,AVCC_refrence,internal_refrence=3
}ADC_refrenceVolt;

typedef enum{
	prescalar_2,prescalar_4,prescalar_8,prescalar_16,prescalar_32,prescalar_64,prescalar_128
}ADC_prescaler;

typedef struct{
	ADC_refrenceVolt refrence;
	ADC_prescaler prescaler;
}ADC_configType;
/********************************************************************************
 * 								 Prototypes									*
 **********************************************************************************/
void ADC_init(const ADC_configType* config_ptr);
uint16 ADC_readChannel(uint8 channelNum);
#endif /* ADC_H_ */
