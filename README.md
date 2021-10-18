# Fan_control_system_using_AVR_micorcontroller
this project is implemented by software layered concept to abstract the microcontroller , hardware and application layers.
by using analog temperature sensor we convert the temperature to corresponding voltage based on this reading we use PWM driver to control the speed of our motor
# project description
The aim of this project is to design a temperature-controlled fan using ATmega16<br />
microcontroller, in which the fan is automatically turned ON or OFF according to the <br />
temperature. Use ATmega16 Microcontroller with frequency 1Mhz.<br />
- the LM35 temperature sensor will give continuous analog output <br />
corresponding to the temperature sensed by it. This analog signal is given to the ADC, 
which converts the analog values to digital values.
-  In order to get the temperature from the sensed analog voltage, we need to perform some 
calculations in the programming for the microcontroller.<br />
- Once the calculations are done by the microcontroller according to the logic, the 
temperature is displayed on the LCD. <br />
- The microcontroller will continuously monitor the temperature and based on the 
temperature value, the microcontroller will drive the fan like that:
a. If the temperature is less than 30C turn off the fan.<br />
b. If the temperature is greater than or equal 30C turn on the fan with 25% of its 
maximum speed.<br />
c. If the temperature is greater than or equal 60C turn on the fan with 50% of its 
maximum speed.<br />
d. If the temperature is greater than or equal 90C turn on the fan with 75% of its 
maximum speed.<br />
e. If the temperature is greater than or equal 120C turn on the fan with 100% of its 
maximum speed.<br />
- The main principle of the circuit is to switch on/off the fan connected to DC motor based 
on temperature value. The DC-Motor rotates in clock-wise direction or stopped based on 
the fan state.
https://user-images.githubusercontent.com/73777263/137814805-f1db1926-00f3-4357-a11e-be74f24a40a5.mp4

