/**
 * @file     ModeControl_Interface.h
 * @author   Developer: Mohammed Atif   "medoatifatif@gmail.com"
 * @author   <Reviewer>
 * @brief    interface for the mode control module.
 * @version   0.1
 * @date      2025-09-8
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _MODECONTROL_INTERFACE_H_
#define _MODECONTROL_INTERFACE_H_

#include <stdint.h>
#include "../../HAL/Btn/Btn_Interface.h"

/**
 * @fn void ModeControl_Init(void)
 * @brief Initializes the mode control module.
 *
 * This function initializes the button driver, which is
 * required for detecting mode changes.
 */
void ModeControl_Init(void);

/**
 * @fn void ModeControl_Task(void)
 * @brief Executes the mode control task.
 * Currently, this function is empty.
 * It ensures Consistency with other tasks
 *  (ZoneControl_Task, Communication_Task, Display_Task).
 */
void ModeControl_Task(void);

/**
 * @fn uint8_t ModeControl_GetMode(void)
 * @brief Retrieves the current system mode.
 *
 * @return uint8_t
 * - 0: Automatic mode
 * - 1: Manual mode
 */
uint8_t ModeControl_GetMode(void);


#endif  /* _MODECONTROL_INTERFACE_H_ */