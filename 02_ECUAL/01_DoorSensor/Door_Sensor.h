/************************************************************************
 * File name: Door_Sensor.h
 *
 *
 * Description: This file contains The APIs for Door_Sensor Driver and macros     
 * used by user         
 *
 * owner: Norhan Nassar
 * date: 25/2/2020
 * version 1.1
 *
 ***************************************************************************/
#ifndef _DOORSENSOR_H__
#define _DOORSENSOR_H__

/* Define each Door sensor channel in the system */
#define DOOR_SENSOR_CH0		0
#define DOOR_SENSOR_CH1		1

/* Configurations for each Door Sensor in the system */
#define SENSOR_CH0_PORT		PORT_F
#define SENSOR_CH0_PIN		0
#define SENSOR_CH0_MODE		INPUT_PIN

#define SENSOR_CH1_PORT     PORT_F
#define SENSOR_CH1_PIN      4
#define SENSOR_CH1_MODE     INPUT_PIN

/************************************************************************
 * Function name: DoorSensor_Init
 *
 *  parameters:  Input:
 *                 DOOR_SENSOR_ID
 *                     type: u8
 *                      Description: Sensor ID to configure it to a certain Port and pin
 *                      (DOOR_SENSOR_CH0 .. till last sensor id at system) 
 *
 *              Output: NA
 *              In/out: NA

 * return: E_OK, E_NOK
 * Description: a function to configure certain sensor id to a certain port
 * and pin as given at configuration 
 ***************************************************************************/
Error_Status DoorSensor_Init(u8 DOOR_SENSOR_ID);

/************************************************************************
 * Function name: DoorSensor_ReadStatus
 *
 *  parameters:  Input:
 *                 Sensor_Ch
 *                     type: u8
 *                      Description: Sensor ID to read its status
 *              Output: NA
 *              In/out: NA

 * return: E_OK, E_NOK
 * Description: a function to read status for certain sensor id and return
 * its status at pointer
 ***************************************************************************/
Error_Status DoorSensor_ReadStatus(u8 Sensor_Ch, u8* Sensor_Status);

#endif
