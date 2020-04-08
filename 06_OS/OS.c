#include "STD_TYPES.h"
#include "TIMER_interface.h"
#include "OS_cfg.h"
#include "OS.h"

static u8 schedStartFlag = 0;
extern taskInfo_t tasks[MAXTASKNUM];

static taskMoreInfo_t Systasks[MAXTASKNUM];
static Error_Status Sched_CreatTasks();

/* Call back function for timer handler, to increment the flag that a tick has arrived */
Error_Status Sched_SystickCbf(void)
{
	schedStartFlag++;				/* to handle a lot of one if an interrupt cut one while running */
	return E_OK;
}
/* at cfg file Tick time must be configured in milli sec	*/
Error_Status Sched_init(void)
{
	/* Init Timer to make an interrupt every tick time */
	Timer0_voidInit();
	Timer0_voidSetCallBack(&Sched_SystickCbf);
	Sched_CreatTasks();
	return E_OK;
}

Error_Status Sched_Start(void)
{
	Timer0_voidStart();
	while(1)
	{
		while(!schedStartFlag);			/* when tick is arrived schedStartFlag will not be zero */
		if(schedStartFlag>0)
			schedStartFlag--;			/* here is a runnable for one flag is going to be executed */
		Sched_Runnable();				/* then Sched will be executed */
	}
	return E_OK;
}

/* task struct has:
 * task Periodicity -> it must be in milli sec
 * firstDelayTicks -> first delay then task start to count
 * Runnable -> task function to execute
 * taskPriority -> it will return error if it exceeds the array of tasks limit */
Error_Status Sched_CreatTasks()
{
	u8 i;
	for(i=0;i<MAXTASKNUM;i++)
	{
		Systasks[tasks[i].periority].AppTask = tasks[i];
		Systasks[tasks[i].periority].ticksToExecute = tasks[i].task->Periodicity/TICKTIMEMS;
		Systasks[tasks[i].periority].taskState = READY;
	}
	return E_OK;
}

/* taskRunnable -> address of the task call back function that you want to suspend it */
Error_Status Task_Suspend(taskRunnable_t taskRunnable)
{
	u8 i;
	for(i=0;i<MAXTASKNUM;i++)
	{
		if(Systasks[i].AppTask.task->Runnable == taskRunnable)
		{
			Systasks[i].taskState = SUSPENDED;
			return E_OK;
		}
	}
	return E_NOK;
}

/* Period -> must be in milli sec
 * and it must be larger than task periodicity time
 * taskRunnable -> address of the task call back function that you want to sleep it */
Error_Status Task_Sleep(taskRunnable_t taskRunnable, u32 Copy_u32Period)
{
	Error_Status loc_err = E_NOK;
	/* task must be ready first to make it suspended    */
	/* and Period must be larger than task Periodicity */
	u8 i;
	for(i=0;i<MAXTASKNUM;i++)
	{
		if((Systasks[i].AppTask.task->Runnable == taskRunnable)
				&&(Systasks[i].taskState == READY)&&(Copy_u32Period>Systasks[i].AppTask.task->Periodicity))
		{
			Systasks[i].taskState = SLEEP;
			Systasks[i].countIfPause = Copy_u32Period / Systasks[i].AppTask.task->Periodicity;
			loc_err = E_OK;
		}
	}

	return loc_err;
}


void Sched_Runnable(void)
{
	u8 i;
	for(i=0;i<MAXTASKNUM;i++)
	{
		if(Systasks[i].ticksToExecute == 0)
		{
			switch(Systasks[i].taskState)
			{
			case READY:
				if(Systasks[i].AppTask.task->Runnable == NULL)
					break;
				if(Systasks[i].AppTask.firstDelayTicks==0)
					Systasks[i].AppTask.task->Runnable();
				break;
			case SLEEP:
				Systasks[i].countIfPause--;
				if(Systasks[i].countIfPause == 0)
					Systasks[i].taskState = READY;
				break;
			}

			Systasks[i].ticksToExecute = (Systasks[i].AppTask.task->Periodicity / TICKTIMEMS) - 1 ;
		}
		else
			Systasks[i].ticksToExecute--;
	}
}




