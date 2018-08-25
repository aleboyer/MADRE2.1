/*
 * epsilometer_altimeter.c
 *
 *  Created on: Jun 11, 2018
 *      Author: aleboyer
 */

#include "ep_altimeter.h"
#include "em_timer.h"
#include "em_rtc.h"
#include "stdint.h"

//#define RTC_COUNTS_BETWEEN_ALTI     10
#define RTC_COUNTS_BETWEEN_ALTI     82     // 2.5 ms
//#define RTC_COUNTS_BETWEEN_ALTI     120

// define the different state of the altimeter timer
enum alti_states {
  firstping,
  echo,
  wait
};
enum alti_states alti_state;
uint32_t blanktime,localcount,start_ping=0;
int nb_nearecho=0;

//int start_alti=0, blank_alti=0, time_echo=0;
void send_ping(){
	/* Enable overflow and CC0 interrupt */
	alti_state=firstping;
    echotime=0;
    alti_count=0;
	TIMER_IntClear(TIMER3, TIMER_IF_CC0);
	TIMER_IntEnable(TIMER3,TIMER_IF_CC0);
	GPIO_PinModeSet(gpioPortB, 7, gpioModePushPull, 1);
	GPIO_PinModeSet(gpioPortB, 7, gpioModePushPull, 0);

	GPIO_PinModeSet(gpioPortE, 15, gpioModePushPull, 1);
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


void TIMER3_IRQHandler(void)
{
  /* Overflow interrupt occured */
  if(TIMER3->IF & TIMER_IF_OF)
  {
	TIMER_IntClear(TIMER3, TIMER_IF_OF);
    /* Increment the counter with TOP = 0xFFFF */
    alti_count += TOP;
  }
  if(TIMER3->IF & TIMER_IF_CC0)
  {
	  TIMER_IntDisable(TIMER3, TIMER_IF_CC0);
	  TIMER_IntClear(TIMER3, TIMER_IF_CC0);
	  localcount=alti_count + TIMER3->CC[0].CCV;
	  switch (alti_state){
		  case firstping:
			  start_ping= localcount;
			  alti_state=echo;
			  TIMER_IntEnable(TIMER3, TIMER_IF_CC0);
			  break;
		  case echo:
			  nb_nearecho++;
			  blanktime = localcount-start_ping;
			  if (blanktime>200000){ // 5* 4 0000 ms
				  echotime = blanktime;
				  GPIO_PinModeSet(gpioPortB, 7, gpioModePushPull, 1);
				  GPIO_PinModeSet(gpioPortB, 7, gpioModePushPull, 0);
				  alti_state=wait;
				  nb_nearecho=0;
			  }
			  else{
				  TIMER_IntEnable(TIMER3, TIMER_IF_CC0);
			  }
			  break;
	}
  }
  TIMER_IntClear(TIMER3, TIMER_IF_OF |  TIMER_IF_CC0);

}

void Init_alti_TIMER(void){

	/* Select CC channel parameters */
	TIMER_InitCC_TypeDef timerCCInit =
	{
	  .eventCtrl  = timerEventFalling,
	  .edge       = timerEdgeFalling,
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
	  .riseAction = timerInputActionNone,
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
	TIMER_IntEnable(TIMER3, TIMER_IF_OF);
	TIMER_Init(TIMER3, &timerInit);
}



