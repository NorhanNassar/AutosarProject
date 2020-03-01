#include "STD_TYPES.h"
#include "DoorSensor.h"
#include "Left_Door.h"


Error_Status leftDoor_Init(void)
{
  Error_Status Local_Error = E_OK;
  Local_Error = DoorSensor_Init(LEFT_DOOR);
  return Local_Error;
}

Error_Status LeftDoor_ReadStatus(u8 *Door_Status)
{
  Error_Status Local_Error = E_OK;
  Local_Error = DoorSensor_ReadStatus(LEFT_DOOR,Door_Status);
  return Local_Error;
}
