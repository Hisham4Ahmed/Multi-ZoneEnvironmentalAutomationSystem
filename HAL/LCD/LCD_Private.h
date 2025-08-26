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

#define FirstLine 1
#define SecondLine 2
#define FirstLineAddress  0x00
#define SecondLineAddress 0x40
#define SetDDRAMCommand   0x80
/*-------------------------------------------------------------*/
#endif /*_LCD_PRIVATE_H_*/