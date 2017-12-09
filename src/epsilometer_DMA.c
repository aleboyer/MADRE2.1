/*
 * epsilometer_DMA.c
 *
 *  Created on: Jul 27, 2017
 *      Author: aleboyer
 */


#include "ep_DMA.h"
#include "em_cmu.h"
#include "ep_auxiliary.h"
#include "em_usart.h"


/* DEFINES */


/* GLOBAL VARIABLES */


DMA_CB_TypeDef cb;

uint32_t leuartif;
uint32_t len;


/**************************************************************************//***
 * @brief  DMA init function
 ******************************************************************************/
void initDMA(void){
	//USARTDmaTxChannel=1;
	LEUARTDmaRxChannel=0;

	CMU_ClockEnable(cmuClock_DMA, true);        /* Enable DMA clock */
	DMADRV_FreeChannel( LEUARTDmaRxChannel ); //free channel 0. usefull after menu exit
	/* Setup LEUART with DMA */
	DMADRV_Init();
	// Allocate DMA channels
	if (ECODE_EMDRV_DMADRV_OK != DMADRV_AllocateChannel(&LEUARTDmaRxChannel, NULL)) {
		printf("DMA channel allocation failure for LEUART RX!");
	}

	// DMA LERX configuration descriptor
	LEUARTDmaRxCfgDescr.arbRate = dmaArbitrate1;
	LEUARTDmaRxCfgDescr.dstInc = dmaDataInc1;
	LEUARTDmaRxCfgDescr.hprot = 0;
	LEUARTDmaRxCfgDescr.size = dmaDataSize1;
	LEUARTDmaRxCfgDescr.srcInc = dmaDataIncNone;
	// DMA LERX channel configuration
	LEUARTDmaRxCfgChannel.cb = NULL;
	LEUARTDmaRxCfgChannel.enableInt = true;
	LEUARTDmaRxCfgChannel.highPri = false;
	LEUARTDmaRxCfgChannel.select = DMAREQ_LEUART0_RXDATAV;
	// Configure LERX channel
	DMA_CfgChannel(LEUARTDmaRxChannel, &LEUARTDmaRxCfgChannel);
	// Configure LERX channel primary descriptor
	DMA_CfgDescr(LEUARTDmaRxChannel, true, &LEUARTDmaRxCfgDescr);
	// Configure LERX channel secondary descriptor
	DMA_CfgDescr(LEUARTDmaRxChannel, false, &LEUARTDmaRxCfgDescr);


/*	// DMA TX configuration descriptor
	USARTDmaTxCfgDescr.arbRate = dmaArbitrate1;
	USARTDmaTxCfgDescr.dstInc = dmaDataInc1;
	USARTDmaTxCfgDescr.hprot = 0;
	USARTDmaTxCfgDescr.size = dmaDataSize1;
	USARTDmaTxCfgDescr.srcInc = dmaDataIncNone;
	// DMA TX channel configuration
	USARTDmaTxCfgChannel.cb = NULL;
	USARTDmaTxCfgChannel.enableInt = true;
	USARTDmaTxCfgChannel.highPri = false;
	USARTDmaTxCfgChannel.select = DMAREQ_USART1_TXBL;
	// Configure LERX channel
	DMA_CfgChannel(USARTDmaTxChannel, &USARTDmaTxCfgChannel);
	// Configure LERX channel primary descriptor
	DMA_CfgDescr(USARTDmaTxChannel, true, &USARTDmaTxCfgDescr);
	// Configure LERX channel secondary descriptor
	DMA_CfgDescr(USARTDmaTxChannel, false, &USARTDmaTxCfgDescr);
*/

	DMA_IntClear(0xffffffff);
	NVIC_EnableIRQ(DMA_IRQn);
	NVIC_SetPriority(DMA_IRQn, 1);

}


/****************************************************************************
 * @brief DMA IRQ handler
 *
 * When the signal frame is detected by the LEUART, and
 * reset the DMA for new data.
 *
 *****************************************************************************/
void DMA_IRQHandler(void)
{
	int DMAif=DMA_IntGet();
	DMA_IntDisable(DMAif);
	DMA_IntClear(0xffffffff);
		// Start frame detection
	switch (DMAif){
		case  DMA_IF_CH0DONE:
			if (aux1_sample[aux1_setup_ptr->Auxword_length-1]==(uint8_t) aux1_setup_ptr->endchar){ //aux_buffer is pointer !!! need to think here
				int DMAcount;
				LEUART0->CMD = LEUART_CMD_CLEARRX;
				aux1_count++;
				DMAcount=(aux1_count % aux1sample_per_block) *  \
						 (aux1_setup_ptr->Auxword_length + 2*sizeof(uint32_t)+sizeof(uint8_t));
        		for (int i=0;i<aux1_word_length;i++){
        			if (i<4){
        				aux1_buffer[i+DMAcount]=itohexa_helper(pending_samples>>((sizeof(uint32_t)-i)*8));
        			}
        			if(i==4){
        				aux1_buffer[i+DMAcount]=44; //decimal 44 = ','
        			}
        			if(i>4){
            			aux1_buffer[i+DMAcount]=aux1_sample[i-(sizeof(uint32_t)+1)];
        			}
        		}

				DMA_IntEnable(DMA_IEN_CH0DONE);
				DMA_ActivateBasic(
						LEUARTDmaRxChannel,
						true,
						false,
						(void*) (aux1_sample),
						(void*) (&(LEUART0->RXDATA)),
						aux1_setup_ptr->Auxword_length-1);
			}
			else{
				LEUART0->FREEZE = 1;
				LEUART0->CMD |= LEUART_CMD_RXBLOCKEN;
				LEUART0->FREEZE = 0;
				while (LEUART0->SYNCBUSY) { }

				LEUART_IntClear(LEUART0,0xffffffff);
				LEUART_IntEnable(LEUART0, LEUART_IEN_SIGF);
			}
			break;
		case DMA_IF_CH1DONE:
			break;

		default:
			LEUART_IntClear(LEUART0, 0xffffffff);
			LEUART_IntEnable(LEUART0, LEUART_IEN_SIGF);
		}
}




