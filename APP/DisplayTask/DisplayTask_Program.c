/**
 * @file     DisplayTask_Program.c
 * @author   Your Name
 * @brief    Display Task Implementation - LCD Mode Display
 * @version   0.1
 * @date      2025-09-17
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#include "DisplayTask_Interface.h"
#include "../../HAL/LCD/LCD_Interface.h"
#include "../ModeControl/ModeControl_Interface.h"

static uint8_t PreviousMode = 0xFF; // Initialize with invalid value

void LCDDisplay_Init(void)
{
    hLCD_Init();
    hLCD_ClearFirstLine();
    
    // Get initial mode and display
    uint8_t currentMode = ModeControl_GetMode();
    PreviousMode = currentMode;
    
    hLCD_MoveCursor(1, 0);
    if(currentMode == 0) {
        hLCD_WriteString("MODE: AUTO");
    } else {
        hLCD_WriteString("MODE: MANUAL");
    }
}

void LCDDisplay_Task(void)
{
    uint8_t currentMode = ModeControl_GetMode();
    
    // Only update if mode changed
    if(currentMode != PreviousMode) {
        hLCD_ClearFirstLine();
        hLCD_MoveCursor(1, 0);
        
        if(currentMode == 0) {
            hLCD_WriteString("MODE: AUTO");
        } else {
            hLCD_WriteString("MODE: MANUAL");
        }
        
        PreviousMode = currentMode;
    }
}