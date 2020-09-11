/* Keil ARM C Startup library
 *    Copyright © 2005 Freescale semiConductor Inc. All Rights Reserved.
 *
 * $Date: 2011/09/21 06:41:34 $
 * $Revision: 1.4 $
 */


/*
 *	startup.c	-	entry-point for ARM programs
 *
 */

#include "IO_Map.h"

extern void __init_registers(void);
extern void __init_hardware(void);

void __attribute__ ((weak)) __init_registers(void)
{
  #if defined(SCB_CPACR)
  /* Initialize FPU */
  SCB_CPACR |= SCB_CPACR_CP10(3U) | SCB_CPACR_CP11(3U); 
  #endif

}

void __attribute__ ((weak)) __init_hardware(void)
{

}

void __thumb_startup(void);

__asm void __thumb_startup(void) {
  IMPORT  __init_registers
  IMPORT  __init_hardware 
  IMPORT  __main
  LDR     R0, =__init_registers
  BLX     R0
  LDR     R0, =__init_hardware
  BLX     R0
  LDR     R0, =__main
  BX      R0
  ALIGN 4
}
