/*
 * epsilometer_menu.c
 *
 *  Created on: Apr 24, 2017
 *      Author: aleboyer
 */



#define _XOPEN_SOURCE 700
#include "ep_menu.h"

char buf[100]= {"\0"};
char buf1[100]= {"\0"};

uint8_t rxData8 = 0;
uint16_t rxData16 = 0;
int menu_out=1;


/******************************************************************************
 * @name MADRE_menu
 * @brief
 *   interaction with the user. User can my python script.
 * @details
 *	define a character chain giving the user options.
 *	If user send 1 sent the user into the change config mode
 *	If user send 2 resume sampling with the new configuration if any
 *
 * @Author A. Le Boyer
 *****************************************************************************/


void MADRE_menu(void){

    // define a sentence to send to the user
	tx_state=SetUp;
	menu_out=1;
	sprintf(buf,"\n ACTIONS \n BR: Change baud rate \n RA: Toggle AUX1 \n");
	MADRE_tx_buf(buf);
	sprintf(buf," SC: Set calendar \n GC: Get Configuration \n RS: RESUME SAMPLING\n");
	MADRE_tx_buf(buf);
	sprintf(buf1,"TRY AGAIN\n");

	// send the user action option through TX.
	USART1->CMD =(USART1->CMD & ~_USART_CMD_CLEARRX_MASK)|USART_CMD_CLEARRX;

	while (menu_out==1) {
		if((USART1->STATUS & USART_STATUS_RXFULL)){
			rxData16 = USART_RxDouble(USART1);
			USART1->CMD =(USART1->CMD & ~_USART_CMD_CLEARRX_MASK)|USART_CMD_CLEARRX;
			switch (rxData16) {
			case 0x5242:
				MADRE_Change_baudrate();
				menu_out=0;
				break;
			case 0x4152:
				MADRE_Change_AUX1();
				menu_out=0;
				break;
			case 0x4353:
				MADRE_set_up_time();
				menu_out=0;
				break;
			case 0x4347:
				MADRE_get_Config();
				menu_out=0;
				break;
			case 0x5352:
				MADRE_reset();
				MADRE_Config();
				standby4setup(1);
				madre_state=MADRE_resume_sampling();
				menu_out=0;
				break;
			default:
				// send the user action option through TX.
				MADRE_tx_buf(buf1);
				USART1->CMD =(USART1->CMD & ~_USART_CMD_CLEARRX_MASK)|USART_CMD_CLEARRX;
				break;
			}
		}
	}
}


/******************************************************************************
 * @name MADRE_Change_baudrate
 * @brief
 *   TODO
 * @details
 *	TODO
 * @Author A. Le Boyer
 *****************************************************************************/
void MADRE_Change_baudrate(void) {

	sprintf(buf1,"TRY AGAIN\n");
	sprintf(buf,"Change baud rate (default:%i,current:%i): 1-460800 , 2-115200 , 3 - 38400 \n",460800,(int) madre_setup_ptr->usart_baudrate);
    menu_out=1;
	MADRE_tx_buf(buf);

	while (menu_out==1){
		rxData8 = USART_Rx(USART1);
		USART1->CMD =(USART1->CMD & ~_USART_CMD_CLEARRX_MASK)|USART_CMD_CLEARRX;
		switch (rxData8){
		case 0x31:
			madre_setup_ptr->usart_baudrate=460800;
			menu_out=0;
			break;
		case 0x32:
			madre_setup_ptr->usart_baudrate=115200;
			menu_out=0;
			break;
		case 0x33:
			madre_setup_ptr->usart_baudrate=38400;
			menu_out=0;
			break;
		default:
			// send the user action option through TX.
			MADRE_tx_buf(buf1);
			USART1->CMD =(USART1->CMD & ~_USART_CMD_CLEARRX_MASK)|USART_CMD_CLEARRX;
			break;
		}
	}
	MADRE_menu();
}
/******************************************************************************
 * @name MADRE_Change_AUX1
 * @brief
 *   TODO
 * @details
 *	TODO
 * @Author A. Le Boyer
 *****************************************************************************/
