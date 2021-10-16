 /******************************************************************************
 *
 * Module: The main application
 *
 * File Name: app.c
 *
 * Description: The entry point to the application includes the main function
 *
 * Author: Karim Mohamed
 *
 *******************************************************************************/
#include"LCD.h"
#include"motor.h"
#include"lm35_sensor.h"
#include"ADC.h"
#include"util/delay.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ZERO_SPEED 0
#define DUTY_PERCENT_25 25
#define DUTY_PERCENT_50 50
#define DUTY_PERCENT_75 75
#define DUTY_PERCENT_100 100
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void APP_displayFanState(DcMotor_State a_state);
void APP_displayTemp(uint8 a_temp);
void APP_checkTemp_controlFan(uint8 a_temp);
/*
 * Global variables
 */

/*To hold the status of the fan in our system*/
	DcMotor_State fan_state ;
/*The entry Function For the application*/
int main(void){
	/*variable to hold the value of the temperature sensor*/
	uint8 temp;

	/*to adjust and configure the ADC driver*/
	ADC_configType ADC_config = {internal_refrence,prescalar_8};

	/* i will not enable the global interrupt as there are no modules implemented using
	 * interrupt design
	 */

	/*calling the initialisation functions for the drivers we use*/
	/*passing the configuration structure by address to avoid duplicate memory */
	ADC_init(&ADC_config);
	LCD_init();
	DcMotor_init();
	/*To display in the middle of the LCD*/
	LCD_moveCursor(0,4);
	/*at first the fan will be off */
	LCD_displayString((uint8*)"Fan is OFF");/*i will overwrite off at column number 11*/
	/*Move the cursor in the second line and at the same column*/
	LCD_moveCursor(1,4);
	/*this is used to show the value of the Temperature*/
	LCD_displayString((uint8*)"Temp =     ");
	while(1){
		/*read the temperature and store to check the value*/
		temp = LM35_GetTemperature();
		/*perform some conditions and update the state of the fan*/
		APP_checkTemp_controlFan(temp);
		/*To display the status of our fan*/
		APP_displayFanState(fan_state);
		/*To display the temperature we read from the analog sensor */
		APP_displayTemp(temp);
	}
	return 0;
}
/*
 * Description:
 *
 */
void APP_displayFanState(DcMotor_State a_state){
	if(a_state == clock_wise){
		LCD_displayStringRowColumn(0,11,"ON ");
	}else{
		LCD_displayStringRowColumn(0,11,"OFF");
	}
}
/*
 * Description:
 *
 */
void APP_displayTemp(uint8 a_temp){
	LCD_moveCursor(1,11);
	if(a_temp<100){
		LCD_intgerToString(a_temp);
		LCD_displayString(" C ");
	}else{
		LCD_intgerToString(a_temp);
	}
}
/*
 * Description:
 *
 */
void APP_checkTemp_controlFan(uint8 a_temp){
	/*assume that the state will be ON*/
		fan_state = clock_wise;
	/*if the temperature is less than 30 C there is no need to the fan*/
		if(a_temp<30){
			/*Turn off the fan*/
			fan_state = stop_motor;
			/*order the motor to stop*/
			DcMotor_Rotate(fan_state,ZERO_SPEED);
		}else if(a_temp>=30 && a_temp<60){
			DcMotor_Rotate(fan_state,DUTY_PERCENT_25);
		}else if(a_temp>=60 && a_temp<90){
			DcMotor_Rotate(fan_state,DUTY_PERCENT_50);
		}else if(a_temp>=90 && a_temp<120){
			DcMotor_Rotate(fan_state,DUTY_PERCENT_75);
		}else{/*if the temperature is greater than 120*/
			DcMotor_Rotate(fan_state,DUTY_PERCENT_100);
		}
}
