/**
 * @file      DisplayTask_Interface.h
 * @author    Dev. Hozifa Ahmed (hozifasedik@gmail.com)
 * @author    Rev. Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief     Display Task Interface - LCD Mode Display
 * @details   Provides APIs for initializing and updating LCD display with system mode information.
 * @version   0.2
 * @date      2025-09-17
 * @copyright Copyright (c) 2025 , Gestell Company
 */

#ifndef _DISPLAYTASK_INTERFACE_H_
#define _DISPLAYTASK_INTERFACE_H_

/**
 * @defgroup Display_Task Display Task
 * @brief APIs for LCD display management
 * @{
 */

/**
 * @fn LCDDisplay_Init
 * @brief Initializes the LCD display and shows starting mode
 * @return void
 * @note Calls hLCD_Init() and displays initial mode from ModeControl
 */
void LCDDisplay_Init(void);

/**
 * @fn LCDDisplay_Task
 * @brief Periodically updates LCD with current operation mode
 * @return void
 * @note Only updates display if mode has changed since last update
 */
void LCDDisplay_Task(void);

/** @} */ // End of Display_Task group

#endif /* _DISPLAYTASK_INTERFACE_H_ */