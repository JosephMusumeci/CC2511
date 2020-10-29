/* ###################################################################
**     Filename    : main.c
**     Project     : lab_4
**     Processor   : MK22FN512VDC12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2020-08-27, 11:15, # CodeGen: 0
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
#include "AS1.h"
#include "ASerialLdd1.h"
#include "RED.h"
#include "BitIoLdd1.h"
#include "GREEN.h"
#include "BitIoLdd2.h"
#include "BLUE.h"
#include "BitIoLdd3.h"
#include "String.h"
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"


void send_string(const char *str)
{
		size_t len, i; // a size_t is an unsigned integer
		len = strlen(str); // returns the number of chars in str
		byte err;
		for (i = 0; i < len; i++) {
			// send this character
			do {
				 err = AS1_SendChar(str[i]);
			} while (err != ERR_OK);
		}
}

/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  RED_SetVal();
  GREEN_SetVal();
  BLUE_SetVal();


  for(;;){
	  byte err;
	  char c;
	  do {
		  err = AS1_RecvChar(&c);
	  } while (err != ERR_OK);
	  if (c == 'r' || c == 'R')
	  {
		  send_string("TOGGLED RED LED\r\n");
		  RED_NegVal();
	  }
	  if (c == 'g' || c == 'G')
	  {
		  send_string("TOGGLED GREEN LED\r\n");
		  GREEN_NegVal();
	  }
	  if (c == 'b' || c == 'B')
	  {
		  send_string("TOGGLED BLUE LED\r\n");
		  BLUE_NegVal();
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
