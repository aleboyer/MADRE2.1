/*
 * ep_menu.h
 *
 *  Created on: Apr 25, 2017
 *      Author: aleboyer
 */

#ifndef INC_EP_MENU_H_
#define INC_EP_MENU_H_

/*standard c library */
#include "stdint.h"
#include "stdio.h"

/*energy micro library */
#include "em_device.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_usart.h"
#include "em_chip.h"
#include "em_rtc.h"


/* SD card library */
#include "microsd.h"
#include "ff.h"
#include "diskio.h"

/* local library */
#include "ep_common.h"
#include "ep_analog.h"
#include "ep_coms.h"
#include "ep_CMU_init.h"
#include "ep_GPIO_init.h"
#include "ep_TIMER_init.h"
#include "ep_SDcard.h"
#include "ep_auxiliary.h"



void MADRE_menu(void);
void MADRE_Config(void);
void MADRE_Change_baudrate(void);
void MADRE_Change_AUX1(void);
void MADRE_set_up_time(void);
void MADRE_reset(void);
void init_MADRE(void);
void MADRE_tx_buf(char * buf);
void MADRE_get_Config(void);
void init_MAP(void);
void standby4setup(uint8_t delay);
enum madre_states MADRE_resume_sampling(void);
uint8_t itohexa_helper(uint8_t x);

#endif /* INC_EP_MENU_H_ */
