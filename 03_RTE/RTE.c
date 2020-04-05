#include "STD_TYPES.h"
#include "tivac_gpio.h"
#include "RTE.h"
/*RTE Variables*/
static u8 Rte_RightDoor = DOOR_CLOSED;
static u8 Rte_LeftDoor = DOOR_CLOSED;
static u8 Rte_DoorsStatus = DOOR_CLOSED;
static u8 Rte_LampStatus = LIGHT_OFF;

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

Error_Status RTE_Write_Lamp_Status(u8 LampStatus)
{
   Rte_LampStatus = LampStatus;
   return E_OK;
}

Error_Status RTE_Call_Read_RightDoor_Status(u8* RDoorStatus)
{
    return(D_GPIO_ReadPin(RIGHT_DOOR_PORT, RIGHT_DOOR_PIN,RDoorStatus));
}

Error_Status RTE_Call_Read_LeftDoor_Status(u8* LDoorStatus)
{
    return(D_GPIO_ReadPin(LEFT_DOOR_PORT, LEFT_DOOR_PIN, LDoorStatus));
}

Error_Status RTE_Set_Lamp_Status()
{
    return (D_GPIO_WritePin(LAMP_PORT, LAMP_PIN, ON));
}

Error_Status RTE_Reset_Lamp_Status()
{
    return (D_GPIO_WritePin(LAMP_PORT, LAMP_PIN, OFF));
}

Error_Status RTE_Call_Init_LeftDoor()
{
    return (D_GPIO_Init(LEFT_DOOR_PORT,LEFT_DOOR_PIN,LEFT_DOOR_MODE));
}

Error_Status RTE_Call_Init_RightDoor()
{
    return (D_GPIO_Init(RIGHT_DOOR_PORT,RIGHT_DOOR_PIN,RIGHT_DOOR_MODE));
}

Error_Status RTE_Call_Init_Lamp()
{
    return (D_GPIO_Init(LAMP_PORT,LAMP_PIN,LAMP_MODE));
}




