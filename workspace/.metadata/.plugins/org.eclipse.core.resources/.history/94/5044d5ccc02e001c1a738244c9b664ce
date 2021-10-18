/*
 *TODO documenting lcd.c
 *
 *  Created on: Oct 13, 2021
 *      Author: Kyrillos
 */

#include "lcd.h"
void LCD_init(){
	GPIO_setupPinDirection(LCD_COMMAND_PORT_ID,LCD_PIN_E_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_COMMAND_PORT_ID,LCD_PIN_RS_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_COMMAND_PORT_ID,LCD_PIN_RW_ID,PIN_OUTPUT);
#if		LCD_4BITS_MODE
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,((LCD_DATA_FIRST_PIN_ID)+0),PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,((LCD_DATA_FIRST_PIN_ID)+1),PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,((LCD_DATA_FIRST_PIN_ID)+2),PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,((LCD_DATA_FIRST_PIN_ID)+3),PIN_OUTPUT);
	LCD_sendCommand(LCD_CMD_MODE_4BITS_1);
	LCD_sendCommand(LCD_CMD_MODE_4BITS_2);
	LCD_sendCommand(LCD_CMD_USE_2_LINES_5X7_DOTS_FOR_4BIT_MODE);
#else
	  /*LCD_8BITS_MODE*/
	LCD_sendCommand(LCD_CMD_USE_2_LINES_5X7_DOTS_FOR_8BIT_MODE);
#endif
	LCD_sendCommand(LCD_CMD_DISPLAY_ON_CURSOR_OFF);
	LCD_sendCommand(LCD_CMD_CLEAR_DISPLAY);
	LCD_sendCommand(LCD_CMD_MOVE_CURSOR_TO_BEGINNING_1ST_LINE);

}

void LCD_sendCommand(LCD_Command_t a_command){
#if LCD_4BITS_MODE
	GPIO_writePin(LCD_COMMAND_PORT_ID,LCD_PIN_RS_ID,LOGIC_LOW);
	GPIO_writePin(LCD_COMMAND_PORT_ID,LCD_PIN_RW_ID,LOGIC_LOW);
	LCD_DELAY();
	GPIO_writePin(LCD_COMMAND_PORT_ID,LCD_PIN_E_ID,LOGIC_HIGH);
	LCD_DELAY();
	/*GPIO_writePort(LCD_DATA_PORT_ID,a_command);*/
	GPIO_INSERT_SUCCESSIVE_BITS(LCD_DATA_OUTPUT,LCD_DATA_FIRST_PIN_ID,(4u),((a_command>>4)&(0x0f)));
	LCD_DELAY();
	GPIO_INSERT_SUCCESSIVE_BITS(LCD_DATA_OUTPUT,LCD_DATA_FIRST_PIN_ID,(4u),((a_command)&(0x0f)));
	LCD_DELAY();
	GPIO_writePin(LCD_COMMAND_PORT_ID,LCD_PIN_E_ID,LOGIC_LOW);
	LCD_DELAY();
#elif LCD_8BITS_MODE
	GPIO_writePin(LCD_COMMAND_PORT_ID,LCD_PIN_RS_ID,LOGIC_LOW);
	GPIO_writePin(LCD_COMMAND_PORT_ID,LCD_PIN_RW_ID,LOGIC_LOW);
	LCD_DELAY();
	GPIO_writePin(LCD_COMMAND_PORT_ID,LCD_PIN_E_ID,LOGIC_HIGH);
	LCD_DELAY();
	GPIO_writePort(LCD_DATA_PORT_ID,a_command);
	LCD_DELAY();
	GPIO_writePin(LCD_COMMAND_PORT_ID,LCD_PIN_E_ID,LOGIC_LOW);
	LCD_DELAY();
#endif
}

void LCD_displayCharacter(char a_char){
#if LCD_4BITS_MODE
	GPIO_writePin(LCD_COMMAND_PORT_ID,LCD_PIN_RS_ID,LOGIC_HIGH);
	GPIO_writePin(LCD_COMMAND_PORT_ID,LCD_PIN_RW_ID,LOGIC_LOW);
	LCD_DELAY();
	GPIO_writePin(LCD_COMMAND_PORT_ID,LCD_PIN_E_ID,LOGIC_HIGH);
	LCD_DELAY();
	/*GPIO_writePort(LCD_DATA_PORT_ID,a_command);*/
	GPIO_INSERT_SUCCESSIVE_BITS(LCD_DATA_OUTPUT,LCD_DATA_FIRST_PIN_ID,(4u),((a_char>>4)&(0x0f)));
	LCD_DELAY();
	GPIO_INSERT_SUCCESSIVE_BITS(LCD_DATA_OUTPUT,LCD_DATA_FIRST_PIN_ID,(4u),((a_char)&(0x0f)));
	LCD_DELAY();
	GPIO_writePin(LCD_COMMAND_PORT_ID,LCD_PIN_E_ID,LOGIC_LOW);
	LCD_DELAY();
#elif LCD_8BITS_MODE
	GPIO_writePin(LCD_COMMAND_PORT_ID,LCD_PIN_RS_ID,LOGIC_LOW);
	GPIO_writePin(LCD_COMMAND_PORT_ID,LCD_PIN_RW_ID,LOGIC_LOW);
	LCD_DELAY();
	GPIO_writePin(LCD_COMMAND_PORT_ID,LCD_PIN_E_ID,LOGIC_HIGH);
	LCD_DELAY();
	GPIO_writePort(LCD_DATA_PORT_ID,a_char);
	LCD_DELAY();
	GPIO_writePin(LCD_COMMAND_PORT_ID,LCD_PIN_E_ID,LOGIC_LOW);
	LCD_DELAY();
#endif
}

void LCD_displayString(char* a_string){
	uint8 counter=0;
	while(a_string[counter]!='\0'){
		LCD_displayCharacter(a_string[counter++]);
	}
}

void LCD_moveCursorTo(uint8 a_row,uint8 a_col){
	switch (a_row) {
		case 0:
			LCD_sendCommand((LCD_CMD_MOVE_CURSOR_TO_BEGINNING_1ST_LINE) +a_col);
			break;

		case 1:
			LCD_sendCommand((LCD_CMD_MOVE_CURSOR_TO_BEGINNING_2ND_LINE) +a_col);
			break;

		default:

			break;
	}
}

void LCD_displayStringRowColumn(char* a_string,uint8 a_row,uint8 a_col){
#if LCD_ROW_NUM >(2u)
#error LCD MODULE SUPPORTS MAX 2 LINES LCD
#endif
	uint8 counter=0;
	LCD_moveCursorTo(a_row,a_col);
	while(a_string[counter]!='\0' && (counter+a_col)<LCD_ROW_WIDTH){
		LCD_displayCharacter(a_string[counter++]);
	}
#if LCD_ROW_NUM >(1u)
	if(a_string[counter]!=0 &&	((a_row+1)<LCD_ROW_NUM)){
		a_col=0;
		LCD_moveCursorTo(a_row++,a_col);
		while(a_string[counter]!='\0' && (counter+a_col)<LCD_ROW_WIDTH){
				LCD_displayCharacter(a_string[counter++]);
			}
#endif

	}
}


void LCD_clearScreen(){
	LCD_sendCommand(LCD_CMD_CLEAR_DISPLAY);
}

void LCD_intgerToString(int8 a_intger,char* a_buffer_ptr){
	itoa(a_intger,a_buffer_ptr,10);
	LCD_displayString(a_buffer_ptr);
}
