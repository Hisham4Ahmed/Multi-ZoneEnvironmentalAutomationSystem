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

/*------------------- Included Files --------------------------*/


#include "LCD_Config.h"                  
#include "LCD_Private.h"                  
#include "../../Common/Macro.h"          
#include "../../MCAL/RegistersAddress.h" 
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Private.h"  



/*------------------- LCD Interface Functions -------------------------------*/
/**
 * @defgroup    LCD_Functions
 * @brief       LCD control and display function prototypes
 * @{
 */

/**
 * @fn          void hLCD_Init(void)
 * @brief       Initialize the LCD in 4-bit mode
 */
void hLCD_Init(void);

/**
 * @fn          void hLCD_WriteByte(uint8_t Byte)
 * @brief       Write a raw byte to the LCD (data or command)
 * @param   Byte The byte to be written
 */
void hLCD_WriteByte(uint8_t Byte);

/**
 * @fn          void hLCD_SetInstruction(uint8_t Command)
 * @brief       Send a command instruction to the LCD
 * @param   Command The command byte to be sent
 * @note        Supported command options:
 *              - LCD_CLEAR_DISPLAY : 0x01
 *              - LCD_RETURN_HOME   : 0x02
 *              - LCD_ENTRY_MODE    : 0x06
 *              - LCD_DISPLAY_OFF   : 0x08
 *              - LCD_DISPLAY_ON    : 0x0E
 *              - LCD_CURSOR_OFF    : 0x0C
 *              - LCD_CURSOR_ON     : 0x0E
 *              - LCD_CURSOR_BLINK  : 0x0F
 */
void hLCD_SetInstruction(uint8_t Command);

/**
 * @fn          void hLCD_WriteString(uint8_t *String)
 * @brief       Write a null-terminated string to the LCD
 * @param   String Pointer to the string to be displayed
 */
void hLCD_WriteString(uint8_t *String);

/**
 * @fn          void hLCD_WriteNumber(uint32_t Number)
 * @brief       Display a decimal number on the LCD
 * @param   Number The number to be displayed
 * @note        Supports up to 10 digits (max: 4,294,967,295)
 */
void hLCD_WriteNumber(uint32_t Number);

/**
 * @fn          void hLCD_MoveCursor(uint8_t Line, uint8_t Pos)
 * @brief       Move the cursor to a specific line and position
 * @param   Line Line number (1 or 2)
 * @param   Pos  Position on the line (0 to 15)
 */
void hLCD_MoveCursor(uint8_t Line, uint8_t Pos);

/**
 * @fn          void hLCD_ClearFirstLine(void)
 * @brief       Clear all characters from the first line
 */
void hLCD_ClearFirstLine(void);

/**
 * @fn          void hLCD_ClearSecondLine(void)
 * @brief       Clear all characters from the second line
 */
void hLCD_ClearSecondLine(void);

/** @} */ 

#endif /*_LCD_INTERFACE_H_*/