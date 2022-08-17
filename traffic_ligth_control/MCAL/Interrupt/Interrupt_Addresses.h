/*
 * Interrupt_Addresses.h
 *
 * Created: 12/10/2021 1:38:20 PM
 *  Author: hosam
 */ 


#ifndef INTERRUPT_ADDRESSES_H_
#define INTERRUPT_ADDRESSES_H_

#define SREG	(*(volatile uint8_t*) 0x5F)
#define GICR	(*(volatile uint8_t*) 0x5B)
#define GIFR	(*(volatile uint8_t*) 0x5A)
#define MCUCR	(*(volatile uint8_t*) 0x55)
#define MCUCSR	(*(volatile uint8_t*) 0x54)


#endif /* INTERRUPT_ADDRESSES_H_ */