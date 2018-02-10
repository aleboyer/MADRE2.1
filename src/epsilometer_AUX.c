/*
 * epsilometer_AUX.c
 *
 *  Created on: Jul 18, 2017
 *      Author: aleboyer
 */



/*local library */
#include "ep_auxiliary.h"
#include "ep_SDcard.h"
#include "em_usart.h"
#include "efm32wg_uart.h"
#include "em_dma.h"

/******************************************************************************
 * @name initAUX
 * @brief
 *  initialize the chip and UART
 * @details
 *	initialize the SD mode: USART2, GPIO route etc
 *	mount the SD driver (FatFS layer)
 *	define a filename in ANSI code
 *	write a header (to be define)
 *
 *
 * @Author A. Le Boyer
 *****************************************************************************/

// define variable
uint32_t len;
#define DMA_CHANNEL    0

/* Defining the LEUART0 initialization data */
LEUART_Init_TypeDef leuart0Init =
{
  .enable   = leuartDisable,     /* Activate data reception on LEUn_RX pin. */
  .refFreq  = 0,                  /* Inherit the clock frequenzy from the LEUART clock source */
  .baudrate = 38400,               /* Baudrate = 38400 bps */
  .databits = leuartDatabits8,    /* Each LEUART frame containes 8 databits */
  .parity   = leuartNoParity,     /* No parity bits in use */
  .stopbits = leuartStopbits1,    /* Setting the number of stop bits in a frame to 1 bitperiods */
};



void initAUX1(void){
    /* GPIO enable  */
	//old madre
	//GPIO_PinModeSet(gpioPortD, 3, gpioModePushPull,0); // MAX3221 EN MADRE REv1 I had to wire MAX3221 pin 1 to GPIO D3 only for old madre
	// end old madre

    /* eneable clocks  */
	//TODO check if CORELE is necessary when activate EM4 for back up mode
	CMU_ClockSelectSet(cmuClock_LFB, cmuSelect_HFCLKLE);
	CMU_ClockEnable(cmuClock_LFB, true);
	// enable the LE domain to use the HF clock
    CMU->CTRL=(CMU->CTRL &~_CMU_CTRL_HFLE_MASK)| CMU_CTRL_HFLE;
    // divide by 4 the HFcoreclock in the LE domain
    CMU->HFCORECLKDIV=(CMU->HFCORECLKDIV &~_CMU_HFCORECLKDIV_HFCORECLKLEDIV_MASK)| CMU_HFCORECLKDIV_HFCORECLKLEDIV_DIV4;
    CMU->LFBPRESC0=(CMU->LFBPRESC0 &~_CMU_LFBPRESC0_LEUART0_MASK)| CMU_LFBPRESC0_LEUART0_DIV8;

	CMU_ClockEnable(cmuClock_CORELE, true);   // needed to enable IEN_SIGF or IEN STARTFRAME in LEUART. IEN_RXDATA works without CORELE
	CMU_ClockEnable(cmuClock_LEUART0, true);    /* Enable LEUART0 clock */


	// define the length of the Auxiliary 1 sample
	aux1_sample=malloc(sizeof(uint8_t) *aux1_setup_ptr->Auxword_length);
	// define the length of the Auxiliary 1 block
	aux1sample_per_block= floor(madre_setup_ptr->sample_frequency/2/     \
			 	 	 	  aux1_setup_ptr->aux_frequency)-1;
	aux1_word_length=aux1_setup_ptr->Auxword_length + 2*sizeof(uint32_t)+sizeof(uint8_t);
                   //length of aux1 sample + length of epsi stamp in hex + length ','
    aux1_buffer_length  = aux1sample_per_block*aux1_word_length;

	aux1_buffer      = malloc(sizeof(uint8_t) * aux1_buffer_length);
	aux1header="$AUX1";

	// Set up low energy uart to trigger the DMA

	LEUART_Reset(LEUART0);
	LEUART_Init(LEUART0, &leuart0Init);

	/* Route LEUART0 RX pin to location 0 */
	LEUART0->ROUTE = LEUART_ROUTE_RXPEN | LEUART_ROUTE_TXPEN | LEUART_ROUTE_LOCATION_LOC0;

	/* Enable LEUART Signal Frame Interrupt */
	LEUART0->CMD = LEUART_CMD_CLEARRX;

	br=LEUART_BaudrateGet(LEUART0);

	/* Enable LEUART Signal Frame Interrupt */
	LEUART0->FREEZE = 1;

	LEUART0->SIGFRAME = (uint8_t) '\n';
	//LEUART0->CTRL = LEUART_CTRL_SFUBRX | LEUART_CTRL_RXDMAWU ;
	LEUART0->CMD |= LEUART_CMD_RXBLOCKEN;
	/* Make sure the LEUART wakes up the DMA on RX data */
	LEUART0->CTRL = LEUART_CTRL_RXDMAWU;
	LEUART0->FREEZE = 0;
	while (LEUART0->SYNCBUSY) { }

	LEUART_Enable(LEUART0, leuartEnable); //

	// init DMA
	init_aux_block();
	initDMA();

	LEUART_IntEnable(LEUART0, LEUART_IEN_SIGF);

	/* Enable LEUART0 interrupt vector */
	NVIC_SetPriority(LEUART0_IRQn, 1);
	NVIC_EnableIRQ(LEUART0_IRQn);


}

void init_aux_block(void){

for (int i=0;i<aux1_buffer_length;i++){
    if (i%aux1_word_length==8){
    	aux1_buffer[i] = 44;
    }
    else{
    	aux1_buffer[i] = 48;
	}
    if ((i%aux1_word_length)==(aux1_word_length-2)){
    	aux1_buffer[i]=13;
    }
    if ((i%aux1_word_length)==(aux1_word_length-1)){
    	aux1_buffer[i]  =10;
    }
	}
}


void initAUX2(void){
}




/**************************************************************************//**
 * @brief LEUART IRQ handler
 *
 * When the signal frame is detected by the LEUART, this interrupt routine will
 * zero-terminate the char array, write the received string the to the LCD, and
 * reset the DMA for new data.
 *
 *****************************************************************************/
void LEUART0_IRQHandler(void)
{
    LEUART_IntDisable(LEUART0, LEUART_IEN_SIGF);
	uint32_t leuartif = LEUART_IntGet(LEUART0);
	LEUART0->FREEZE = 1;
	LEUART0->CMD |= LEUART_CMD_RXBLOCKDIS;
	LEUART0->FREEZE = 0;
	while (LEUART0->SYNCBUSY) { }
	// Start DMA detection
	if (leuartif & LEUART_IF_SIGF){
		DMA->IFC |= DMA_IFC_CH0DONE; //clear the interrupt flag channel 0
		DMA_IntEnable(DMA_IEN_CH0DONE);
		DMA_ActivateBasic(
				LEUARTDmaRxChannel,
				true,
				false,
				(void*) (aux1_sample),
				(void*) (&(LEUART0->RXDATA)),
				aux1_setup_ptr->Auxword_length-1);
		if (aux1_count>1){
			// Already gathered AUX sample but we are back in the LEUART.
			// DMA failed to get an entire SBE 49 sample.
			// TODO fill the Aux Block with !!!~(endblock)
			USART_Tx(USART1, 0x4C); // 0x4C ->ASCII: L
			USART_Tx(USART1, '\r');
			USART_Tx(USART1, '\n');
		}
	}
}




