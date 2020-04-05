#include "STD_TYPES.h"
#include "RTE.h"
#include "Left_Door.h"


Error_Status leftDoor_Init(void)
{
  return (RTE_Call_Init_LeftDoor());
}

Error_Status LeftDoor_ReadStatus(u8 *Door_Status)
{
    Error_Status Local_Error = E_OK;
    Local_Error |= RTE_Call_Read_LeftDoor_Status(Door_Status);
    Local_Error |= RTE_Write_LeftDoor_Status(*Door_Status);
    return Local_Error;
}
