#include "STD_TYPES.h"
#include "RTE.h"
#include "DoorSensor.h"

Error_Status DoorSensor_ReadStatus()
{
    Error_Status loc_err = E_OK;
    u8 RDoorStatus;
    u8 LDoorSensor;
    loc_err |= RTE_Read_LeftDoor_Status(&LDoorSensor);
    loc_err |= RTE_Read_RightDoor_Status(&RDoorStatus);
    loc_err |= RTE_Write_Door_Status(LDoorSensor|RDoorStatus);
	return loc_err;
}
