/*
 * global.c
 *
 *  Created on: Nov 24, 2023
 *      Author: hoang
 */

#include "global.h"

int global_time = 0;
int status = 0;

void update_time()
{
	global_time +=10;
}
int get_time()
{
	return global_time;
}
