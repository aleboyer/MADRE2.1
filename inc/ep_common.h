/*
 * ep_common.h
 *
 *  Created on: Nov 30, 2017
 *      Author: A. LeBoyer
 */

#ifndef EP_COMMON_H_
#define EP_COMMON_H_


/******************************************************************************/
/***************************** Include Files **********************************/
/******************************************************************************/

#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "ff.h"
#include "time.h"
#include "ep_DMA.h"

/*************************************************************************/
/* define epsilometer parameters info to be put into the header data   */
/*************************************************************************/

#define NUMBER_SENSORS 7

typedef struct MadreSetup {
	uint32_t 	core_clock;             // frequency of the cristal
	uint32_t	maximum_samples;        // max number of sample in the dataBuffer. A sample is all the channels data + timestamp if timeStampflag=1 (default 320)
	uint32_t    pinInterupt;            // GPIO used to trigger the sample interrupt.
	uint32_t	blocksize;              // nb of EPSI sample for in one block. We stream and SD write whole blocks (default 160)
	uint32_t	sample_frequency;       // sample frequency in Hz used in epsilometer_analog.c define_ADC_configuration
	uint32_t    master_clock_frequency; // frequency in Hz of the clock used by the ADC
	uint32_t    timer1Sync;             // so far number of cycle of the master clock to trigger TIMER1 which will sync all the ADC togther
	uint32_t	spi_baudrate;           // baudrate of the spi bus: ADC to MCU communication (1MHz)
	uint32_t	usart_baudrate;         // baudrate ot the RS232 TX/RX (default 460800)
	uint32_t	ADCword_length;         // ADC word length (binary is 3 bits and hexa is 6 bits)
	time_t 	    Start_time;             // Start time in Unix time default is 1 January 2017 00:00:00
	uint32_t    AUX_flag;               // Auxiliary flag
} MadreSetup, *MadreSetupPtr;

typedef struct MapSetup {
	uint32_t 	number_sensor;               // number of sensor used. It will always go from 1 to numSensor in the list define in the main
	uint8_t 	sensorID[NUMBER_SENSORS];    //
} MapSetup, *MapSetupPtr;

// Aux 1 is by default Sea Bird 49
typedef struct AuxSetup {
	uint32_t	usart_baudrate;         // baudrate ot the RS232 TX/RX default(SBE baud rate 38400)
	uint32_t  	Auxword_length;         // Aux word length
	uint32_t  	aux_frequency;          // Aux frequency in hertz
	uint8_t  	endchar;                // default \n
} AuxSetup, *AuxSetupPtr;

// TODO change time_t to a fixed type and then cast the variable Start_time when called

//TODO get rid of the variable with different size.


/*************************************************************************/
/* define the default epsilometer structure                              */
/*************************************************************************/

#define MADRE_SETUP_DEFAULT      \
{40000000,                       \
320,                             \
0x200,                           \
160,                             \
320,                             \
625000,                          \
0x13,                            \
2000000,                         \
460800,                          \
3,								 \
1483228800,                      \
1}
//default TX baud  460800

#define MAP_SETUP_DEFAULT         \
{7,                               \
{0,1,2,3,5,6,7}                   \
}

#define SBE49_SETUP_DEFAULT       \
{                                 \
38400,                            \
24,                               \
16,                               \
10                                \
}
// \n = 10 in acscii

/*************************************************************************/
/* SD card filename                                                      */
/*************************************************************************/

// define the name of the file we open on the SD card
#define FILENAME "ep_test.bin"
#define FILENAME1 "ep_test"
#define FILENAME_SUFFIXE ".bin"
TCHAR filename[256];
FIL fsrc;					// File objects


/*************************************************************************/
/* Define the different States                                           */
/*************************************************************************/

// define the different state of MADRE (not use in this Application note)
enum madre_states {
  Sampling,
  Menu
};
enum madre_states madre_state;

//enum madre_states madre_state;

// define the different state of TX channel (not use in this Application note)
enum tx_states {
  TransmitHeader,
  TransmitAux1,
  TransmitAux2,
  TransmitMap,
  Stop,
  SetUp
};
enum tx_states tx_state;

