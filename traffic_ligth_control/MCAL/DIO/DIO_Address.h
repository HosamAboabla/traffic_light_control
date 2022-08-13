/*
 * DIO_Address.h
 *
 * Created: 8/12/2022 7:50:30 PM
 *  Author: hosam
 */ 


#ifndef DIO_ADDRESS_H_
#define DIO_ADDRESS_H_


#define PORTA (*(volatile uint8_t*) 0x3B)
#define DDRA (*(volatile uint8_t*) 0x3A)
#define PINA (*(volatile uint8_t*) 0x39)


#define PORTB (*(volatile uint8_t*) 0x38)
#define DDRB  (*(volatile uint8_t*) 0x37)
#define PINB  (*(volatile uint8_t*) 0x36)

#define PORTC (*(volatile uint8_t*) 0x35)
#define DDRC  (*(volatile uint8_t*) 0x34)
#define PINC  (*(volatile uint8_t*) 0x33)

#define PORTD (*(volatile uint8_t*) 0x32)
#define DDRD (*(volatile uint8_t*) 0x31)
#define PIND (*(volatile uint8_t*) 0x30)




#endif /* DIO_ADDRESS_H_ */