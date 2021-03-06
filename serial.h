/*
 * Serial.h
 *
 *  Author: shuffleres
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

//Data bits / Parity / Stop bits
// 5 Data / No Parity / 1 Stop
#define SERIAL_5N1 0x00
// 00 00 0 000

#define SERIAL_6N1 0x01
// 00 00 0 001

#define SERIAL_7N1 0x02
// 00 00 0 010

#define SERIAL_8N1 0x03
// 00 00 0 011

#define SERIAL_5N2 0x08
// 00 00 1 000

#define SERIAL_6N2 0x09
// 00 00 1 001

#define SERIAL_7N2 0x0A
// 00 00 1 010

#define SERIAL_8N2 0x0B
// 00 00 1 011

#define SERIAL_5E1 0x20
// 00 10 0 000

#define SERIAL_6E1 0x21
// 00 10 0 001

#define SERIAL_7E1 0x22
// 00 10 0 010

#define SERIAL_8E1 0x23
// 00 10 0 011

#define SERIAL_5E2 0x28
// 00 10 1 000

#define SERIAL_6E2 0x29
// 00 10 1 001

#define SERIAL_7E2 0x2A
// 00 10 1 010

#define SERIAL_8E2 0x2B
// 00 10 1 011

#define SERIAL_5O1 0x30
// 00 11 0 000

#define SERIAL_6O1 0x31
// 00 11 0 001

#define SERIAL_7O1 0x32
// 00 11 0 010

#define SERIAL_8O1 0x33
// 00 11 0 011

#define SERIAL_5O2 0x38
// 00 11 1 000

#define SERIAL_6O2 0x39
// 00 11 1 001

#define SERIAL_7O2 0x3A
// 00 11 1 010

#define SERIAL_8O2 0x3B
// 00 11 1 011


//Prototypes
void serial_open(long speed, int config);
char serial_read();
void serial_write(unsigned char write);



#endif /* SERIAL_H_ */