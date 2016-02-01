//Scott Shuffler

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define		x_getTID()		(x_thread_id)
#define		MAX_THREADS		8
#define		NUM_THREADS		8
typedef		uint8_t			byte;
typedef		uint8_t			bool;
typedef 	void			(*PTHREAD)(void);

#define		stack_size		256
#define		canary			0x11

#define 	thread0_start	RAMEND
#define		thread0_stop	(thread0_start - stack_size)

#define		thread1_start	(thread0_stop - 1)
#define		thread1_stop	(thread1_start - stack_size)

#define		thread2_start	(thread1_stop - 1)
#define		thread2_stop	(thread2_start - stack_size)

#define		thread3_start	(thread2_stop - 1)
#define		thread3_stop	(thread3_start - stack_size)

#define		thread4_start	(thread3_stop - 1)
#define		thread4_stop	(thread4_start - stack_size)

#define		thread5_start	(thread4_stop - 1)
#define		thread5_stop	(thread5_start - stack_size)

#define		thread6_start	(thread5_stop - 1)
#define		thread6_stop	(thread6_start - stack_size)

#define		thread7_start	(thread6_stop - 1)
#define		thread7_stop	(thread7_start - stack_size)	

void x_init();
void x_new(byte tid, PTHREAD pthread, byte  isEnabled);
void x_yield();
void x_delay(int ticks);
void x_suspend(int tid);
void x_resume(int tid);
void x_disable(int tid);
void x_enable(int tid);
long g_time();
uint8_t * changeStack(uint8_t *pNewStack);

uint16_t delay_counters[8];

byte disable_status;
byte suspend_status;
byte delay_status;

struct control 
{
	uint8_t * p_base;
	uint8_t * p_stack;
};

uint32_t timer;