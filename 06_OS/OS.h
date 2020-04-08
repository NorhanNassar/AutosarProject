#ifndef OS_H
#define OS_H

typedef u8 taskState_t;
typedef void (*taskRunnable_t)(void);
#define NULL ((void *)0)

#define SUSPENDED			0
#define READY				1
#define SLEEP				2
#define IDEAL				3

/* struct for user */
typedef struct
{
	taskRunnable_t Runnable;			/* Pointer to Task Function */
	u32 Periodicity;					/* time in milli sec 		*/
} task_t;

typedef struct
{
	task_t* task;
	u8 periority;
	u8 firstDelayTicks;					/* first delay in Ticks 	*/
} taskInfo_t;

typedef struct
{
	taskInfo_t AppTask;
	u8 ticksToExecute;
	u8 countIfPause;
	taskState_t taskState;
} taskMoreInfo_t ;


extern Error_Status Sched_init(void);

extern Error_Status Sched_Start(void);

extern void Sched_Runnable(void);

extern Error_Status Sched_SystickCbf(void);

extern Error_Status Task_Suspend(taskRunnable_t tasktosus);

extern Error_Status Task_Sleep(taskRunnable_t taskRunnable, u32 Copy_u32Period);


#endif
