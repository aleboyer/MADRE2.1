/*
 * epilometer_sampling.c
 *
 *  Created on: Apr 24, 2017
 *      Author: aleboyer
 */


#include "ep_sampling.h"
#include "efm32wg_uart.h"
#include "em_rtc.h"

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
	//RTC->CNT*32768
	switch(sd_state){
		case WriteHeader:
			err_write=0;
			writeSD_header(header_buffer,header_length);
			sd_state=WriteMap;
			if (madre_setup_ptr->AUX_flag>0){sd_state=WriteAux1;}
			break;
		case WriteAux1:
		  	writeSD_aux(aux1_buffer,aux1_buffer_length);
			sd_state=WriteMap;
			if (madre_setup_ptr->AUX_flag>1){sd_state=WriteAux2;}
			break;
		case WriteAux2:
		  	writeSD_aux(aux2_buffer,aux2_buffer_length);
			sd_state=WriteMap;
			break;
		case WriteMap:
		  	writeSD();
			sd_block++;
			sd_state=Wait;
			if (tx_state==Stop){
				init_aux_block();
			}
			err_sync=f_sync(&fsrc);
			//err_write=0;
			break;
	}
	if (err_sync!=0){
		MICROSD_Deinit();
		while(err_sync!=0){
			initSD();
		}
	}
	if ((sd_block%7200==0) & (flag_SDfile==0)){
		MICROSD_Deinit();
		initSD();
	}
	if ((sd_block%7200>0) & (flag_SDfile==1)){
		flag_SDfile=0;
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

void poll_RX(void){

	// quick check if the RX buffer empty
	//uint16_t rxData = USART_RxDouble(USART1);
	uint16_t rxData = 0;
	if((USART1->STATUS & USART_STATUS_RXFULL)){
		rxData = USART_RxDouble(USART1);
		USART1->CMD =(USART1->CMD & ~_USART_CMD_CLEARRX_MASK)|USART_CMD_CLEARRX;

		if (rxData==0x7171){
			LEUART_IntDisable(LEUART0, LEUART_IEN_SIGF);
			USART_IntDisable(USART1, USART_IEN_TXBL);
			DMA_IntDisable(DMA_IEN_CH0DONE);
			MICROSD_Deinit();
		    f_close(&fsrc);
			AD7124_StopConversion();
		    madre_state=Menu;
		    tx_state=SetUp;sd_state=Wait;
	    }
	}
}