void MADRE_Change_AUX1(void) {
    menu_out=1;
	sprintf(buf1,"TRY AGAIN\n");
	sprintf(buf,"Change AUX1 (default:%i,current:%i): 1-SBE , 2-none \n",1,(int) madre_setup_ptr->AUX_flag);

	MADRE_tx_buf(buf);

	while (menu_out==1){
		rxData8 = USART_Rx(USART1);
		USART1->CMD =(USART1->CMD & ~_USART_CMD_CLEARRX_MASK)|USART_CMD_CLEARRX;
		switch (rxData8){
		case 0x31:
			madre_setup_ptr->AUX_flag=1;
			menu_out=0;
			break;
		case 0x32:
			madre_setup_ptr->AUX_flag=0;
			menu_out=0;
			break;
		default:
			// send the user action option through TX.
			MADRE_tx_buf(buf1);
			USART1->CMD =(USART1->CMD & ~_USART_CMD_CLEARRX_MASK)|USART_CMD_CLEARRX;
			break;
		}
	}
	MADRE_menu();
}

/******************************************************************************
 * @name MADRE_Change_Time
 * @brief
 *   TODO
 * @details
 *	TODO
 * @Author A. Le Boyer
 *****************************************************************************/
void MADRE_set_up_time(void) {

    int count=0;
	char strnewtime[20]= {"\0"};

	sprintf(buf,"Set up new time for resume sampling (current:%s , USE THE SAME FORMAT): \n",madre_setup_ptr->Start_time);
	MADRE_tx_buf(buf);

	while (count<19){
		strnewtime[count] = USART_Rx(USART1);
		USART1->CMD =(USART1->CMD & ~_USART_CMD_CLEARRX_MASK)|USART_CMD_CLEARRX;
		madre_setup_ptr->Start_time[count]=strnewtime[count];
		count ++;
	}
//	struct tm tsplt;
//	strptime("2001-11+25 18:31:01", "%Y-%m-%d %H:%M:%S", &tsplt);

<<<<<<< HEAD
=======
	sprintf(buf,"New time: %s \n",madre_setup_ptr->Start_time);
	MADRE_tx_buf(buf);

	MADRE_menu();
}

/******************************************************************************
 * @name MADRE_get_Config
 * @brief
 *   TODO
 * @details
 *	TODO
 * @Author A. Le Boyer
 *****************************************************************************/
