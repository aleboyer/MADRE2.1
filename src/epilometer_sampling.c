/*
 * epilometer_sampling.c
 *
 *  Created on: Apr 24, 2017
 *      Author: aleboyer
 */


#include "ep_sampling.h"
#include "efm32wg_uart.h"

// for rtc purpose
volatile bool doTemperatureCompensation = true;         // Flags that signal when to do temperature compensation

/******************************************************************************
 * @name MADRE_Sampling
 * @brief
 *   during the sampling we send the data on the SD card. the actual sampling is inside the interrupt c.f analog.c
 * @details
 *	start to send data after 160 sample are available
 *	send a block of 80 sample  1/8 second
 *	once 100 block (every 12.5 second) we sync the sd card which actually right in the file
 *	check if temperature is needed for the rtc
 *
 * @Author A. Le Boyer
 *****************************************************************************/

void MADRE_Sampling(void) {

	switch(sd_state){
		case WriteHeader:
			writeSD_header(header_buffer,header_length);
			sd_state=WriteMap;
			if (madre_setup_ptr->AUX_flag>0){sd_state=TransmitAux1;}
			break;
		case WriteAux1:
		  	writeSD_aux(aux1_buffer,aux1_buffer_length);
			sd_state=WriteMap;
			if (madre_setup_ptr->AUX_flag>1){sd_state=TransmitAux2;}
			break;
		case WriteAux2:
		  	writeSD_aux(aux2_buffer,aux2_buffer_length);
			sd_state=WriteMap;
			break;
		case WriteMap:
		  	writeSD();
			sd_block++;
			sd_state=Wait;
			f_sync(&fsrc);
			break;
	}

	if (doTemperatureCompensation)	// Perform temperature compensation
  	{
  	    doTemperatureCompensation = false;  // Clear doTemperatureCompensation flag
  	    clockDoTemperatureCompensation();
  	  }
}

/******************************************************************************
 * @name poll_RX
 * @brief
 *   check if a user is trying to talk to the board
 * @details
 *	read the RX buffer
 *
 * @Author A. Le Boyer
 *****************************************************************************/

/*enum madre_states poll_RX(void){

	// quick check if the RX buffer empty
	//uint16_t rxData = USART_RxDouble(USART1);
	uint16_t rxData = 0;
	if((USART1->STATUS & USART_STATUS_RXDATAV)){
		rxData = USART_RxDouble(USART1);
		USART1->CMD =(USART1->CMD & ~_USART_CMD_CLEARRX_MASK)|USART_CMD_CLEARRX;

		if (rxData==0x1e1e){
			LEUART_IntDisable(LEUART0, LEUART_IEN_SIGF);
			USART_IntDisable(USART1, USART_IEN_TXBL);
			DMA_IntDisable(DMA_IEN_CH0DONE);
			AD7124_StopConversion();

		    GPIO_PinModeSet(gpioPortA, 13, gpioModePushPull, 1); //
		    madre_state=Menu;
		    tx_state=SetUp;sd_state=Wait;
		    GPIO_PinModeSet(gpioPortA, 13, gpioModePushPull, 0);
	    }
	}

	return madre_state;

}*/
