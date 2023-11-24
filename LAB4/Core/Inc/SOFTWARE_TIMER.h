/*
 * SOFTWARE_TIMER.h
 *
 *  Created on: Nov 24, 2023
 *      Author: hoang
 */


#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;

void setTimer1(int duration);
void setTimer2(int duration);
void clearTimer1();
void timerRun();
#endif /* INC_SOFTWARE_TIMER_H_ */
