/*
 *  module : Temp sensor
 *  file : Header file for sensor
 *  description : header file for temp driver (EXternal Driver).
 *  Auth : Karim Mohamed Amin
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_
#include "std_types.h"
/*                           Definitions                           */
#define MAX_SENSOR_TEMP 150
#define MAX_SENSOR_VOLTAGE 1.5
#define SENSOR_CHANNEL_ID 2
/*                           Declaration                           */
uint8 LM35_GetTemperature(void);
#endif /* LM35_SENSOR_H_ */
