/**
 * @file      ModeControl_Program.c
 * @author    Developer: Mohammed Atif   "medoatifatif@gmail.com"
 * @author    Reviewer: Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief     Mode control initialization and mode retrieval.
 * @version   0.2
 * @date      2025-09-8
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#include "../../Common/Config.h"
#if ModeControl_App
#include "ModeControl_Interface.h"
static uint8_t ModeControl_Initialized=0;

void ModeControl_Init(void) {
    hBtn_Init();
    ModeControl_Initialized=1;
}

void ModeControl_Task(void) {
    // Empty for current version
}

uint8_t ModeControl_GetMode(void) {
    return hBtn_GetStatus();
}

uint8_t ModeControl_IsInitialized()
{
    return ModeControl_Initialized; 
}
#endif 