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

extern task_t const DoorTasks;
extern task_t const SendTask;
taskInfo_t tasks[MAXTASKNUM]=
{
		{&HswitchTask,0,0},
		{&DoorTasks,1,0},
		{&SendTask,2,0}
};




