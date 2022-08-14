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
DIO_ERROR_CODE DIO_SetPinDirection (Port port , Pin pin , State state);
DIO_ERROR_CODE DIO_SetPinValue (Port port , Pin pin , Status status);
DIO_ERROR_CODE DIO_TogglePinValue(Port port , Pin pin);





#endif /* DIO_H_ */