/*
 * epsilometer_altimeter.c
 *
 *  Created on: Jun 11, 2018
 *      Author: aleboyer
 */

#include "ep_altimeter.h"
#include "em_timer.h"


void send_ping(){
	GPIO_PinModeSet(gpioPortE, 15, gpioModePushPull, 1); 	//
	GPIO_PinModeSet(gpioPortE, 15, gpioModePushPull, 0); 	//
}

/**************************************************************************//**
 * @brief TIMER0_IRQHandler
 * Interrupt Service Routine TIMER0 Interrupt Line
 *****************************************************************************/
int count = 0, totalTime, localcount, localcount_old;
/* TOP reset value is 0xFFFF so it doesn't need
   to be written for this example */
#define TOP 0xFFFF
/* 39062 Hz -> 40Mhz (clock frequency) / 1024 (prescaler) */
#define TIMER_FREQ 39062


void TIMER3_IRQHandler(void)
{
  uint16_t intFlags = TIMER_IntGet(TIMER3);

  TIMER_IntClear(TIMER3, TIMER_IF_OF);

  /* Overflow interrupt occured */
  if(intFlags & TIMER_IF_OF)
  {
    /* Increment the counter with TOP = 0xFFFF */
    count += TOP;
  }
  TIMER_IntClear(TIMER3, TIMER_IF_CC0);

  /* Capture interrupt occured */
  if(intFlags & TIMER_IF_CC0)
  {
    /* Calculate total time of button pressing */
	localcount = TIMER_CaptureGet(TIMER3, 0);
	localcount_old=localcount;
    totalTime = count + localcount;
    /* Multiply by 1000 to avoid floats */
    totalTime = (totalTime * 1000) / TIMER_FREQ;
	GPIO_PinModeSet(gpioPortB, 7, gpioModePushPull, 1); 	//
	GPIO_PinModeSet(gpioPortB, 7, gpioModePushPull, 0); 	//


    /* Clear counter */
    count = 0;
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
	  .prescale   = timerPrescale1024,
	  .clkSel     = timerClkSelHFPerClk,
	  .fallAction = timerInputActionNone,
	  .riseAction = timerInputActionReloadStart,
	  .mode       = timerModeUp,
	  .dmaClrAct  = false,
	  .quadModeX4 = false,
	  .oneShot    = false,
	  .sync       = false,
	};

	/* Enable overflow and CC0 interrupt */
	TIMER_IntEnable(TIMER3, TIMER_IF_OF | TIMER_IF_CC0);

	/* Enable TIMER0 interrupt vector in NVIC */
	NVIC_EnableIRQ(TIMER3_IRQn);

	/* Configure timer */
	TIMER_Init(TIMER3, &timerInit);
}

