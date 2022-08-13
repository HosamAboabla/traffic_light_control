/*
 * DIO.h
 *
 * Created: 8/12/2022 7:50:00 PM
 *  Author: hosam
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "DIO_Configurations.h"
// #include "DIO_Address.h"

// Prototypes for functions

// Prototypes for functions pin only
void DIO_SetPinDirection (Port port , Pin pin , State state);
void DIO_SetPinValue (Port port , Pin pin , Status status);
void DIO_TogglePinValue(Port port , Pin pin);
void DIO_ReadPinValue(Port port , Pin pin , uint8* reading);
void DIO_SetPinPullUp(Port port , Pin pin);

// Prototypes for functions for port only
void DIO_SetPortDirection(Port port , State state);
void DIO_SetPortValue(Port port , Status status);
void DIO_TogglePortValue(Port port);
uint8_t DIO_ReadPortValue(Port port);
// void DIO_SetPortPullUp(Port port , Pin pin);


void ViewPinValue_Format1(Port port , Pin pin , Status* status);
boolean ViewPinValue_Format2(Port port , Pin pin , Status* status);



#endif /* DIO_H_ */