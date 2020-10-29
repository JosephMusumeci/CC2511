/* ###################################################################
**     Filename    : main.c
**     Project     : Assign1
**     Processor   : MK22FN512VDC12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2020-10-27, 16:59, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Pins1.h"
#include "LED1.h"
#include "BitIoLdd1.h"
#include "LED2.h"
#include "BitIoLdd2.h"
#include "LED3.h"
#include "BitIoLdd3.h"
#include "FC321.h"
#include "RealTimeLdd1.h"
#include "TU1.h"
#include "BitSW.h"
#include "BitIoLdd4.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
#include <stdlib.h>
/* User includes (#include below this line is not maintained by Processor Expert) */
#include <stdbool.h>
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

	int c;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

//  LED3_ClrVal();
//  LED2_ClrVal();
//  LED1_ClrVal();

  for(;;)
  {
	  if(BitSW_GetVal());
	  {
//		  c = rand() %6;
		  c = 0;
		  if (c == 0) { //light up the First LED
			  LED1_ClrVal();
			  LED2_ClrVal();
			  LED3_ClrVal();
		  }
		  else if (c == 1) { //light up the Second LED
			  LED1_ClrVal();
			  LED2_ClrVal();
			  LED3_SetVal();
		  }
		  else if (c == 2) { //light up the Third LED
			  LED1_SetVal();
			  LED2_ClrVal();
			  LED3_ClrVal();
		  }
		  else if (c == 3) { //light up the Fourth LED
			  LED1_SetVal();
			  LED2_SetVal();
			  LED3_ClrVal();
		  }
		  else if (c == 4) { //light up the Fifth LED
			  LED1_ClrVal();
			  LED2_ClrVal();
			  LED3_SetVal();
		  }
		  else if (c == 5) { //light up the Sixth LED
			  LED1_SetVal();
			  LED2_ClrVal();
			  LED3_SetVal();
		  }
	  }
  }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
