/*
 * ep_coms.h
 *
 *  Created on: Jun 20, 2016
 *      Author: leumas64
 */

#ifndef EP_COMS_H_
#define EP_COMS_H_

#include "ep_common.h"
#include "em_gpio.h"


void UART_Setup(void);
void uartPutData(void);
uint32_t sendblock(uint32_t dataLen,char * Buffer, uint32_t bytes_sent);
#endif /* EP_COMS_H_ */
