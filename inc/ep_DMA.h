/*
 * ep_DMA.h
 *
 *  Created on: Jul 27, 2017
 *      Author: aleboyer
 */

#ifndef INC_EP_DMA_H_
#define INC_EP_DMA_H_

#include "ep_common.h"
#include "em_dma.h"
#include "dmadrv_config.h"
#include "dmadrv.h"


// DMA globals
unsigned LEUARTDmaRxChannel;
DMA_CfgDescr_TypeDef LEUARTDmaRxCfgDescr;
DMA_CfgChannel_TypeDef LEUARTDmaRxCfgChannel;

/*unsigned USARTDmaTxChannel;
DMA_CfgDescr_TypeDef USARTDmaTxCfgDescr;
DMA_CfgChannel_TypeDef USARTDmaTxCfgChannel;
*/

void initDMA(void);

#endif /* INC_EP_DMA_H_ */
