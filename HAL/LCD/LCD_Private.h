/**
 * @file     LCD_Private.h
 * @author   Developer : Ahmed Ashraf
 * @author   Reviewer  : Mohamed Diaa
 * @brief    This Driver is to set and operate LCD Screen 2*16
 * @version   0.1
 * @date      2025-08-24
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#ifndef _LCD_PRIVATE_H_
#define _LCD_PRIVATE_H_

/*------------------- LCD Commands --------------------------*/
/**
 * @defgroup    LCD_Command_Macros
 * @brief       LCD instruction set macros for control operations
 * @{
 */

/** @brief Clear display and reset cursor */
#define LCD_CLEAR_DISPLAY        0x01

/** @brief Return cursor to home position */
#define LCD_RETURN_HOME          0x02

/** @brief Set entry mode: increment cursor, no display shift */
#define LCD_ENTRY_MODE           0x06

/** @brief Turn off display */
#define LCD_DISPLAY_OFF          0x08

/** @brief Turn on display with cursor */
#define LCD_DISPLAY_ON           0x0E

/** @brief Display ON, cursor OFF */
#define LCD_CURSOR_OFF           0x0C

/** @brief Display ON, cursor ON */
#define LCD_CURSOR_ON            0x0E

/** @brief Display ON, cursor blinking */
#define LCD_CURSOR_BLINK         0x0F

/** @} */

/*----------------------- Line Addresses ----------------------*/
/**
 * @defgroup    LCD_Line_Addresses
 * @brief       DDRAM address mapping for LCD lines
 * @{
 */

/** @brief Logical identifier for first line */
#define FirstLine                1

/** @brief Logical identifier for second line */
#define SecondLine               2

/** @brief DDRAM address for first line start */
#define FirstLineAddress         0x00

/** @brief DDRAM address for second line start */
#define SecondLineAddress        0x40

/** @brief Base command for setting DDRAM address */
#define SetDDRAMCommand          0x80

/** @} */
/*------------------------------ LCD Magic Numbers --------------------------------------*/
/**
 * @defgroup    LCD_Magic_Numbers
 * @brief       Bit masks and initialization values used for LCD data manipulation and setup
 * @{
 */

/** @brief Mask to extract the higher nibble from a byte */
#define Higher_Nibble_Mask       0xF0

/** @brief Mask to extract the lower nibble from a byte */
#define Lower_Nibble_Mask        0x0F

/** @brief Command to initialize LCD in 8-bit mode */
#define _8bit_Mode               0x38

/** @brief Command to initialize LCD in 4-bit mode with 2-line display */
#define _2Line_Mode              0x28

/** @brief Command to switch from 8-bit to 4-bit mode during initialization */
#define _4bit_Mode               0x32

/** @} */ 

#endif /*_LCD_PRIVATE_H_*/