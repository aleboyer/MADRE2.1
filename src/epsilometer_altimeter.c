/*
 * epsilometer_altimeter.c
 *
 *  Created on: Jun 11, 2018
 *      Author: aleboyer
 */

#include "ep_altimeter.h"



void send_ping(){
	alti_count++;
	if (alti_count %500000==0){
	GPIO_PinModeSet(gpioPortE, 14, gpioModePushPull, 1); 	//
	GPIO_PinModeSet(gpioPortE, 14, gpioModePushPull, 0); 	//
	}
}
