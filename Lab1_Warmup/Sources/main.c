/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "MK22F51212.h"
#include <stdbool.h>

static int i = 0;

void wait(int t) {
	int counter;
	for (counter = 0; counter < t; counter++) {
		// waste time using the "no-operation" assembly instruction
		__asm volatile ("nop");
	}
}

void clear_leds() {
	GPIOA_PSOR = (1 << 1);
	GPIOA_PSOR = (1 << 2);
	GPIOD_PSOR = (1 << 5);
}

int main(void)
{
	// Enable the clock for the port control module
	// SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTE_MASK;
	SIM->SCGC5 = 0x3e00;

	// Initialise the red LED
	PORTA->PCR[1] = 0x100; // Select GPIO mode
	GPIOA_PDDR = GPIOA_PDDR | (1 << 1); // set PTA1 to output

	// Initialise the green LED
	PORTA->PCR[2] = 0x100; // Select GPIO mode
	GPIOA_PDDR = GPIOA_PDDR | (1 << 2); // set PTA2 to output

	// Initialise the blue LED
	PORTD->PCR[5] = 0x100; // Select GPIO mode
	GPIOD_PDDR = GPIOD_PDDR | (1 << 5); // set PTD5 to output


	// Flash the LED
	int counter;
	for (;;) {

		clear_leds();

		GPIOA_PCOR = (1 << 1); // flash red
		wait(1000000);
		clear_leds();
		wait(1000000);

		GPIOA_PCOR = (1 << 2); // flash green
		wait(1000000);
		clear_leds();
		wait(1000000);

		GPIOD_PCOR = (1 << 5); // flash blue
		wait(1000000);
		clear_leds();
		wait(1000000);

		GPIOA_PCOR = (1 << 1); // flash red
		GPIOD_PCOR = (1 << 5); // flash blue
		wait(1000000);
		clear_leds();
		wait(1000000);

		GPIOA_PCOR = (1 << 1); // flash red
		GPIOA_PCOR = (1 << 2); // flash green
		wait(1000000);
		clear_leds();
		wait(1000000);

		GPIOD_PCOR = (1 << 5); // flash blue
		GPIOA_PCOR = (1 << 2); // flash green
		wait(1000000);
		clear_leds();
		wait(1000000);

		GPIOA_PCOR = (1 << 1); // flash red
		GPIOD_PCOR = (1 << 5); // flash blue
		GPIOA_PCOR = (1 << 2); // flash green
		wait(1000000);
		clear_leds();
		wait(1000000);
	}
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
