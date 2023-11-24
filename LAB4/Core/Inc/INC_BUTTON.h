/*
 * INC_BUTTON.h
 *
 *  Created on: Nov 24, 2023
 *      Author: hoang
 */

#ifndef INC_INC_BUTTON_H_
#define INC_INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int button1_flag;
void getKeyInput();

#endif /* INC_INC_BUTTON_H_ */
