/*
 * epsilometer_SDcard.c
 *
 *  Created on: Jan 24, 2017
 *      Author: aleboyer
 */

/*local library */
#include "ep_SDcard.h"


/******************************************************************************
 * @name initSD
 * @brief
 *  initialize SD card
 * @details
 *	initialize the SD mode: USART2, GPIO route etc
 *	mount the SD driver (FatFS layer)
 *	define a filename in ANSI code
 *	write a header (to be define)
 *
 *
 * @Author A. Le Boyer
 *****************************************************************************/

void initSD(void){

	MICROSD_Init(); //Initialize MicroSD driver

	resCard = disk_initialize(0); //Check micro-SD card status
	switch (resCard) //Use onboard LED's to indicate error.
	{
	case STA_NOINIT: // Drive not initialized
		break;
	case STA_NODISK: // No medium in the drive
		break;
	case STA_PROTECT: // Write protected
		break;
	default:
		break;
	}

	// Initialize filesystem
	//TCHAR * filename = _T("ep_test.bin"); //TCHAR is only use for the filename and the drive name;
	TCHAR * drive    = _T("0:");
	char buf[1024];
	char buf1[1024];

	nb_file=1; // initialize the number of file user to change the filename if file already exist

	res_mount=f_mount(&Fatfs,drive ,1);
	SDwritten = 0;

	//TCHAR is only use for the filename and the drive name;
	char * textheader = "stuff out the header\nEpsilometer-Wavechaser-MPL"; // char * allow to initialize string
	char * header2bin = "Start Data:"; // char * allow to initialize string
	char * cr="\n";
	char filename_default[10]="ep_test";


	// local time
	//TODO check out local time and sync the board time with user time
	struct tm tsplt_start;
	gmtime_r(&madre_setup_ptr->Start_time,&tsplt_start);
	clockSetStartCalendar(&tsplt_start);

	strftime(buf1, sizeof buf1, "%Y%m%d_%H%M%S", &tsplt_start);
	sprintf(buf,"%s_%s_%i.dat",filename_default,buf1,nb_file);

	static int cur_min = -1, cur_sec = -1;
	struct tm tsplt;
	time_t t = time(NULL);
    localtime_r (&t, &tsplt);
    // filename stuff
    int idx;
    for (idx = 0; idx < strlen (buf); ++idx){
    	filename[idx] = ff_convert (buf[idx], 1);
    }
    filename[idx] = '\0';
    //ctime_r(&t, buf);
    ;


	if (res == FR_OK) f_close (&fsrc);
	// Open  the file for write
	res = f_open(&fsrc, filename, FA_CREATE_NEW | FA_WRITE );
	while (res == FR_EXIST){
		nb_file++;
		strftime(buf1, sizeof buf1, "%Y%m%d_%H%M%S", &tsplt_start);
		sprintf(buf,"%s_%s_%i.dat",filename_default,buf1,nb_file);
		for (idx = 0; idx < strlen (buf); ++idx){
			filename[idx] = ff_convert (buf[idx], 1);
		}
		filename[idx] = '\0';
		res = f_open(&fsrc, filename, FA_CREATE_NEW | FA_WRITE );

	}
	cur_min = tsplt.tm_min;

  ctime_r(&t, buf);
  f_write (&fsrc, buf, strlen(buf), &SDwritten);
  SDwritten = 0;
  f_write(&fsrc, textheader, strlen(textheader), &SDwritten);
  SDwritten = 0;
  f_write(&fsrc, cr,1, &SDwritten);

  cur_sec = tsplt.tm_sec;
    SDwritten = 0;
    // write the header on the SD
    f_write(&fsrc, header2bin,strlen(header2bin), &SDwritten);
    SDwritten = 0;
    f_write(&fsrc, cr,1, &SDwritten);
	err_sync=f_sync(&fsrc);
    f_close(&fsrc);

    sd_state=Wait;
	flag_SDfile=1;
	// open SD file
	res = f_open(&fsrc, filename, FA_OPEN_APPEND | FA_WRITE);

}

/******************************************************************************
 * @name writeSD
 * @brief
 *  write a block on the SD card
 * @details
 *	check the hard coded values
 *
 * @Author A. Le Boyer
 *****************************************************************************/

void writeSD(){

	int32_t count=(sd_bytes_sent+bytes_per_block)%buffer_size;
	SDwritten = 0;
    f_write(&fsrc, "$EPSI",5, &SDwritten);
    err_write=err_write+SDwritten;
    SDwritten = 0;
    if (count<bytes_per_block){ //in case sd_byte_sent is close to the end of the buffer. and we want to avoid memory leak
    	f_write(&fsrc, data_buffer+(sd_bytes_sent% buffer_size),bytes_per_block-count, &SDwritten);
        err_write=err_write+SDwritten;
   	    SDwritten = 0;
    	f_write(&fsrc, data_buffer,count, &SDwritten);
    }
    else{
    	f_write(&fsrc, data_buffer+(sd_bytes_sent % buffer_size),bytes_per_block, &SDwritten);
    }
    err_write=err_write+SDwritten;
	SDwritten = 0;
    sd_bytes_sent+=bytes_per_block;
}

/******************************************************************************
 * @name writeSD
 * @brief
 *  write a block on the SD card
 * @details
 *	check the hard coded values
 *
 * @Author A. Le Boyer
 *****************************************************************************/

void writeSD_aux(uint8_t * Buffer, uint32_t Bufferlength){
	SDwritten = 0;
    f_write(&fsrc, "$AUX1",5, &SDwritten);
    err_write=err_write+SDwritten;
	SDwritten = 0;
    f_write(&fsrc, Buffer,Bufferlength, &SDwritten);
    err_write=err_write+SDwritten;
	SDwritten = 0;
	//
}

/******************************************************************************
 * @name writeSD
 * @brief
 *  write a block on the SD card
 * @details
 *	check the hard coded values
 *
 * @Author A. Le Boyer
 *****************************************************************************/

void writeSD_header(char * Buffer, uint32_t Bufferlength){
	SDwritten = 0;
    f_write(&fsrc, Buffer,Bufferlength, &SDwritten);
    err_write=err_write+SDwritten;
	SDwritten = 0;
	//
}




/******************************************************************************
* @brief
*   Time function for FatFS ; uses Calendar RTC config from AN0006
*****************************************************************************/
DWORD get_fattime (void)
{
     struct tm ct;
     time_t t = time(NULL);          // get time from RTC based clock
     localtime_r (&t, &ct);          // convert to tm structure

  /* FAT expects
           bit31:25   Year origin from the 1980 (0..127)
           bit24:21   Month (1..12)
           bit20:16   Day of the month(1..31)
           bit15:11   Hour (0..23)
           bit10:5    Minute (0..59)
           bit4:0     Second / 2 (0..29)  */

     return (((ct.tm_year - 80) << 25) |
                ((ct.tm_mon + 1) << 21) |
                (ct.tm_mday << 16) |
                (ct.tm_hour << 11) |
                (ct.tm_min << 5) |
                (ct.tm_sec >> 1) );

}

