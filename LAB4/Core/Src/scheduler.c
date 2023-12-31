/*
 * scheduler.c
 *
 *  Created on: Nov 24, 2023
 *      Author: hoang
 */

#include "scheduler.h"
#include "main.h"
sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;

void SCH_Init(void)
{
		current_index_task = 0;
}

uint32_t SCH_Add_Task ( void (*pFunction)() , uint32_t DELAY, uint32_t PERIOD)
{
	if(current_index_task < SCH_MAX_TASKS)
	{

		SCH_tasks_G[current_index_task].pTask = pFunction;
		SCH_tasks_G[current_index_task].Delay = DELAY/TIMER_CYCLE;
		SCH_tasks_G[current_index_task].Period = PERIOD/TIMER_CYCLE;
		SCH_tasks_G[current_index_task].RunMe = 0;
//		SCH_tasks_G[current_index_task].TaskID = current_index_task;
		current_index_task++;
		return current_index_task-1;
	}
	return -1;
}

void SCH_Update(void)
{
	for(int i = 0 ; i < current_index_task; i++)
	{
		if(SCH_tasks_G[i].Delay > 0)
		{
			SCH_tasks_G[i].Delay--;
		}
		if(SCH_tasks_G[i].Delay == 0)
		{
			SCH_tasks_G[i].RunMe +=1;
			if(SCH_tasks_G[i].Period)
					SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
		}

	}
}

void SCH_Dispatch_Tasks(void)
{
	for( int i = 0; i < current_index_task; i++)
	{
		if(SCH_tasks_G[i].RunMe > 0)
		{
			SCH_tasks_G[i].RunMe--;
			(*SCH_tasks_G[i].pTask)();
			if(SCH_tasks_G[i].Delay == 0 && SCH_tasks_G[i].Period == 0 && SCH_tasks_G[i].RunMe == 0)
			{
				SCH_Delete_Task(i);
			}
		}

	}
}

uint8_t SCH_Delete_Task(const uint8_t TASK_INDEX)//in array index is taskid
{
   if(TASK_INDEX >= current_index_task)
   {
	   return -1;
   }
   else
   {
	   for( int i = TASK_INDEX; i < current_index_task - 1; i++)
	   {
			SCH_tasks_G[i].pTask = SCH_tasks_G[i + 1].pTask;
			SCH_tasks_G[i].Delay = SCH_tasks_G[i + 1].Delay;
			SCH_tasks_G[i].Period = SCH_tasks_G[i + 1].Period;
			SCH_tasks_G[i].RunMe = SCH_tasks_G[i + 1].RunMe;
	   }

	   current_index_task--;
	   return 1;
   }
}
