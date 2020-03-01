#include "STD_TYPES.h"
#include "Lamp.h"
#include "Lightning.h"

Error_Status Lighting_Init(void)
{
  Error_Status Local_Error = E_OK;
  Local_Error = Lamp_Init();
  return Local_Error;
}

Error_Status Lighting_Control(u8 Copy_u8LampStatus)
{
  Error_Status Local_Error = E_OK;
  if(Copy_u8LampStatus == L_ON || Copy_u8LampStatus == L_OFF)
  {
    Local_Error = Lamp_Update(LIGHTING_CH0,Copy_u8LampStatus);
  }
  else
  {
    Local_Error = E_NOK;
  }
  return Local_Error;
}

