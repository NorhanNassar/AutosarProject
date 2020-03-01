#include "STD_TYPES.h"
#include "tivac_gpio.h"
#include "DoorSensor.h"

Error_Status DoorSensor_Init(u8 DOOR_SENSOR_ID)
{
	Error_Status loc_err = E_OK;
	switch(DOOR_SENSOR_ID)
	{
		case DOOR_SENSOR_CH0:
		loc_err = D_GPIO_Init(SENSOR_CH0_PORT,SENSOR_CH0_PIN,SENSOR_CH0_MODE);
		break;

		case DOOR_SENSOR_CH1:
		loc_err = D_GPIO_Init(SENSOR_CH1_PORT,SENSOR_CH1_PIN,SENSOR_CH1_MODE);
		break;

		default:
		loc_err = E_NOK;
		break;
	}
	return loc_err;
	
}

Error_Status DoorSensor_ReadStatus(u8 Sensor_Ch, u8* Sensor_Status)
{
	Error_Status loc_err = E_OK;
	u8 Data;
	switch(Sensor_Ch)
	{
		case DOOR_SENSOR_CH0:
		loc_err = D_GPIO_ReadPin(SENSOR_CH0_PORT,SENSOR_CH0_PIN,&Data);
		*Sensor_Status = Data;
		break;

		case DOOR_SENSOR_CH1:
		loc_err = D_GPIO_ReadPin(SENSOR_CH1_PORT,SENSOR_CH1_PIN,&Data);
		*Sensor_Status = Data;
		break;

		default:
		loc_err = E_NOK;
		break;
	}
	return loc_err;
}
