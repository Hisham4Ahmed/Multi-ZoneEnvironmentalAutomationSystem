/**
 * @file     LCD_Config.h
 * @author   Developer : Ahmed Ashraf
 * @author   Reviewer  : Mohamed Diaa
 * @brief    this file is used to show preconfigured options of LCD
 * @version   0.1
 * @date      2025-08-24
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#ifndef _LCD_CONFIG_H_
#define _LCD_CONFIG_H_

/*-------------------- LCD Group -----------------------------------------*/
/**
 * @defgroup    LCD_Group_Configuration
 * @brief       Port group assignments for LCD control and data lines
 * @note        We are using 4 bti mode in this driver
 * @{
 */

/** @brief LCD Register Select (RS) control line group */
#define LCD_RS_Group    GroupB

/** @brief LCD Enable (E) control line group */
#define LCD_E_Group     GroupB

/** @brief LCD Data line D4 group */
#define LCD_D4_Group    GroupB

/** @brief LCD Data line D5 group */
#define LCD_D5_Group    GroupB

/** @brief LCD Data line D6 group */
#define LCD_D6_Group    GroupB

/** @brief LCD Data line D7 group */
#define LCD_D7_Group    GroupB

/** @brief LCD port register used for data and control lines */
#define LCD_PORT        PORTB_Reg

/** @brief LCD Read/Write (RW) pin assignment — grounded to avoid conflicts */
#define LCD_RW_Pin      GND

/** @} */ // end of LCD_Group_Configuration

/*------------------------ LCD Pins ----------------------------------------*/
/**
 * @defgroup    LCD_Pin_Configuration
 * @brief       Pin number assignments for LCD control and data lines
 * @{
 */

/** @brief LCD Register Select (RS) control line pin */
#define LCD_RS_Pin       Pin0

/** @brief LCD Enable (E) control line pin */
#define LCD_E_Pin        Pin1

/** @brief LCD Data line D4 pin */
#define LCD_D4_Pin       Pin4

/** @brief LCD Data line D5 pin */
#define LCD_D5_Pin       Pin5

/** @brief LCD Data line D6 pin */
#define LCD_D6_Pin       Pin6

/** @brief LCD Data line D7 pin */
#define LCD_D7_Pin       Pin7

/** @} */ // end of LCD_Pin_Configuration




#endif /*_LCD_CONFIG_H_*/