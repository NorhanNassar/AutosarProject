/*
 * OS_cfg.c
 *
 *  Created on: Apr 7, 2020
 *      Author: Norhan Nassar
 */
#include "STD_TYPES.h"
#include "OS.h"
#include "OS_cfg.h"

extern const task_t HswitchTask;
extern const task_t LeftDoorTask,RightDoorTask,DimmerTask,LampTask;

void Task_25msec_Runnable(void)
{
    LeftDoorTask.Runnable();
    RightDoorTask.Runnable();
}

void Task_50msec_Runnable(void)
{
    DimmerTask.Runnable();
    LampTask.Runnable();
}

taskInfo_t tasks[MAXTASKNUM]=
{
		{&HswitchTask,0,0},
		{&Task_25msec_Runnable,1,0},
		{&Task_50msec_Runnable,2,0}
};




