#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

Error_Status setPinDir(u8 Port, u8 Pin, u8 Dir);
Error_Status setPinValue(u8 Port, u8 Pin, u8 val);
Error_Status getPinValue(u8 Port, u8 Pin,u8* Result);

#endif
