#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "RTE.h"
#include "Com_interface.h"
#include "OS_cfg.h"
#include "OS.h"

/*RTE Variables*/
static u8 Rte_DoorsStatus = DOOR_CLOSED;
static u8 Rte_LampStatus = LIGHT_OFF;

extern const task_t DimmerTask,LampTask,ReceiveTask;


void Task_50msec_Runnable(void)
{
	ReceiveTask.Runnable();
	DimmerTask.Runnable();
    LampTask.Runnable();

}

extern task_t const LightingTasks = {Task_50msec_Runnable,50};



Error_Status RTE_Read_Door_Status(u8* DoorData)
{
    *DoorData = Rte_DoorsStatus;
    return E_OK;
}

Error_Status RTE_Read_Lamp_Status(u8* LampStatus)
{
    *LampStatus = Rte_LampStatus;
    return E_OK;
}

Error_Status RTE_Write_Door_Status(u8 DoorData)
{
    Rte_DoorsStatus = DoorData;
    return E_OK;
}

Error_Status RTE_Write_Lamp_Status(u8 LampStatus)
{
   Rte_LampStatus = LampStatus;
   return E_OK;
}

Error_Status RTE_Call_Read_Door(u32 Port,u32 Pin,u8* Door)
{
    return(getPinValue(Port, Pin,Door));
}


Error_Status RTE_Set_Lamp_Status()
{
    return (setPinValue(LAMP_PORT, LAMP_PIN, ON));
}

Error_Status RTE_Reset_Lamp_Status()
{
    return (setPinValue(LAMP_PORT, LAMP_PIN, OFF));
}

Error_Status RTE_Call_Init_LeftDoor()
{
    return (setPinDir(LEFT_DOOR_PORT,LEFT_DOOR_PIN,LEFT_DOOR_MODE));
}

Error_Status RTE_Call_Init_RightDoor()
{
    return (setPinDir(RIGHT_DOOR_PORT,RIGHT_DOOR_PIN,RIGHT_DOOR_MODE));
}

Error_Status RTE_Call_Init_Lamp()
{
    return (setPinDir(LAMP_PORT,LAMP_PIN,LAMP_MODE));
}
Error_Status RTE_Call_Recieve_Door_Status()
{
    return (Com_Recieve_Signal(SIGNAL_ID_1,&Rte_DoorsStatus));
}






