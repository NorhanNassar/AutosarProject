#include "STD_TYPES.h"
#include "OS.h"
#include "RTE.h"
#include "DoorContact.h"

void DoorContact_Read_Status(void)
{
    u8 RDoorStatus;
    u8 LDoorSensor;
    RTE_Read_LeftDoor_Status(&LDoorSensor);
    RTE_Read_RightDoor_Status(&RDoorStatus);
    RTE_Write_Door_Status(LDoorSensor|RDoorStatus);
    RTE_Call_Send_Door_Status();

}

task_t const SendDoorStateTask = {&DoorContact_Read_Status,50};
