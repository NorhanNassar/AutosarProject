/************************************************************************
 * File name: Left_Door.c
 *
 *
 * Description: This file contains the implementation of the APIs of the 
 * Left Door Component
 *
 * owner: Mostafa Ramadan
 * date: 2/3/2020
 * version 1.1
 *
 ***************************************************************************/

/* The includes needed to initialize the left door component */
#include "STD_TYPES.h"
#include "DoorSensor.h"
#include "Left_Door.h"

/* this function is to initialize the left door and map it to the corresponding 
 * Door Sensor and return the error status of the function if it failed or succeeded */
Error_Status leftDoor_Init(void)
{
  /* Initialize the local error as E_OK status */
  Error_Status Local_Error = E_OK;
  
  /* Mapping the left door to the corresponding LEFT_DOOR Sensor and return 
   * the error status of the function if it is failed or succeeded */
  Local_Error = DoorSensor_Init(LEFT_DOOR);
  
  /* Return the status of the function E_NOK if there is a fail or E_OK if succeeded */
  return Local_Error;
}

/* this function is to read the status of the left door and check if it is opened or not 
 * and return the error status of the function if it failed or succeeded */
Error_Status LeftDoor_ReadStatus(u8 *Door_Status)
{
  /* Initialize the local error as E_OK status */
  Error_Status Local_Error = E_OK;
  
  /* reading the status of the left door if it is opened or not and return
   * the error status of the function if it failed or succeeded */
  Local_Error = DoorSensor_ReadStatus(LEFT_DOOR,Door_Status);
  
  /* Return the status of the function E_NOK if there is a fail or E_OK if succeeded */
  return Local_Error;
}