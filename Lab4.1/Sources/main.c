/* ###################################################################
**     Filename    : main.c
**     Project     : Lab4.1
**     Processor   : MK22FN512VDC12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2020-08-22, 12:18, # CodeGen: 0
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
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
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

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/

    byte err;
    char c;    // char d = 'a'; // transmit the letter a

    for(;;) {

  	  do {
  	  err = AS1_RecvChar(&c); // component name = AS1
  	  } while (err != ERR_OK);
  	  // the received byte is in the variable c

  	  if (c == 'r' || c =='R')
  	  {
  		  Red_ClrVal(); // Turn Red LED on
  		  // send a message to the user!
  		  do {
  		  err = AS1_SendChar('a'); // component name = AS1
  		  } while (err != ERR_OK);

  	  }

  	  else
  	  {
  		  Red_SetVal(); // Turn Red LED off
  		  // send a message to the user!
  		  do {
  		  err = AS1_SendChar('x'); // component name = AS1
  		  } while (err != ERR_OK);

  	  }
  	  // the received byte is in the variable c
  	  // check for button presses if off turn on, if on turn off
  	  // Red -> R
  	  // Green -> G
  	  // Blue -> B
    }
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
