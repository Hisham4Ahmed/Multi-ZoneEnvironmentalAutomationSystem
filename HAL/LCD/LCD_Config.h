/**
 * @file     LCD_Config.h
 * @author   Developer : Ahmed Ashraf
 * @author   Reviewer  : Mohamed Diaa
 * @brief    This Driver is to set and operate LCD Screen 2*16
 * @version   0.1
 * @date      2025-08-24
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#ifndef _LCD_CONFIG_H_
#define _LCD_CONFIG_H_

/*-------------------- LCD Group -----------------------------------------*/

/**
 * @def LCD Group Configuration
 * @brief Define the port groups for LCD control and data lines
 */

#define LCD_RS_Group    GroupB
#define LCD_E_Group     GroupB
#define LCD_D4_Group    GroupB
#define LCD_D5_Group    GroupB
#define LCD_D6_Group    GroupB
#define LCD_D7_Group    GroupB
#define LCD_PORT        PORTB_Reg

#define LCD_RW_Pin      GND   //-> won't be used But Mentioned To Avoid Conflicts

/*------------------------ LCD Pins ----------------------------------------*/

/**
 * @def LCD Pin Configuration
 * @brief Define the pin numbers for LCD control and data lines
 */

#define LCD_RS_Pin       Pin0
#define LCD_E_Pin        Pin1
#define LCD_D4_Pin       Pin4
#define LCD_D5_Pin       Pin5
#define LCD_D6_Pin       Pin6
#define LCD_D7_Pin       Pin7



/*-------------------------------------------------------*/




#endif /*_LCD_CONFIG_H_*/