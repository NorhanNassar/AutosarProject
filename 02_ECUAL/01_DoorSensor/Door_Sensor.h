#ifndef _DOORSENSOR_H__
#define _DOORSENSOR_H__

/* Define each Door sensor channel in the system */
#define DOOR_SENSOR_CH0		0
#define DOOR_SENSOR_CH1		1

/* Configurations for each Door Sensor in the system */
#define SENSOR_CH0_PORT		PORT_F
#define SENSOR_CH0_PIN		0
#define SENSOR_CH0_MODE		INPUT_PIN

#define SENSOR_CH1_PORT     PORT_F
#define SENSOR_CH1_PIN      4
#define SENSOR_CH1_MODE     INPUT_PIN

/*************************************************/
Error_Status DoorSensor_Init(u8 DOOR_SENSOR_ID);
Error_Status DoorSensor_ReadStatus(u8 Sensor_Ch, u8* Sensor_Status);

#endif
