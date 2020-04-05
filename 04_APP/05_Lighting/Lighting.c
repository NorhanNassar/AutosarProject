#include "STD_TYPES.h"
#include "RTE.h"
#include "Lightning.h"


Error_Status Lighting_Control()
{
  Error_Status Local_Error = E_OK;
  u8 DoorStatus;
  Local_Error |= RTE_Read_Door_Status(&DoorStatus);
  Local_Error |= RTE_Write_Lamp_Status(DoorStatus);
  return Local_Error;
}

