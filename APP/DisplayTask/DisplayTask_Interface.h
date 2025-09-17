/**
 * @file     DisplayTask_Interface.h
 * @author   Your Name
 * @brief    Display Task Interface - LCD Mode Display
 * @version   0.1
 * @date      2025-09-17
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _DISPLAYTASK_INTERFACE_H_
#define _DISPLAYTASK_INTERFACE_H_

/**
 * @fn void LCDDisplay_Init(void)
 * @brief Initializes the LCD display and shows starting mode
 */
void LCDDisplay_Init(void);

/**
 * @fn void LCDDisplay_Task(void)
 * @brief Periodically updates LCD with current operation mode
 */
void LCDDisplay_Task(void);

#endif /* _DISPLAYTASK_INTERFACE_H_ */