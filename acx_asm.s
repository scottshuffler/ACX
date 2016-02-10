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
push r2
push r3
push r4
push r5
push r6
push r7
push r8
push r9
push r10
push r11
push r12
push r13
push r14
push r15
push r16
push r17
push r28
push r29

//------------------------------------------------------------------
//   Get thread ID and mask
//------------------------------------------------------------------
lds r18, x_thread_id
lds r19, x_thread_mask 

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
pop r29
pop r28
pop r17
pop r16
pop r15
pop r14
pop r13
pop r12
pop r11
pop r10
pop r9
pop r8
pop r7
pop r6
pop r5
pop r4
pop r3
pop r2
		// Return to next thread
		ret