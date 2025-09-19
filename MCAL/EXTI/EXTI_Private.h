/**
 * @file      DisplayTask_Program.c
 * @author    Developer: Hozifa Ahmed (hozifasedik@gmail.com)
 * @author    Reviewer: Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief     Display Task Implementation - LCD Mode Display
 * @details   Implements LCD display initialization and mode update functionality.
 * @version   0.2
 * @date      2025-09-18
 * @copyright Copyright (c) 2025 , Gestell Company
 */

#include "DisplayTask_Interface.h"
#include "../../HAL/LCD/LCD_Interface.h"
#include "../ModeControl/ModeControl_Interface.h"

/** @addtogroup Display_Task
 * @{
 */

/**
 * @var PreviousMode
 * @brief Stores the previous mode for change detection
 * @note Initialized with invalid value (0xFF) to force first update
 */
static uint8_t PreviousMode = 0xFF;

/**
 * @fn LCDDisplay_Init
 * @brief Initializes the LCD display and shows starting mode
 * @return void
 */
void LCDDisplay_Init(void)
{
    /* Initialize LCD hardware */
    hLCD_Init();
    
    /* Clear first line of display */
    hLCD_ClearFirstLine();
    
    /* Get initial mode from ModeControl */
    uint8_t currentMode = ModeControl_GetMode();
    PreviousMode = currentMode;
    
    /* Move cursor to first line, first position */
    hLCD_MoveCursor(1, 0);
    
    /* Display appropriate mode message */
    if(currentMode == Automatic) {
        hLCD_WriteString("MODE: AUTO");
    } else {
        hLCD_WriteString("MODE: MANUAL");
    }
}

/**
 * @fn LCDDisplay_Task
 * @brief Periodically updates LCD with current operation mode
 * @return void
 */
void LCDDisplay_Task(void)
{
    /* Get current mode from ModeControl */
    uint8_t currentMode = ModeControl_GetMode();
    
    /* Only update display if mode has changed */
    if(currentMode != PreviousMode) {
        /* Clear first line */
        hLCD_ClearFirstLine();
        
        /* Move cursor to first line, first position */
        hLCD_MoveCursor(1, 0);
        
        /* Display new mode message */
        if(currentMode == Automatic) {
            hLCD_WriteString("MODE: AUTO");
        } else {
            hLCD_WriteString("MODE: MANUAL");
        }
        
        /* Update stored mode value */
        PreviousMode = currentMode;
    }
}

/** @} */ // End of Display_Task group