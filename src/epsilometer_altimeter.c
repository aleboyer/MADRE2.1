/*
 * epsilometer_altimeter.c
 *
 *  Created on: Jun 11, 2018
 *      Author: aleboyer
 */

#include "ep_altimeter.h"
#include "em_timer.h"
#include "em_rtc.h"

#define RTC_COUNTS_BETWEEN_ALTI     82
//#define RTC_COUNTS_BETWEEN_ALTI     120

// define the different state of the altimeter timer
enum alti_states {
  firstping,
  echo
};
enum alti_states alti_state;
int count = 0, blanktime,localcount,start_ping=0;
int nb_nearecho=0;
//int start_alti=0, blank_alti=0, time_echo=0;
void send_ping(){
	/* Enable overflow and CC0 interrupt */
	alti_state=firstping;
    count = 0;
	TIMER_IntClear(TIMER3, TIMER_IF_OF | TIMER_IF_CC0);
	TIMER_IntEnable(TIMER3, TIMER_IF_OF | TIMER_IF_CC0);
    GPIO_PinModeSet(gpioPortB, 7, gpioModePushPull, 1); 	//
	GPIO_PinModeSet(gpioPortB, 7, gpioModePushPull, 0); 	//
	GPIO_PinModeSet(gpioPortE, 15, gpioModePushPull, 1); 	//
    RTC_CompareSet(1,RTC->CNT + RTC_COUNTS_BETWEEN_ALTI);
	RTC_IntEnable(RTC->IEN | RTC_IEN_COMP1);
}

/**************************************************************************//**
 * @brief TIMER0_IRQHandler
 * Interrupt Service Routine TIMER0 Interrupt Line
 *****************************************************************************/
/* TOP reset value is 0xFFFF so it doesn't need
   to be written for this example */
#define TOP 0xFFFF
/* 39062 Hz -> 40Mhz (clock frequency) / 1024 (prescaler) */
#define TIMER_FREQ 39062


void TIMER3_IRQHandler(void)
{
  uint16_t intFlags = TIMER_IntGet(TIMER3);
  TIMER_IntClear(TIMER3, TIMER_IF_OF |  TIMER_IF_CC0);
  /* Overflow interrupt occured */
  if(intFlags & TIMER_IF_OF)
  {
    /* Increment the counter with TOP = 0xFFFF */
    count += TOP;
  }
  if(intFlags & TIMER_IF_CC0)
  {
	  switch (alti_state){
		  case firstping:
			  start_ping=TIMER3->CC[0].CCV;
			  alti_state=echo;
			  break;
		  case echo:
			  nb_nearecho++;
			  //localcount = TIMER_CaptureGet(TIMER3, 0);
			  localcount = TIMER3->CC[0].CCV;
			  blanktime = count + localcount-start_ping;
			  /* Multiply by 10000 to avoid floats */
			  blanktime = (blanktime * 10000) / TIMER_FREQ;
			  if (blanktime>800){ // 80 ms
				  localcount = TIMER3->CC[0].CCV;
				  echotime = count + localcount-start_ping;
				  //echotime = (echotime * 10000) / TIMER_FREQ;
				  GPIO_PinModeSet(gpioPortB, 7, gpioModePushPull, 1); 	//
				  GPIO_PinModeSet(gpioPortB, 7, gpioModePushPull, 0); 	//
				  TIMER_IntDisable(TIMER3, TIMER_IF_OF | TIMER_IF_CC0);
				  nb_nearecho=0;
			  }
			  break;
	}
  }
}

void Init_alti_TIMER(void){

	/* Select CC channel parameters */
	TIMER_InitCC_TypeDef timerCCInit =
	{
	  .eventCtrl  = timerEventRising,
	  .edge       = timerEdgeRising,
	  .prsSel     = timerPRSSELCh0,
	  .cufoa      = timerOutputActionNone,
	  .cofoa      = timerOutputActionNone,
	  .cmoa       = timerOutputActionNone,
	  .mode       = timerCCModeCapture,
	  .filter     = false,
	  .prsInput   = false,
	  .coist      = false,
	  .outInvert  = false,
	};

	/* Configure CC channel 0 */
	TIMER_InitCC(TIMER3, 0, &timerCCInit);

	/* Select timer parameters */
	TIMER_Init_TypeDef timerInit =
	{
	  .enable     = true,
	  .debugRun   = false,
	  .prescale   = timerPrescale1,
	  .clkSel     = timerClkSelHFPerClk,
	  .fallAction = timerInputActionNone,
	  .riseAction = timerInputActionStart,
	  .mode       = timerModeUp,
	  .dmaClrAct  = false,
	  .quadModeX4 = false,
	  .oneShot    = false,
	  .sync       = false,
	};


	/* Enable TIMER3 interrupt vector in NVIC */
	NVIC_EnableIRQ(TIMER3_IRQn);
	NVIC_SetPriority(TIMER3_IRQn, 2);

	/* Configure timer */
	TIMER_Init(TIMER3, &timerInit);
}



