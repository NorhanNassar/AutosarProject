/************************************************************************
 * File name: Lighting.h
 *
 *
 * Description: This file contains the prototypes of the Lamp_Light Driver
 * and the macros used by the user
 *
 * owner: Mostafa Ramadan
 * date: 2/3/2020
 * version 1.1
 *
 ***************************************************************************/
#ifndef _LIGHTNING_H__
#define _LIGHTNING_H__

/* Defines every Lighting channel
 * Channel 0 for Lamp channel 0*/
#define LIGHTING_CH0  LAMP_CH0

#define LIGHT_ON        1
#define LIGHT_OFF       0


/************************************************************************
 * Function name: Lighting_Init
 *
 * parameters:  Input: NA
 *              Output: NA
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: a function to intialize the Dimmer lamp and map it to the corresponding 
 *              lamp sensor
 ***************************************************************************/
Error_Status Lighting_Init(void);

/************************************************************************
 * Function name: Lighting_Control
 *
 * parameters:  Input: NA
 *              Output: NA
 *              In/out: Copy_u8LampStatus
 *                     type: pointer to u8
 *                      Description: update the lamp status to L_ON or L_OFF
 * return: E_OK, E_NOK
 * Description: a function to control the dimmer lamp to be ON or OFF 
 ***************************************************************************/
Error_Status Lighting_Control(u8 *Copy_u8LampStatus);

#endif