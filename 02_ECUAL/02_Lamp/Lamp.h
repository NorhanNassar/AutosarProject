/************************************************************************
 * File name: Lamp.h
 *
 *
 * Description: This file contains The APIs for GPIO Driver and macros    
 * used by user 
 *
 * owner: Norhan Nassar
 * date: 25/2/2020
 * version 1.1
 *
 ***************************************************************************/
#ifndef _LAMP_H__
#define _LAMP_H__

/* Define Number of lamps in system */
#define Lamp_Count			1

/* Define each lamp channel in the system */
#define LAMP_CH0            0

/* Configurations for each lamp in the system */
#define LAMP_PORT_CH0		PORT_F
#define LAMP_PIN_CH0		1
#define LAMP_MODE_CH0		OUTPUT_PIN

/* L_ON to turn Lamp ON and L_OFF to turn it off */
#define L_ON				1
#define L_OFF				0

/************************************************************************
 * Function name: Lamp_Init
 *
 *  parameters:  Input: NA
 *              Output: NA
 *              In/out: NA

 * return: E_OK, E_NOK
 * Description: a function to configure Lamp channel in system to 
 * a certain port and pin 
 ***************************************************************************/
Error_Status Lamp_Init(void);

/************************************************************************
 * Function name: DoorSensor_Init
 *
 *  parameters:  Input:
 *                 LAMP_CH
 *                     type: u8
 *                      Description: Lamp channel to update its status to be ON or OFF
 *                      (LAMP_CH0)
 *                 LAMP_Status
 *                      type: u8
 *                      Description: Lamp Status to write this status to given lamp channel
 *              Output: NA
 *              In/out: NA

 * return: E_OK, E_NOK
 * Description: a function to update Lamp status to certain lamp channel
 ***************************************************************************/
Error_Status Lamp_Update(u8 LAMP_CH, u8 LAMP_Status);

#endif
