#include "STD_TYPES.h"
#include "DoorSensor.h"
#include "Right_Door.h"

Error_Status RightDoor_Init(void)
{
  Error_Status Local_Error = E_OK;
  Local_Error = DoorSensor_Init(RIGHT_DOOR);
  return Local_Error;
}

Error_Status RightDoor_ReadStatus(u8 *Door_Status)
{
  Error_Status Local_Error = E_OK;
  Local_Error = DoorSensor_ReadStatus(RIGHT_DOOR,Door_Status);
  return Local_Error;
}
