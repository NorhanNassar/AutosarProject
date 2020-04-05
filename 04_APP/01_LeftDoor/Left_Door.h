#ifndef _LEFT_DOOR_H__
#define _LEFT_DOOR_H__

/* Configurations for Left Door sensors */
#define LEFT_DOOR  DOOR_SENSOR_CH1
/****************************************/

Error_Status leftDoor_Init(void);
Error_Status LeftDoor_ReadStatus(u8 * Door_Status);

#endif
