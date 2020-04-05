#include "STD_TYPES.h"
#include "RTE.h"
#include "RTE.h"

Error_Status RightDoor_Init(void)
{
  return (RTE_Call_Init_LeftDoor());
}

Error_Status RightDoor_ReadStatus(u8 *Door_Status)
{
    Error_Status Local_Error = E_OK;
    Local_Error |= RTE_Call_Read_LeftDoor_Status(Door_Status);
    Local_Error |= RTE_Write_LeftDoor_Status(*Door_Status);
    return Local_Error;
}