void MADRE_get_Config(void) {

	sprintf(buf,"\nMADRE SET UP\n");
	MADRE_tx_buf(buf);
	sprintf(buf1,"%i \n",(int) madre_setup_ptr->core_clock);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i \n",(int) madre_setup_ptr->maximum_samples);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i \n",(int) madre_setup_ptr->pinInterupt);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i \n",(int) madre_setup_ptr->blocksize);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i \n",(int) madre_setup_ptr->sample_frequency);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i \n",(int) madre_setup_ptr->master_clock_frequency);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i \n",(int) madre_setup_ptr->timer1Sync);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i \n",(int) madre_setup_ptr->spi_baudrate);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i \n",(int) madre_setup_ptr->usart_baudrate);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%s \n",madre_setup_ptr->Start_time);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i \n",(int) madre_setup_ptr->AUX_flag);
	MADRE_tx_buf(buf1);

	sprintf(buf,"\nMAP SET UP\n");
	MADRE_tx_buf(buf);
	sprintf(buf1,"%i \n",(int) map_setup_ptr->number_sensor);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i,%i,%i,%i,%i,%i,%i,%i \n",(int) map_setup_ptr->sensorID[0],   \
			                                  (int) map_setup_ptr->sensorID[1],   \
			                                  (int) map_setup_ptr->sensorID[2],   \
			                                  (int) map_setup_ptr->sensorID[3],   \
			                                  (int) map_setup_ptr->sensorID[4],   \
			                                  (int) map_setup_ptr->sensorID[5],   \
			                                  (int) map_setup_ptr->sensorID[6],   \
			                                  (int) map_setup_ptr->sensorID[7]
											  );
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i \n",(int) map_setup_ptr->ADCtempconfig);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i \n",(int) map_setup_ptr->ADCshearconfig);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i \n",(int) map_setup_ptr->ADCcondconfig);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i \n",(int) map_setup_ptr->ADCaccelconfig);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i,%i \n",(int) map_setup_ptr->t1_ID[0],(int) map_setup_ptr->t1_ID[1]);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i,%i \n",(int) map_setup_ptr->t2_ID[0],(int) map_setup_ptr->t2_ID[1]);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i,%i \n",(int) map_setup_ptr->s1_ID[0],(int) map_setup_ptr->s1_ID[1]);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i,%i \n",(int) map_setup_ptr->s2_ID[0],(int) map_setup_ptr->s2_ID[1]);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i,%i \n",(int) map_setup_ptr->cond_ID[0],(int) map_setup_ptr->cond_ID[1]);
	MADRE_tx_buf(buf1);


	sprintf(buf,"\nAUX SET UP\n");
	MADRE_tx_buf(buf);
	sprintf(buf1,"%i \n",(int) aux1_setup_ptr->usart_baudrate);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i \n",(int) aux1_setup_ptr->Auxword_length);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i \n",(int) aux1_setup_ptr->aux_frequency);
	MADRE_tx_buf(buf1);
	sprintf(buf1,"%i \n",(int) aux1_setup_ptr->endchar);
	MADRE_tx_buf(buf1);

	MADRE_menu();
}

/******************************************************************************
 * @name MADRE_resume_sampling
 * @brief
 *   TODO
 * @details
 *	TODO
 * @Author A. Le Boyer
 *****************************************************************************/
void MADRE_tx_buf(char * buf) {
	for(int i=0;i<strlen(buf);i++){
		USART_Tx(USART1,buf[i]);
	}
}

/******************************************************************************
 * @name MADRE_resume_sampling
 * @brief
 *   TODO
 * @details
 *	TODO
 * @Author A. Le Boyer
 *****************************************************************************/
void MADRE_reset(void) {
	if(data_buffer) free(data_buffer);
	if(header_buffer) free(header_buffer);
	if(aux1_sample) free(aux1_sample);
	memset(data_buffer, 0, sizeof(uint8_t)*buffer_size);
	memset(header_buffer, 0,sizeof(char)*header_length);
	memset(aux1_sample, 0,sizeof(uint8_t) *aux1_setup_ptr->Auxword_length);
	AD7124_Reset();
	standby4setup(2);
>>>>>>> NISKINE_8Channels
}







/******************************************************************************
 * @name MADRE_Config
 * @brief
 *   Configure and switch on the needed part on MADRE
 * @details
 *   init the clock management
 *   init the GPIO port (switch the ADC)
 *   set up UART the communication port between the ADC and the MCU
 *   set up the GPIO interrupt controled by the ADC
 *   configure the ADC
 *   set the main buffer size
 *   initialize the TIMERS
 *   initialize the RS232 UART
 *   initialize the SD card
 *   open a file on the SD card to start the sampling
 *
 * @Author A. Le Boyer
 *****************************************************************************/
void MADRE_Config(void) {
	/* Use 20 MHZ HFRCO as core clock frequency*/
    /* use of an interrupt on CMU to trigger the Oscillator when ready */
	main_calendar_setup();  // set up date and start RTC. TODO: initialize the backRTC and start the LFXO
    init_MADRE();           // define the MADRE variables declare in common.h
	init_SPI();             // Initialize the SPI interface for the Analog front end
    init_MAP();             // Initialize the analog front end (i.e initialize the ADCs)
	setupGpioInt();         // Setup GPIO Interrupt but leave disabled. This interrupt is the one the collect the data from the ADC
    UART_Setup();           // initialize the 422 communication. this is the USER-MADRE communication port

	init_TIMER(coreclock_cycle,timer1_phase_shift); //set up timer MCLOCK and SYNC. MCLOCK (TIMER0) is send to the ADC

	standby4setup(1);

	// initialize SD: mount the driver, open file, write a header
	initSD();

	// initialize the auxiliary peripheral port
	switch (madre_setup_ptr->AUX_flag){
		case 1:
			initAUX1();
			break;
		case 2:
			initAUX2();
			break;
		}
}

