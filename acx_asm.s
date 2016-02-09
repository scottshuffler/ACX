/*
 * acx_asm.s
 *
 * Created: 
 * Author: efb
 */ 
 #define __SFR_OFFSET 0
 #include <avr/io.h>
 #include "acx.h"


		.section .text
		.global x_yield
x_yield:
//------------------------------------------------------------------
// Save "callee-save" registers
//------------------------------------------------------------------


//------------------------------------------------------------------
//   Get thread ID and mask
//------------------------------------------------------------------


//------------------------------------------------------------------
// Store SP into current thread's stack-save area
//------------------------------------------------------------------



;------------------------------------------------------------------------
; Schedule next thread -- must use caller-save registers below here
;                         because we can reach this without saving regs
;                         if entered from x_new() function
;-------------------------------------------------------------------------
		.global	x_schedule
x_schedule:
	// determine READY status of each thread




;------------------------------------------------
;   Loop through all threads to test for READY
;------------------------------------------------




;----------------------------------------------------------
;  SLEEP HERE:  Here's where we sleep (no threads are READY)
;  but for now we'll jump back to schedule loop again
;----------------------------------------------------------
		; add sleep instructions here...

		rjmp	x_schedule			

;---------------------------------------------------
; Restore context of next READY thread
;---------------------------------------------------
restore:
		//	restore SP from thread's sp
		
		
		
				
		// update hardware SP




		// Restore registers






		// Return to next thread
		ret