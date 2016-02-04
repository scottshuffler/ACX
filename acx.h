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

#define		stack_size_0		256
#define		stack_size_1		256
#define		stack_size_2		256
#define		stack_size_3		256
#define		stack_size_4		256
#define		stack_size_5		256
#define		stack_size_6		256
#define		stack_size_7		256

#define		canary			0xBE

#define		T0_ID			0
#define		T1_ID			1
#define		T2_ID			2
#define		T3_ID			3
#define		T4_ID			4
#define		T5_ID			5
#define		T6_ID			6
#define		T7_ID			7


#define 	thread0_start	RAMEND
#define		thread0_stop	(thread0_start - stack_size_0)
#define		thread0_canary	thread0_stop


#define		thread1_start	(thread0_stop - 1)
#define		thread1_stop	(thread1_start - stack_size_1)
#define		thread1_canary	(thread1_stop)

#define		thread2_start	(thread1_stop - 1)
#define		thread2_stop	(thread2_start - stack_size_2)
#define		thread2_canary	(thread2_stop)

#define		thread3_start	(thread2_stop - 1)
#define		thread3_stop	(thread3_start - stack_size_3)
#define		thread3_canary	(thread3_stop)

#define		thread4_start	(thread3_stop - 1)
#define		thread4_stop	(thread4_start - stack_size_4)
#define		thread4_canary	(thread4_stop)

#define		thread5_start	(thread4_stop - 1)
#define		thread5_stop	(thread5_start - stack_size_5)
#define		thread5_canary	(thread5_stop)

#define		thread6_start	(thread5_stop - 1)
#define		thread6_stop	(thread6_start - stack_size_6)
#define		thread6_canary	(thread6_stop)

#define		thread7_start	(thread6_stop - 1)
#define		thread7_stop	(thread7_start - stack_size_7)
#define		thread7_canary	(thread7_stop)	

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
byte x_thread_mask;

struct control 
{
	uint8_t * p_base;
	uint8_t * p_stack;
};

uint32_t timer;