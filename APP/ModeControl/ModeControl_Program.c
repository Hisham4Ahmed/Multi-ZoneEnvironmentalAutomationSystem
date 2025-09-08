/**
 * @file     ModeControl_Program.c
 * @author   Developer: Mohammed Atif   "medoatifatif@gmail.com"
 * @author   <Reviewer>
 * @brief    Mode control initialization and mode retrieval.
 * @version   0.1
 * @date      2025-09-8
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */
#include "ModeControl_Interface.h"

/**
 * @var CurrentMode
 * @brief Current operation mode of the system.
 *
 * Possible values:
 * - 0: Automatic mode
 * - 1: Manual mode
 */
extern uint8_t CurrentMode; 

void ModeControl_Init(void) {
    hBtn_Init();
}

void ModeControl_Task(void) {
    // Empty for current version
}

uint8_t ModeControl_GetMode(void) {
    return CurrentMode;
}
