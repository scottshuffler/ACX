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
;------------------------------------------------------------------
; Save "callee-save" registers
;------------------------------------------------------------------
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

;------------------------------------------------------------------
;   Get thread ID and mask
;------------------------------------------------------------------
	lds r23, x_thread_id
	lds r21, x_thread_mask 

;------------------------------------------------------------------
; Store SP into current thread's stack-save area
;------------------------------------------------------------------
	cli
	in r26, 0x3e ;SPH
	in r25, 0x3d ;SPL
	sei

;------------------------------------------------------------------------
; Schedule next thread -- must use caller-save registers below here
;                         because we can reach this without saving regs
;                         if entered from x_new() function
;						  (r18-r27, r30-r31)
;-------------------------------------------------------------------------
		.global	x_schedule
x_schedule:
	; determine READY status of each thread

	lds r18, disable_status
	lds r19, suspend_status
	lds r20, delay_status
	or r18, r19  
	or r18, r20 
	com r18 ; not or
	cpi r21, 0x80
	brne shift_left

set_to_hex_one:
	ldi r21, 0x01
	ldi r23, 0
	jmp bit2mask 

;------------------------------------------------
;   Loop through all threads to test for READY
;------------------------------------------------
shift_left:
	lsl r21
	inc r23

bit2mask:
	mov r22, r18
	and r22, r21
	cpi r22, 0x0
	brne  restore
	cpi r20, 0x80
	breq set_to_hex_one
	jmp shift_left



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
		;	restore SP from thread's sp
		
	ldi r30, lo8(stack_control)
	ldi r31, hi8(stack_control)
	mov r24, r23
	add r24, r24
	add r24, r24
	inc r24
	inc r24
	add r30, r24
	adc r31, r1
				
		; update hardware SP
	cli
	sts x_thread_mask, r21
	sts x_thread_id, r23
	ld r25, Z+
	ld r26, Z
	out 0x3e, r26 ;SPH
	out 0x3d, r25 ;SPL
	sei
		; Restore registers

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
		; Return to next thread
		ret
