#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

extern Error_Status setPinDir(u8 Port, u8 Pin, u8 Dir);
extern Error_Status setPinValue(u8 Port, u8 Pin, u8 val);
extern Error_Status getPinValue(u8 Port, u8 Pin,u8* Result);

#endif
