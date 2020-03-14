/************************************************************************
 * File name: Left_Door.h
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
#ifndef _LEFT_DOOR_H__
#define _LEFT_DOOR_H__

/* Configuration for Left Door sensor mapping */
#define LEFT_DOOR  DOOR_SENSOR_CH1

/************************************************************************
 * Function name: leftDoor_Init
 *
 * parameters:  Input: NA
 *              Output: NA
 *              In/out: NA
 * return: E_OK, E_NOK
 * Description: a function to intialize the Left door and map it to the corresponding 
 *              door sensor
 ***************************************************************************/
Error_Status leftDoor_Init(void);

/************************************************************************
 * Function name: LeftDoor_ReadStatus
 *
 * parameters:  Input: NA
 *              Output: NA
 *              In/out: Door_Status
 *                     type: pointer to u8
 *                      Description: Read if the door is opened or not opened
 * return: E_OK, E_NOK
 * Description: a function to read if the left door is opened or not 
 ***************************************************************************/
Error_Status LeftDoor_ReadStatus(u8 * Door_Status);

#endif