/************************************************************************
 * File name: Lighting.c
 *
 *
 * Description: This file contains the implementation of the APIs of the 
 * Dimmer Component
 *
 * owner: Mostafa Ramadan
 * date: 2/3/2020
 * version 1.1
 *
 ***************************************************************************/
 
/* The includes needed to initialize the Right door component */
#include "STD_TYPES.h"
#include "Lamp.h"
#include "Lightning.h"

/* this function is to initialize the Dimmer lamp and map it to the corresponding 
 * lamp sensor and return the error status of the function if it failed or succeeded */
Error_Status Lighting_Init(void)
{
  /* Initialize the local error as E_OK status */
  Error_Status Local_Error = E_OK;
  
  /* Initializing the Dimmer lamp at the initial state */
  Local_Error = Lamp_Init();
  
  /* Return the status of the function E_NOK if there is a fail or E_OK if succeeded */
  return Local_Error;
}

/* this function is control the status of the dimmer lamp to be LIGHT_ON or LIGHT_OFF   
 * and return the error status of the function if it failed or succeeded */
Error_Status Lighting_Control(u8 Copy_u8LampStatus)
{
  /* Initialize the local error as E_OK status */
  Error_Status Local_Error = E_OK;
  
  /* Check the status of the Dimmer lamp to be LIGHT_ON or LIGHT_OFF and return
   * the error status of the function if it failed or succeeded */
  if(Copy_u8LampStatus == LIGHT_ON || Copy_u8LampStatus == LIGHT_OFF)
  {
    /* updating the status of the Lamp corresponding to its Lamp Channel with its status and reading
     * the status of the function if it failed or succeeded */
    Local_Error = Lamp_Update(LIGHTING_CH0,Copy_u8LampStatus);
  }
  /* check if the status of the Dimmer lamp is not LIGHT_ON or LIGHT_OFF 
     then the function failed and return E_NOK */
  else
  {
    /* The function failed and the error value is E_NOK */
    Local_Error = E_NOK;
  }
  /* Return the status of the function E_NOK if there is a fail or E_OK if succeeded */
  return Local_Error;
}

