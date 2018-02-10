/*
 * epsilometer_init_gpio.c
 *
 *  Created on: Jan 13, 2017
 *      Author: aleboyer
 */


#include "ep_GPIO_init.h"
#include "ep_analog.h"

/******************************************************************************
 * @name init_GPIO
 * @brief
 *   Switch on some GPIO
 * @details
 * Switch on the parts of MADRE, mainly the ADC
 *
 * @Author A. Le Boyer
 *****************************************************************************/

void init_GPIO(void) {

/*  GPIO_PinModeSet(gpioPortE, 13, gpioModePushPull, 1); // Enable Analog power
	GPIO_PinModeSet(gpioPortF, 3, gpioModePushPull, 1); // Enable 485 Driver
	GPIO_PinModeSet(gpioPortF, 4, gpioModePushPull, 0); // Enable 485 Receiver power
	GPIO_PinModeSet(gpioPortF, 5, gpioModePushPull, 1); // Enable 485 Transmitter
	GPIO_PinModeSet(gpioPortA, 2, gpioModePushPull, 1); // PA2 in output mode to send the MCLOCK  to ADC
	GPIO_PinModeSet(gpioPortA, 12, gpioModePushPull, 1); // put the voltage regulator to high
	GPIO_PinModeSet(gpioPortB, 7, gpioModePushPull, 1);   // PB7 in output mode to send the SYNC away
	GPIO_PinModeSet(gpioPortE, 12, gpioModePushPull, 1); // SD EN	K
*/

// new GPIO
	GPIO_PinModeSet(gpioPortE, 8, gpioModePushPull, 1); 	// Enable isolated Analog Power (SN6505A)
	GPIO_PinModeSet(gpioPortA, 5, gpioModePushPull, 0); 	// ADP5302 PS_EN Hi
	GPIO_PinModeSet(gpioPortA, 4, gpioModePushPull, 0); 	// ADP5302 PS_STOP Lo
	GPIO_PinModeSet(gpioPortA, 12, gpioModePushPull, 0); 	// ADP5302 PS_SYNC Hi (PWM 500mA Hi Current Mode)
	GPIO_PinModeSet(gpioPortA, 3, gpioModeInput, 0); 		// ADP5302 PS_VINOK Hi
	GPIO_PinModeSet(gpioPortC, 4, gpioModeInput, 1); 		// Reed Switch
	GPIO_PinModeSet(gpioPortB, 11, gpioModePushPull, 1); 	// 40MHz oscillator Enable

	GPIO_PinModeSet(gpioPortF, 4, gpioModePushPull, 0); 	// Enable 485 Receiver
	GPIO_PinModeSet(gpioPortF, 5, gpioModePushPull, 1); 	// Enable 485 Transmitter
	GPIO_PinModeSet(gpioPortF, 3, gpioModePushPull, 1); 	// Enable 485 Driver

	GPIO_PinModeSet(gpioPortD, 7, gpioModePushPull, 1);     // TX USART1
	GPIO_PinModeSet(gpioPortD, 6, gpioModeInput, 0);        // RX USART1

	GPIO_PinModeSet(gpioPortD,5,gpioModeInputPull,1);       // RX2 for the LEUART
	GPIO_PinModeSet(gpioPortD,4,gpioModePushPull,1);        // TX2 for the LEUART



	GPIO_PinModeSet(gpioPortE, 12, gpioModeInput, 0); 		// RX2 Input
	GPIO_PinModeSet(gpioPortE, 13, gpioModePushPull, 0); 	// TX2 Output
	//GPIO_PinModeSet(gpioPortD, 5, gpioModeInput, 0); 	    // RX2 Input
	//GPIO_PinModeSet(gpioPortD, 4, gpioModePushPull, 0); 	// TX2 Output

	GPIO_PinModeSet(gpioPortA, 2, gpioModePushPull, 1); 	// PA2 in output mode to send the MCLK  to ADC
	GPIO_PinModeSet(gpioPortE, 10, gpioModePushPull, 0);   	// SYNC signal from TIM1_CC0 ported to PE10

	GPIO_PinModeSet(gpioPortE, 11, gpioModePushPull, 0); 	// MicroSD Card Enable Active Low
	GPIO_PinModeSet(gpioPortD, 2, gpioModePushPull, 0); 	// AUX232_/EN Auxiliary RS232
	GPIO_PinModeSet(gpioPortF, 5, gpioModePushPull, 0); 	// STRN PROG EN, RS422 Power
	GPIO_PinModeSet(gpioPortE, 14, gpioModeInput, 0); 		// PE14 Fault logic input


// end new GPIO





	GPIO_PinModeSet(gpioPortC, 13, gpioModePushPull, 1); // and the ADA2200 amp or conductivity sensor
    for (int i=0;i<8;i++){
    	AD7124_ChipSelect(sensors[i], LHI); // bring them all high
    }
}