/******************************************************************************
 * @name init_MADRE
 * @brief
 *   initiliaze the variables for the MADRE board
 * @details
 *   malloc databuffer,
 *
 * @Author A. Le Boyer
 *****************************************************************************/
void init_MADRE(void){

   // define all the madre variables declared in common.h
	byte_per_sample    = map_setup_ptr->number_sensor*map_setup_ptr->ADCword_length;          // 6 bytes per channel (hex) * number of channel+ \n
	buffer_size        = madre_setup_ptr->maximum_samples*byte_per_sample;                                //
	coreclock_cycle    = madre_setup_ptr->core_clock/madre_setup_ptr->master_clock_frequency/2-1;    //
	timer1_phase_shift = .5 * coreclock_cycle;
	bytes_per_block    = madre_setup_ptr->blocksize*byte_per_sample;

	pending_samples     = 0; 	 // samples from ADC
	aux1_bytes_sent     = 0;
	aux1_count          = 0;
	tx_pending_bytes    = 0;
	sensorID            = 0;
	sd_bytes_sent       = 0;
	block_chcksum       = 0;
	chcksum_aux1_header = 0;
	aux2_chcksum        = 0;
	voltage             = 0;
	header_bytes_sent   = 0;
	map_bytes_sent      = 0;
	err_write           = 0;
	err_sync            = 0;

	// uint32 array where data are stored and from where data are sent to the serial port
    data_buffer       = malloc(sizeof(uint8_t)*buffer_size);
    header_length     = 63;
    header_buffer     = NULL;
    header_buffer     = malloc(sizeof(char)*header_length);
    sprintf(header_buffer,"\r\n$MADRE00000000,00000000,00000000,00000000,00000000,00000000\r\n");
    //                     /r/n$MADREepsisample,timestamp,voltage,aux1checksum,aux2checksum,blockchecksum/r/n

}

/******************************************************************************
 * @name init_MAP
 * @brief
 *   initiliaze the Analog to digital converter 7124
 * @details
 *
 * @Author A. Le Boyer
 *****************************************************************************/
void init_MAP(void){
	mapheader="$EPSI";
	AD7124_Reset(); // Place devices into a known state
	define_ADC_configuration(); // set up and send the registers for the ADC
}

/******************************************************************************
 * @name standby4setup
 * @brief
 *   stay in a while loop for x second so the user can change the date after power up
 * @details
 *
 * @Author A. Le Boyer
 *****************************************************************************/

void standby4setup(uint8_t delay) {
    while (RTC->CNT<delay*32768){}
}


/******************************************************************************
 * @name MADRE_resume_sampling
 * @brief
 *   Re sync the ADC and enable the GPIO interrupt
 * @details
 *   initialize the sampling, tx and SD counters.
 *   Re sync the ADC and enable the GPIO interrupt
 *   change the state of the board
 *
 * @Author A. Le Boyer
 *****************************************************************************/

enum madre_states MADRE_resume_sampling(void){

	// start conversion: send SYNC signal and enable the sampling interrupt
    AD7124_StartConversion(sensors[map_setup_ptr->sensorID[sensorID]]);
    madre_state = Sampling;
	return madre_state;
}


uint8_t itohexa_helper(uint8_t x) {
	uint8_t dest;
	if (x<=9){
		dest=x+48;
	}
	else{
		dest=x+55;
	}
	return dest;
}

<<<<<<< HEAD

=======
>>>>>>> NISKINE_8Channels