// define the different state of TX channel (not use in this Application note)
enum sd_states {
  WriteHeader,
  WriteAux1,
  WriteAux2,
  WriteMap,
  Wait
};
enum sd_states sd_state;

/*************************************************************************/
/*    define global external values  									 */
/*************************************************************************/

int32_t  byte_per_sample;     // number of bytes per Sample
uint32_t buffer_size;        // numChannel*maxSamples

/*************************************************************************/
/* define circular buffer for the samples.   */
/*************************************************************************/

// MADRE variable
extern MadreSetupPtr  madre_setup_ptr;

uint8_t * data_buffer;                  // main buffer for EPSI samples. Size of MadreSetup.maximumSample. Memory is allocated in the main
char * header_buffer;                   // buffer the header block. Memory is allocated in the main
volatile uint32_t map_bytes_sent;       // counter for nb byte from the Epsi block send to 422
volatile uint32_t header_bytes_sent;    // counter for nb byte from the Header send to 422
volatile uint32_t header_length;        // length of the header
volatile uint32_t sd_block;             // number of "block" sent on the SD
volatile uint32_t gulclockset;          // used in the interrupt enabling the HFXO. Glitch detector.
volatile uint32_t bytes_per_block;      // nb of EPSI bytes in 1 block
volatile uint32_t tx_pending_bytes;     // ?? what is the difference with map_bytes sent??
volatile uint32_t sd_bytes_sent;        // number of bytes send on the sd_card
volatile uint32_t tx_block_sent;        // number of blocks sent through 422
volatile uint32_t block_chcksum;        // checksum for the Epsi sample updated at every sample
volatile uint32_t chcksum_block_header; // final checksum for the header to send re-initialize after every block
volatile uint32_t epsi_stamp_block;     // epsi sample count for the Header
volatile uint32_t voltage;              // epsi sample count for the Header
uint err_write;            // error when writing on the sd
uint err_sync;             // error when sync the sd



// Epsi sample variable
volatile uint32_t pending_samples;    // counter for samples gathered from the ADC
volatile uint32_t sensorID;           // ID number of the probe
volatile uint32_t number_sensor;      // ID number of the probe

// MAP variable
char *   mapheader;
volatile uint32_t count_analog;
volatile uint32_t coreclock_cycle;
volatile uint32_t timer1_phase_shift;

//Auxiliary Sea bird variable
uint8_t *   aux1header;
extern MapSetupPtr   map_setup_ptr;
extern AuxSetupPtr  aux1_setup_ptr;

uint8_t * aux1_buffer;			        // Aux1 buffer. memory Allocation in init_aux.c
uint8_t * aux1_sample;			        // Aux1 sample. Read with DMA.
uint8_t * aux1_end_block;               // fill up the end of the SD block when needed
volatile uint32_t aux1_count;           // counter for samples gathered from the aux
volatile uint32_t aux1_epsicount;       // counter for samples gathered from the aux
volatile uint32_t aux1_bytes_sent;      // counter for nb byte send on the SD card
volatile uint32_t aux1_buffer_length;
volatile uint32_t aux1_word_length;
volatile uint32_t aux1sample_per_block;
volatile uint32_t chcksum_aux1_header;  // final checksum to send re-initialize after every block

//Auxiliary 2 variable
//AuxSetup     aux2_setup = SBE49_SETUP_DEFAULT;   // default user parameter
//AuxSetupPtr  aux2_setup_ptr = &aux2_setup;        // default user parameter
char    * aux2_buffer;			    // Aux1 buffer. memory Allocation in init_aux.c
uint8_t * aux2_sample;			    // Aux1 sample. Read with DMA.
uint8_t * aux2_end_block;           // fill up the end of the SD block when needed
volatile uint32_t aux2_samples;      // counter for samples gathered from the aux
volatile uint32_t aux2_bytes_sent;   // counter for nb byte send on the SD card
volatile uint32_t aux2_buffer_length;
volatile uint32_t aux2_chcksum;      //
volatile uint32_t chcksum_aux2_header;  // final checksum to send re-initialize after every block



#endif /* EP_COMMON_H_ */
