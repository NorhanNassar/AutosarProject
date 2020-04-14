#include "STD_TYPES.h"
#include "RTE.h"
#include "Left_Door.h"
#include "OS.h"

Error_Status LeftDoor_Init(void)
{
  return (RTE_Call_Init_LeftDoor());
}

void LeftDoor_ReadStatus_Runnable(void)
{
    u8 Door_Status;
    RTE_Call_Read_LeftDoor_Status(&Door_Status);
    RTE_Write_LeftDoor_Status(Door_Status);
}

task_t LeftDoorTask = {&LeftDoor_ReadStatus_Runnable,25};
