#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "HSwitch_cfg.h"
#include "HSwitch.h"
#include "RTE.h"
#include "Com_interface.h"
#include "OS_cfg.h"
#include "OS.h"

/*RTE Variables*/
static u8 Rte_RightDoor = DOOR_CLOSED;
static u8 Rte_LeftDoor = DOOR_CLOSED;
static u8 Rte_DoorsStatus = DOOR_CLOSED;
static u8 Rte_LampStatus = LIGHT_OFF;

extern const task_t LeftDoorTask,RightDoorTask,SendDoorStateTask,SendTask;


void Task_25msec_Runnable(void)
{
    LeftDoorTask.Runnable();
    RightDoorTask.Runnable();
}

void Task_50msec_Runnable(void)
{
	SendDoorStateTask.Runnable();
	SendTask.Runnable();
}

task_t const DoorTasks = {Task_25msec_Runnable,25};
task_t const SendTask = {Task_50msec_Runnable,50};


Error_Status RTE_Read_RightDoor_Status(u8* RightDoorS)
{
    *RightDoorS = Rte_RightDoor;
    return E_OK;
}

Error_Status RTE_Read_LeftDoor_Status(u8* LeftDoorS)
{
    *LeftDoorS = Rte_LeftDoor;
    return E_OK;
}

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

Error_Status RTE_Write_RightDoor_Status(u8 RightDoorS)
{
     Rte_RightDoor = RightDoorS;
     return E_OK;
}

Error_Status RTE_Write_LeftDoor_Status(u8 LeftDoorS)
{
    Rte_LeftDoor = LeftDoorS;
    return E_OK;
}

Error_Status RTE_Write_Door_Status(u8 DoorData)
{
    Rte_DoorsStatus = DoorData;
    return E_OK;
}
Error_Status RTE_Call_Send_Door_Status(void)
{
	return (Com_Send_Signal(SIGNAL_ID_1, Rte_DoorsStatus));

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

Error_Status RTE_Call_Read_RightDoor_Status(u8* RDoorStatus)
{
    return(Switch_getSwitchState(RIGHT_DOOR,RDoorStatus));
}

Error_Status RTE_Call_Read_LeftDoor_Status(u8* LDoorStatus)
{
    return(Switch_getSwitchState(LEFT_DOOR,LDoorStatus));
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

Error_Status RTE_Call_Start_Transmition(void){
	Com_Start_Transmition();
	return E_OK;
}


