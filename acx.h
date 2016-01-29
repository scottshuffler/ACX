//Scott Shuffler

#include <stdint.h>

#define		x_getTID()		(x_thread_id)
#define		MAX_THREADS		8
#define		NUM_THREADS		8
typedef		uint8_t			byte;
typedef		uint8_t			bool;
typedef 	void			(*PTHREAD)(void);

#define		canary			0xDEADBEEF
#define 	thread0_start	RAMEND
#define		thread0_stop
#define		thread1_start
#define		thread1_stop

void x_init();
void x_new(byte tid, PTHREAD pthread, byte  isEnabled);
void x_yield();
void x_delay(int ticks);
void x_suspend(int tid);
void x_resume(int tid);
void x_disable(int tid);
void x_enable(int tid);
long g_time();