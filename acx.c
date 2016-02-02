//Scott Shuffler

#include "acx.h"

int main () {
	x_init();
}

/**
 * x_init function
 * Initializes and sets up the stack for all threads
 */
void x_init() {
	disable_status = 0xFE;
	suspend_status = 0x00;
	delay_status = 0x00;
	x_thread_mask = 0x01;
	timer = 0;
	struct control stack_control[8];
	stack_control[0].p_base = (uint8_t *) thread0_start;
	stack_control[0].p_stack = (uint8_t *) thread0_start;
	int i;
	for (i=0;i<MAX_THREADS;i++) {
		delay_counters[i] = (uint16_t) 0;
	}

	*((byte *)thread0_canary) = canary;
	changeStack((uint8_t *)thread0_start);
}

/**
 * @param
 * @param
 * @param
 */
void x_new(byte tid, PTHREAD pthread, byte  isEnabled) {

}

/**
 * 
 */
void x_yield() {

}

/**
 * @param
 */
void x_delay(int ticks) {

}

/**
 * @param
 */
void x_suspend(int tid) {

}

/**
 * @param
 */
void x_resume(int tid) {

}

/**
 * @param
 */
void x_disable(int tid) {

}

/**
 * @param
 */
void x_enable(int tid) { 

}

/**
 * @return
 */
long g_time() {
	return 0;
}

uint8_t * changeStack(uint8_t *pNewStack) {
	// Interrupts off
	cli();
	
	// Set retValue to 0 so the default will fall through
	// Initializes a retAddress value used in the stack & upper and lower bounds
	uint8_t * retValue = (uint8_t *)0;
	uint8_t * retAddress = (uint8_t *)0;
	uint8_t * upper = (uint8_t *)0xFFFF;
	uint8_t * lower = (uint8_t *)0x200;
	
	// Ensures that the parameter given is between the correct bounds
	// Saves the current SP and sets the retAddress to this value
	// Moves the old stack to the new location allowing the stack to operate as normal
	// Sets the retValue to the parameter to return
	if (pNewStack > lower && pNewStack < upper) {
		
		uint16_t currSP = SP;
		SP = (uint16_t)pNewStack;
		retAddress = (uint8_t *)currSP;
		
		*(pNewStack)   = retAddress[0];
		*(pNewStack+1) = retAddress[1];
		*(pNewStack+2) = retAddress[2];
		*(pNewStack+3) = retAddress[3];
		*(pNewStack+4) = retAddress[4];
		*(pNewStack+5) = retAddress[5];
		*(pNewStack+6) = retAddress[6];
		*(pNewStack+7) = retAddress[7];
		retValue = pNewStack;
	}
	
	// Interrupts on
	sei();
	
	return retValue;
}

