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

#define LCD_CLEAR_DISPLAY        0x01
#define LCD_RETURN_HOME         0x02
#define LCD_ENTRY_MODE          0x06

#define LCD_DISPLAY_OFF         0x08
#define LCD_DISPLAY_ON          0x0E

#define LCD_CURSOR_OFF          0x0C
#define LCD_CURSOR_ON           0x0E

#define LCD_CURSOR_BLINK        0x0F

/*-----------------------Line Addresses----------------------*/
/**
 * @def LCD line addresses
 */
#define FirstLine 1
#define SecondLine 2
#define FirstLineAddress  0x00
#define SecondLineAddress 0x40
#define SetDDRAMCommand   0x80
/*-------------------------------------------------------------*/
/*------------------------------LCD Magic Numbers--------------------------------------*/
/**
 * @def LCD Magic Numbers
 * @brief These macros are used to manipulate the LCD data port & Initialize the LCD in 4-bit mode
 */
#define Higher_Nibble_Mask 0xF0
#define Lower_Nibble_Mask  0x0F

#define _8bit_Mode 0x38
#define _2Line_Mode 0x28
#define _4bit_Mode 0x32

#endif /*_LCD_PRIVATE_H_*/