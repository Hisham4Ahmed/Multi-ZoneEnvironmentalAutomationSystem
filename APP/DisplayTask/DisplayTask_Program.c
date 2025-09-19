/**
 * @file      DisplayTask_Program.c
 * @author    Dev. Hozifa Ahmed (hozifasedik@gmail.com)
 * @author    Rev. Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief     Display Task Implementation - LCD Mode Display
 * @version   0.2
 * @date      2025-09-18
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
    
    hLCD_MoveCursor(Manual, Automatic);
    if(currentMode == Automatic) {
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
        hLCD_MoveCursor(Manual, Automatic);
        
        if(currentMode == Automatic) {
            hLCD_WriteString("MODE: AUTO");
        } else {
            hLCD_WriteString("MODE: MANUAL");
        }
        
        PreviousMode = currentMode;
    }
}