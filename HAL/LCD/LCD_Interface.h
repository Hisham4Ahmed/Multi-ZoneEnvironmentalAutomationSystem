/**
 * @file     LCD_Interface.h
 * @author   Developer : Ahmed Ashraf
 * @author   Reviewer  : Mohamed Diaa
 * @brief    This Driver is to set and operate LCD Screen 2*16
 * @version   0.1
 * @date      2025-08-24
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */




#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_
/*------------------- included Files--------------------------*/
#include "LCD_Config.h"
#include "LCD_Private.h"
#include "../../Common/Macro.h"
#include "../../MCAL/RegistersAddress.h"
#include "../../MCAL/DIO/DIO_Interface.h"
/*-------------------Functions-------------------------------*/
/**
 * @fn hLCD_Init
 * @brief Initialize the LCD in 4-bit mode
 */
void hLCD_Init () ;


/**
 * @fn hLCD_WriteByte
 */
void hLCD_WriteByte (uint8_t Byte);
/**
 * @fn hLCD_SetInstruction
 * @brief Send a command instruction to the LCD
 * @param Command The command byte to be sent to the LCD
 * 
 * Options for Command:
 * - LCD_CLEAR_DISPLAY : 0x01
 * - LCD_RETURN_HOME   : 0x02
 * - LCD_ENTRY_MODE    : 0x06
 * - LCD_DISPLAY_OFF   : 0x08
 * - LCD_DISPLAY_ON    : 0x0E
 * - LCD_CURSOR_OFF    : 0x0C
 * - LCD_CURSOR_ON     : 0x0E
 * - LCD_CURSOR_BLINK  : 0x0F
 */
void hLCD_SetInstruction (uint8_t Command) ;

/**
 * @fn hLcd_WriteString
 * @brief Write a string to the LCD
 * @param String Pointer to the null-terminated string to be displayed
 */
void hLCD_WriteString(uint8_t *String);
/**
 * @fn hLcd_WriteNumber
 * @brief Write a number to the LCD
 * @param Number The number to be displayed on the LCD
 * @note Supports up to 10 digits (uint32_t max) (Decimal : 4,294,967,295 )
 */
void hLCD_WriteNumber(uint32_t Number);
/**
 * @fn hLcd_MoveCursor
 * @brief Move the cursor to a specific line and position on the LCD
 * @param Line The line number (1 or 2)
 * @param Pos The position on the line (0 to 15)
 */
void hLCD_MoveCursor(uint8_t Line, uint8_t Pos);
/**
 * @fn hLcd_ClearFirstLine
 * @brief Clear the first line of the LCD
 */
void hLCD_ClearFirstLine();

/**
 * @fn hLcd_ClearSecondLine
 * @brief Clear the second line of the LCD
 */

void hLCD_ClearSecondLine();

/*----------------------------------------------------*/
#endif /*_LCD_INTERFACE_H_*/