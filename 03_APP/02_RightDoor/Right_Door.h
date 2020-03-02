/************************************************************************
 * File name: Right_Door.h
 *
 *
 * Description: This file contains the prototypes of the Right Door driver
 * and the macros used by the user
 *
 * owner: Mostafa Ramadan
 * date: 2/3/2020
 * version 1.1
 *
 ***************************************************************************/
#ifndef _RIGHT_DOOR_H__
#define _RIGHT_DOOR_H__

/* Configuration for Right Door sensor mapping */
#define RIGHT_DOOR  DOOR_SENSOR_CH0


/************************************************************************
 * Function name: RightDoor_Init
 *
 * parameters:  Input: NA
 *              Output: NA
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: a function to intialize the right door and map it to the corresponding 
 *              door sensor
 ***************************************************************************/
Error_Status RightDoor_Init(void);


/************************************************************************
 * Function name: RightDoor_ReadStatus
 *
 * parameters:  Input: NA
 *              Output: NA
 *              In/out: Door_Status
 *                     type: pointer to u8
 *                      Description: Read if the door is opened or not opened
 * return: E_OK, E_NOK
 * Description: a function to read if the right door is opened or not 
 ***************************************************************************/
Error_Status RightDoor_ReadStatus(u8 * Door_Status);

#endif