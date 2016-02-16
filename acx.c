//Scott Shuffler

#include "acx.h"

int main () {
	x_init();
	x_new(T0_ID,thread0,0);
	x_new(T1_ID,thread1,0);
	while (1) {

	}
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
	x_thread_id = T0_ID;
	timer = 0;
	
	stack_control[0].p_base = (uint8_t *) thread0_start;
	stack_control[0].p_stack = (uint8_t *) thread0_start;
	stack_control[1].p_base = (uint8_t *) thread1_start;
	stack_control[1].p_stack = (uint8_t *) thread1_start;
	stack_control[2].p_base = (uint8_t *) thread2_start;
	stack_control[2].p_stack = (uint8_t *) thread2_start;
	stack_control[3].p_base = (uint8_t *) thread3_start;
	stack_control[3].p_stack = (uint8_t *) thread3_start;
	stack_control[4].p_base = (uint8_t *) thread4_start;
	stack_control[4].p_stack = (uint8_t *) thread4_start;
	stack_control[5].p_base = (uint8_t *) thread5_start;
	stack_control[5].p_stack = (uint8_t *) thread5_start;
	stack_control[6].p_base = (uint8_t *) thread6_start;
	stack_control[6].p_stack = (uint8_t *) thread6_start;
	stack_control[7].p_base = (uint8_t *) thread7_start;
	stack_control[7].p_stack = (uint8_t *) thread7_start;

	int i;
	for (i=0;i<MAX_THREADS;i++) {
		delay_counters[i] = (uint16_t) 0;
	}
	*((byte *)thread0_canary) = canary;
	*((byte *)thread1_canary) = canary;
	*((byte *)thread2_canary) = canary;
	*((byte *)thread3_canary) = canary;
	*((byte *)thread4_canary) = canary;
	*((byte *)thread5_canary) = canary;
	*((byte *)thread6_canary) = canary;
	*((byte *)thread7_canary) = canary;
}

/**
 * 
 * @param tid------------ defined thread id
 * @param pthread-------- Pointer to the thread function 
 * @param beginDisabled-- byte 0 or 1 to set enabled or disabled
 */
void x_new(byte tid, PTHREAD pthread, byte isEnabled) {
	//Toggle disable status
	if (!isEnabled) {
		disable_status |= 1 << tid;
	}
	else {
		disable_status &= ~(1 << tid);
	}
	createThreadStack((uint8_t *)pthread, tid);
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

/**
 * [thread0 description]
 */
void thread0() {

}

/**
 * [thread1 description]
 */
void thread1() {

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
		//SP = (uint16_t)pNewStack;
		retAddress = (uint8_t *)currSP;
		
		*(pNewStack-7) = retAddress[0];
		*(pNewStack-6) = retAddress[1];
		*(pNewStack-5) = retAddress[2];
		*(pNewStack-4) = retAddress[3];
		*(pNewStack-3) = retAddress[4];
		*(pNewStack-2) = retAddress[5];
		*(pNewStack-1) = retAddress[6];
		*(pNewStack) = retAddress[7];
		retValue = pNewStack;
	}
	
	// Interrupts on
	sei();
	
	return retValue;
}

void createThreadStack(uint8_t *pNewStack, byte TID) {
	*((uint8_t * ) SP) = *(pNewStack);
	*((uint8_t * ) SP - 1) = *(pNewStack + 1);
	*((uint8_t * ) SP - 2) = *(pNewStack + 2);
	stack_control[TID].p_stack = (uint8_t *) (stack_control[TID].p_stack - 0x15);
}

