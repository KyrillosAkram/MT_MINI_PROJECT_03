/*
 * keypad.h
 *
 *		Module: KEYPAD
 *
 *  Created on: Oct 9, 2021
 *
 *      Author: Kyrillos
 *
 *		 Usage: To use this module should consider the following
 * 		 		1- the gpio used should start from PIN0
 * 		 		2- the column is lest significant the row
 * 		 		3- confider the module header in config section
 * 		 		4- gpio of keypad should lay on single port
 *
 *
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "gpio.h"

/****************************************************
 *  		Module macros and configuration         *
 ****************************************************/

/*
 * Description: this section should explicitly defined
 */

/*(3 or 4) only supported for columns and 4 for rows
 *  but you can define you own*/
#define KEYPAD_COL_NUM 3U /*default*/
#define KEYPAD_ROW_NUM 4U /*default*/

#define KEYPAD_PORT_ID UNDEFINED
#define KEYPAD_ROW_FIRST_ID UNDEFINED
#define KEYPAD_COL_FIRST_ID UNDEFINED

/*TODO KEYPAD_TIMEOUT and KEYPAD_TIMER
#define KEYPAD_TIMEOUT FALSE feature to be added in future
#define KEYPAD_TIMER FALSE feature to be added in future
*/

#define KEYPAD_BUTTON_PRESSED UNDEFINED
#define KEYPAD_BUTTON_RELEASED UNDEFINED


#if \
	(KEYPAD_BUTTON_PRESSED  == UNDEFINED)||\
	(KEYPAD_BUTTON_RELEASED == UNDEFINED)||\
	(KEYPAD_COL_ID          == UNDEFINED)||\
	(KEYPAD_COL_NUM         == UNDEFINED)||\
	(KEYPAD_PORT_ID         == UNDEFINED)||\
	(KEYPAD_ROW_ID          == UNDEFINED)||\
	(KEYPAD_ROW_NUM         == UNDEFINED)||\
	(KEYPAD_PULL_UP         == UNDEFINED)
#error ==> a config macro in KEYPAD module is undefined
#endif


uint8 KEYPAD_getPressedKey(void);
#endif /* KEYPAD_H_ */
