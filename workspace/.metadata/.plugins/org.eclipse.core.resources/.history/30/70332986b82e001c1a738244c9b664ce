/*
 * keypad.c
 *
 *  Created on: Oct 9, 2021
 *      Author: Kyrillos
 */


#include "keypad.h"

#if  ( KEYPAD_COL_NUM == 3 && KEYPAD_ROW_NUM==4 )
static uint8 KEYPAD_adjust_4x3_adjustKeyNumber(uint8 a_key);
#elif( KEYPAD_COL_NUM == 4 && KEYPAD_ROW_NUM==4 )
/**/
static uint8 KEYPAD_adjust_4x3_adjustKeyNumber(uint8 a_key);
#else
#error "no adjustKeyNumber found for used numbers of rows or columns !!! "
#endif
uint8 KEYPAD_getPressedKey(void){
	/*TODO this part need testing and optimize when write first n pins function be ready*/
	while(1){
		for(uint8 col=0; col<KEYPAD_COL_NUM;col++){
			/*for easy disconnect power on pins is to make them inputs*/
			GPIO_setupFirstNPins((uint8)KEYPAD_PORT_ID,((KEYPAD_COL_NUM)+(KEYPAD_ROW_NUM)),PIN_INPUT);
#if  ( KEYPAD_BUTTON_PRESSED == LOGIC_HIGH)
			GPIO_writeFirstNPins((uint8)KEYPAD_PORT_ID,(KEYPAD_COL_NUM),FIRST_BITS_HIGH((KEYPAD_COL_NUM)));
#else
			GPIO_writeFirstNPins((uint8)KEYPAD_PORT_ID,(KEYPAD_COL_NUM),~(FIRST_BITS_HIGH((KEYPAD_COL_NUM))));
#endif
			GPIO_setupPinDirection((uint8)KEYPAD_PORT_ID,col,PIN_OUTPUT);

#if 0
#if  ( KEYPAD_BUTTON_PRESSED == LOGIC_HIGH)
			//GPIO_writePort(KEYPAD_PORT_ID,((GPIO_readPort(KEYPAD_PORT_ID)&(0xFF&(~(1<<((KEYPAD_COL_NUM)+(KEYPAD_ROW_NUM)))-1))))|(1<<col));
			GPIO_writePin(KEYPAD_PORT_ID,col,LOGIC_HIGH);
#else
			//GPIO_writePort(KEYPAD_PORT_ID,((GPIO_readPort(KEYPAD_PORT_ID)&(0xFF&(~(1<<((KEYPAD_COL_NUM)+(KEYPAD_ROW_NUM)))-1))))&(~(1<<col)));
			GPIO_writePin(KEYPAD_PORT_ID,col,LOGIC_LOW);
#endif
#endif
			for(uint8 row=KEYPAD_COL_NUM;row<((KEYPAD_COL_NUM)+(KEYPAD_ROW_NUM));row++){
				if(GPIO_readPin(KEYPAD_PORT_ID,row) == (KEYPAD_BUTTON_PRESSED)){
#if   (KEYPAD_COL_NUM == 3 && KEYPAD_ROW_NUM == 4)
					return KEYPAD_adjust_4x3_adjustKeyNumber((row*KEYPAD_COL_NUM)+col+1);
#elif (KEYPAD_COL_NUM == 4 && KEYPAD_ROW_NUM == 4)
					return KEYPAD_adjust_4x4_adjustKeyNumber((row*KEYPAD_COL_NUM)+col+1);
#endif
				}
			}
		}
	}
}

#if  ( KEYPAD_COL_NUM == 3 && KEYPAD_ROW_NUM==4 )
static uint8 KEYPAD_adjust_4x3_adjustKeyNumber(uint8 a_key){
	switch(a_key)
	{
		case 10: return '*'; // ASCII Code of *
				 break;
		case 11: return  0;
				 break;
		case 12: return '#'; // ASCII Code of #
				 break;
		default: return a_key;
				 break;
	}
}
#elif( KEYPAD_COL_NUM == 4 && KEYPAD_ROW_NUM==4 )
static uint8 KEYPAD_adjust_4x3_adjustKeyNumber(uint8 a_key)
{
	switch(a_key)
	{
		case 1: return 7;
				break;
		case 2: return 8;
				break;
		case 3: return 9;
				break;
		case 4: return '%'; // ASCII Code of %
				break;
		case 5: return 4;
				break;
		case 6: return 5;
				break;
		case 7: return 6;
				break;
		case 8: return '*'; /* ASCII Code of '*' */
				break;
		case 9: return 1;
				break;
		case 10: return 2;
				break;
		case 11: return 3;
				break;
		case 12: return '-'; /* ASCII Code of '-' */
				break;
		case 13: return 13;  /* ASCII of Enter */
				break;
		case 14: return 0;
				break;
		case 15: return '='; /* ASCII Code of '=' */
				break;
		case 16: return '+'; /* ASCII Code of '+' */
				break;
		default: return a_key;
				break;
	}
}

#else
#error "no adjustKeyNumber found for used numbers of rows or columns !!! "
#endif
