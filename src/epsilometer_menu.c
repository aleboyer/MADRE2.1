/*
 * epsilometer_menu.c
 *
 *  Created on: Apr 24, 2017
 *      Author: aleboyer
 */



#include "ep_menu.h"


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
	char buf[100]= {"\0"};
	char buf1[100]= {"\0"};
	uint8_t  rxData8  = 0;
	//uint16_t  rxData16;
	sprintf(buf,"ACTIONS: \n 1- CHANGE CONFIG \n 2- RESUME SAMPLING\n");
	sprintf(buf1,"TRY AGAIN\n");

	// USART_RxDouble have while loop which will hold on until a bytes is going to come.
	// giving us the time to clean serial buffer in python. This is not very elegant
	// but I already spend almost a whole day to figure out something "smart"

	// menu selection
	//TODO: this is bad, I need to stay here to clean the serial buffer in python as explained above
	USART_RxDouble(USART1);
	USART1->CMD =(USART1->CMD & ~_USART_CMD_CLEARRX_MASK)|USART_CMD_CLEARRX;

	// send the user action option through TX.
	for(int i=0;i<strlen(buf);i++){
		USART_Tx(USART1,buf[i]);
	}
	USART1->CMD =(USART1->CMD & ~_USART_CMD_CLEARRX_MASK)|USART_CMD_CLEARRX;

	rxData8 = USART_Rx(USART1);
	USART1->CMD =(USART1->CMD & ~_USART_CMD_CLEARRX_MASK)|USART_CMD_CLEARRX;

	switch (rxData8) {
	case 49:
		MADRE_Change_Config();
		break;
	case 50:
		break;
	}
}


/******************************************************************************
 * @name MADRE_Change_Config
 * @brief
 *   TODO
 * @details
 *	TODO
 * @Author A. Le Boyer
 *****************************************************************************/
void MADRE_Change_Config(void) {

	char buf0[100] = {"\0"};
	char buf1[100]= {"\0"};
	char buf2[100]= {"\0"};
	uint16_t rxData1 = 0;
	uint16_t rxData2 = 0;
	uint32_t param;
	sprintf(buf0,"1:Sensors \n 2: Whatever? \n");
	sprintf(buf1,"Number of sensor (default:%i,current:%i): \n",8,(int) map_setup_ptr->number_sensor);
	sprintf(buf2,"Setting up the new Start Date");
	for(int i=0;i<strlen(buf0);i++){
		USART_Tx(USART1,buf0[i]);
	}
	rxData1 = USART_RxDouble(USART1);
	USART1->CMD =(USART1->CMD & ~_USART_CMD_CLEARRX_MASK)|USART_CMD_CLEARRX;

	switch(rxData1){
		case 1:
			param=0;
			for(int i=0;i<strlen(buf1);i++){
				USART_Tx(USART1,buf1[i]);
			}
			rxData1 = USART_RxDouble(USART1);
			USART1->CMD =(USART1->CMD & ~_USART_CMD_CLEARRX_MASK)|USART_CMD_CLEARRX;
			param = (int32_t) rxData1;
			map_setup_ptr->number_sensor=param;
			sprintf(buf1,"new number of sensor %i \n",(int) param);
			for(int i=0;i<strlen(buf1);i++){
				USART_Tx(USART1,buf1[i]);
			}
			break;
		default:
			break;
	}
	// gather the the new Start date every time we enter in the menu mode
	for(int i=0;i<strlen(buf2);i++){
		USART_Tx(USART1,buf2[i]);
	}

	param=0;
	rxData1 = USART_RxDouble(USART1);
	USART1->CMD =(USART1->CMD & ~_USART_CMD_CLEARRX_MASK)|USART_CMD_CLEARRX;
	param = param | rxData1 <<16;
	rxData2 = USART_RxDouble(USART1);
	USART1->CMD =(USART1->CMD & ~_USART_CMD_CLEARRX_MASK)|USART_CMD_CLEARRX;
	param = param | rxData2;

	madre_setup_ptr->Start_time= (time_t) param;
	sprintf(buf2,"new date %i \n",(int) param);
	for(int i=0;i<strlen(buf2);i++){
		USART_Tx(USART1,buf2[i]);
	}

	clear_madre();
	standby4setup(1);
	MADRE_Config();


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
    init_CMU();
    init_GPIO();            // define GPIO pin mode for ADC and the 485, PA2 to send MCLOCK (for ADCs), and PE7 to send SYNC
	main_calendar_setup();  // set up date and start RTC. TODO: initialize the backRTC and start the LFXO
    init_MADRE();           // define the MADRE variables declare in common.h
	init_SPI();             // Initialize the SPI interface for the Analog front end
    init_MAP();             // Initialize the analog front end (i.e initialize the ADCs)
	setupGpioInt();         // Setup GPIO Interrupt but leave disabled. This interrupt is the one the collect the data from the ADC
    UART_Setup();           // initialize the 422 communication. this is the USER-MADRE communication port

	init_TIMER(coreclock_cycle,timer1_phase_shift); //set up timer MCLOCK and SYNC. MCLOCK (TIMER0) is send to the ADC

    standby4setup(0);       // delay so the user can change the date after power up the board. TODO: get rid of it when menu mode is working

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
	byte_per_sample    = map_setup_ptr->number_sensor*madre_setup_ptr->ADCword_length;          // 6 bytes per channel (hex) * number of channel+ \n
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
    while (RTC->CNT<delay*32768){
        if((USART1->STATUS & USART_STATUS_RXDATAV)){
            uint16_t rxData1 = 0;
        	uint16_t rxData2 = 0;
        	uint32_t param;
        	param=0;
        	rxData1 = USART_RxDouble(USART1);
        	param = param | rxData1 <<16;
        	rxData2 = USART_RxDouble(USART1);
        	param = param | rxData2;
        	madre_setup_ptr->Start_time= (time_t) param;
        }
    }
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

void clear_madre(void){
	memset(data_buffer, 0, sizeof(uint8_t)*buffer_size);
	memset(header_buffer, 0,sizeof(char)*header_length);
	memset(aux1_sample, 0,sizeof(uint8_t) *aux1_setup_ptr->Auxword_length);
	if(data_buffer) free(data_buffer);
	if(header_buffer) free(header_buffer);
	if(aux1_sample) free(aux1_sample);
	USART_Reset(USART1);
	USART_Reset(USART0);
}



