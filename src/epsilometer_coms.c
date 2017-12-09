/*
 * proto Epsilometer_coms.c
 *
 *  Created on: May 24, 2016
 *      Author: leumas64
 */

#include "ep_coms.h"
#include "ep_common.h"
#include "em_usart.h"
#include "em_cmu.h"
#include "efm32wg_uart.h"



/******************************************************************************
 * @name UART_Setup
 * @brief
 *  set up the communication with the RS232
 * @details
 *	enable USART1 clock
 *	switch on the TX and RX GPIO
 *	configure USART1: baudrate ....
 *	set up an interrupt to TX the data
 *	lower the priority of the interrupt so it is lower than tha sampling interrupt
 *
 * @Author A. Le Boyer
 *****************************************************************************/

void UART_Setup() {
	/*UART1 shit*/
	CMU_ClockEnable(cmuClock_USART1, true); // Enable clock for USART1 module
	GPIO_PinModeSet(gpioPortD, 7, gpioModePushPull, 1); // TX
	GPIO_PinModeSet(gpioPortD, 6, gpioModeInput, 0); // RX

	USART_InitAsync_TypeDef usartInitUSART1 = {
		.enable = usartDisable, 					// Initially disabled
		.refFreq = 0,								// configured reference frequency
		.baudrate = madre_setup_ptr->usart_baudrate, 				    // Baud rate defined in common.h
		.oversampling = usartOVS16, 				// overSampling rate x16
		.databits = USART_FRAME_DATABITS_EIGHT, 	// 8-bit frames
		.parity = USART_FRAME_PARITY_NONE,			// parity - none
		.stopbits = USART_FRAME_STOPBITS_ONE,		// 1 stop bit
	};

	/*Initialize UART registers*/
	USART_InitAsync(USART1, &usartInitUSART1);

	USART1 -> ROUTE = USART_ROUTE_RXPEN | USART_ROUTE_TXPEN
			| USART_ROUTE_LOCATION_LOC2;

	/* Inform NVIC of IRQ changes*/
	NVIC_ClearPendingIRQ(USART1_TX_IRQn);
	NVIC_SetPriority(USART1_TX_IRQn, 2);
	NVIC_EnableIRQ(USART1_TX_IRQn);

	tx_state=SetUp;

	USART_Enable(USART1, usartEnable);
	//USART_IntEnable(USART1, USART_IEN_TXBL);
}


/******************************************************************************
 * @name UART_Setup
 * @brief
 *  send 3 bytes through TX
 * @details
 *	send 3 bytes block when TX buffer (2 bytes for 2 FIFO level + 1 bytes for shift register)
 *
 * @Author A. Le Boyer
 *****************************************************************************/

void USART1_TX_IRQHandler(void)
{
	uint32_t dataLen;
	USART_IntDisable(USART1, USART_IEN_TXBL);

	switch (tx_state){
		case TransmitHeader:
			dataLen    = header_length-header_bytes_sent;
			if (header_bytes_sent==0){//first time we enter the interrupt, build the header
				sprintf(header_buffer,"\r\n$MADRE%8x,%8x,%8x,%8x,%8x,%8x\r\n",(int) epsi_stamp_block      \
																	     ,(int) RTC->CNT                  \
																	     ,(int) voltage                   \
																         ,(int) chcksum_aux1_header       \
																         ,(int) chcksum_aux2_header       \
																         ,(int) chcksum_block_header);
			}
			if(dataLen ==0){
				tx_state=TransmitMap;
				header_bytes_sent=0;
				if (madre_setup_ptr->AUX_flag>0){tx_state=TransmitAux1;}
			}
			else{
				header_bytes_sent=sendblock(dataLen, header_buffer, header_bytes_sent);
			}
			USART_IntEnable(USART1, USART_IEN_TXBL);
			break;

		case TransmitAux1:
			dataLen         = aux1_buffer_length-aux1_bytes_sent;
			if(aux1_bytes_sent==0){

			}
			if(dataLen ==0){
				tx_state=TransmitMap;
				if (madre_setup_ptr->AUX_flag>1){tx_state=TransmitAux2;}
			}
			else{
				aux1_bytes_sent = sendblock(dataLen, aux1_buffer, aux1_bytes_sent);
			}
			USART_IntEnable(USART1, USART_IEN_TXBL);
			break;
		case TransmitAux2:
			dataLen    = aux2_buffer_length-aux2_bytes_sent;
			aux2_bytes_sent = sendblock(dataLen, aux2_buffer, aux2_bytes_sent);
			tx_state=TransmitMap;
			USART_IntEnable(USART1, USART_IEN_TXBL);
			break;
		case TransmitMap:
			dataLen    = bytes_per_block-map_bytes_sent;
			if(map_bytes_sent==0){
				for(int i=0;i<5;i++){
					USART_Tx(USART1, mapheader[i]);
				}
			}
			map_bytes_sent= sendblock(dataLen,(char *) data_buffer, map_bytes_sent);
			tx_state=TransmitMap;
			if (dataLen==0){tx_state=Stop;}
			else{USART_IntEnable(USART1, USART_IEN_TXBL);}
			break;
	}
}  //end of handler



/******************************************************************************
 * @name send_sdupdate
 * @brief
 *  send nb of samples saved
 * @details
 *
 *
 * @Author A. Le Boyer
 *****************************************************************************/

uint32_t sendblock(uint32_t dataLen,char * Buffer, uint32_t bytes_sent)
{
	switch (dataLen){
	case 0:
		bytes_sent=0;
		break;
	case 1:
		USART_Tx(USART1, Buffer[ bytes_sent]);
		 bytes_sent++;
		break;
	default:
		for(int i=0;i<2;i++){
			/* Transmit pending character */
			USART_Tx(USART1, Buffer[ bytes_sent]);
			 bytes_sent++;
		} //end of for
		break;
	}//end of switch
	return bytes_sent;

}



/*	if ((tx_state==TransmitHeader) & (aux1_bytes_sent==0)){

		//dataLen    = strlen(SBEbuf)-SBEbytes_sent;

	}
	if ((TXState==Transmit) & (SBE_TX_sent==1)){

		//dataLen    = pendingSamples*byte_per_sample-tx_bytes_sent;
		dataLen    = TX_pendingSamples - tx_bytes_sent;
		uint32_t count  = tx_bytes_sent % buffer_size;

		switch (dataLen){
		case 0:
			count1 = tx_block_size-sample_per_block;
			switch (count1){
			case 2:
				USART_Tx(USART1, '\r');
				USART_Tx(USART1, '\n');
				sample_per_block+=2;
				break;
			case 0:
				break;
			default:
				USART_Tx(USART1, 0x21);
				sample_per_block++;
				USART_IntEnable(USART1, USART_IEN_TXBL);
				break;
			}
			break;
		case 1:
			USART_Tx(USART1, dataBuffer[count]);
			tx_bytes_sent++;
			USART_IntEnable(USART1, USART_IEN_TXBL);
			break;
		default:
			for(int i=0;i<2;i++){
				// Transmit pending character
				USART_Tx(USART1, dataBuffer[count+i]);
			}
			tx_bytes_sent+=2;
			USART_IntEnable(USART1, USART_IEN_TXBL);
			break;
		}
	}

}*/






