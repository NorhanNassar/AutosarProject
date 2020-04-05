#ifndef RTE_H
#define RTE_H

# define DOOR_OPEN      1
# define DOOR_CLOSED    0
# define LIGHT_ON       1
# define LIGHT_OFF      0

#define RIGHT_DOOR_PORT        PORT_F
#define RIGHT_DOOR_PIN          0
#define RIGHT_DOOR_MODE        INPUT_PIN

#define LEFT_DOOR_PORT         PORT_F
#define LEFT_DOOR_PIN          4
#define LEFT_DOOR_MODE         INPUT_PIN

#define LAMP_PORT               PORT_F
#define LAMP_PIN                1
#define LAMP_MODE               OUTPUT_PIN

#define ON                      1
#define OFF                     0

Error_Status RTE_Read_RightDoor_Status(u8* RightDoorS);

Error_Status RTE_Read_LeftDoor_Status(u8* LeftDoorS);

Error_Status RTE_Read_Door_Status(u8* DoorData);

Error_Status RTE_Read_Lamp_Status(u8* LampStatus);

Error_Status RTE_Write_RightDoor_Status(u8 RightDoorS);

Error_Status RTE_Write_LeftDoor_Status(u8 LeftDoorS);

Error_Status RTE_Write_Door_Status(u8 DoorData);

Error_Status RTE_Write_Lamp_Status(u8 LampStatus);

Error_Status RTE_Call_Read_RightDoor_Status(u8* RDoorStatus);

Error_Status RTE_Call_Read_LeftDoor_Status(u8* LDoorStatus);

Error_Status RTE_Set_Lamp_Status();

Error_Status RTE_Reset_Lamp_Status();

Error_Status RTE_Call_Init_LeftDoor();

Error_Status RTE_Call_Init_RightDoor();

Error_Status RTE_Call_Init_Lamp();

#endif
