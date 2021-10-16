/*
 *  module : Temp sensor
 *  file : source file for temp sensor
 *  description : source file for temp driver (EXternal Driver)using ADC.
 *  Auth : Karim Mohamed Amin
 */
#include"lm35_sensor.h"
#include "ADC.h"

/*                         Definitions                        */
/*
 * Function description:
 * 1)invoke the read Function in ADC driver to get the digital value
 * 2)perform calculations to get the temperature
 */
uint8 LM35_GetTemperature(void){
	uint8 temp_value;
	uint16 read_value;
	read_value = ADC_readChannel(SENSOR_CHANNEL_ID);
	temp_value = ((uint32)read_value * MAX_SENSOR_TEMP * ADC_REFRENCE_VOLT)/(MAX_SENSOR_VOLTAGE *ADC_MAX_VALUE);
	return temp_value;
}
