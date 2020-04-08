#include "STD_TYPES.h"
#include "OS.h"
#include "RTE.h"
#include "DoorContact.h"

Error_Status DoorContact_ReadStatus(void)
{
    Error_Status loc_err = E_OK;
    u8 RDoorStatus;
    u8 LDoorSensor;
    loc_err |= RTE_Read_LeftDoor_Status(&LDoorSensor);
    loc_err |= RTE_Read_RightDoor_Status(&RDoorStatus);
    loc_err |= RTE_Write_Door_Status(LDoorSensor|RDoorStatus);
	return loc_err;
}
