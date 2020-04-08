#include "STD_TYPES.h"
#include "OS.h"
#include "RTE.h"
#include "RTE.h"


Error_Status RightDoor_Init(void)
{
  return (RTE_Call_Init_LeftDoor());
}

void RightDoor_ReadStatus_Runnable(void)
{
    u8 Door_Status;
    RTE_Call_Read_RightDoor_Status(&Door_Status);
    RTE_Write_RightDoor_Status(Door_Status);
}

task_t RightDoorTask = {&RightDoor_ReadStatus_Runnable,25};
