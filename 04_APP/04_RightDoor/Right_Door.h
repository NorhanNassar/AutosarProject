#ifndef _RIGHT_DOOR_H__
#define _RIGHT_DOOR_H__

/* Configurations for Left Door sensors */
#define RIGHT_DOOR  DOOR_SENSOR_CH0
/***************************************/

Error_Status RightDoor_Init(void);
Error_Status RightDoor_ReadStatus(u8 * Door_Status);

#endif
