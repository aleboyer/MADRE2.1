/*
 * ep_sdcard.h
 *
 *  Created on: Jan 24, 2017
 *      Author: aleboyer
 */

#ifndef INC_EP_SDCARD_H_
#define INC_EP_SDCARD_H_

/*energy micro library */
#include "em_gpio.h"

/* SD card library */
#include "microsd.h"
#include "ff.h"
#include "diskio.h"
#include "stddef.h"
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "clock_tc.h"

#include "ep_common.h"



/* SD card initialisation */

//TCHAR drive;             //TCHAR is only use for the filename and the drive name;
//TCHAR filename; //TCHAR is only use for the filename and the drive name;


FATFS Fatfs;				// File system specific
FRESULT res;				// FatFs function common result code
FRESULT res_mount;			// FatFs function mount result code
UINT br, bw;				// File read/write count
DSTATUS resCard;			// SDcard status

/* custom function */
UINT SDwritten;


void initSD(void);
void writeSD(void);
void writeSD_header(char * Buffer, uint32_t Bufferlength);
void writeSD_aux(uint8_t * Buffer, uint32_t Bufferlength);

#endif /* INC_EP_SDCARD_H_ */
