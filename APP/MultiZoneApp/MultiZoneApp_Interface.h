/**
 * @file    MULTIZONEAPP_Interface.h
 * @author  Mohammed Diaa    (mohammeddiaato@gmail.com)  Developer 
 * @author  Hesham Ahmed     (Hisham4Ahmed@gmail.com)    Reviewer   
 * @brief   This file introduce the APIs used in the Multizone APP
 * @version 0.1
 * @date    2025-09-16
 *
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _MULTIZONEAPP_INTERFACE_H_
#define _MULTIZONEAPP_INTERFACE_H_
#include <stdint.h>
#include "../ZoneControl/ZoneControl_Interface.h"
#include "../ModeControl/ModeControl_Interface.h"
//#include "../Communication/Communication_Interface.h"
#include "../../HAL/LCD/LCD_Interface.h"
#include "../../MCAL/GIE/GIE.h"

/**
 * @fn uint8_t MultizoneApp_Init(void)
 * @brief Initializes all system modules required for the Multizone application.
 *
 * @details This function performs ordered initialization of the following modules:
 *          - ModeControl
 *          - ZoneControl
 *          - Communication
 *          - LCDDisplay
 *
 *          Each module must set its internal `*_Initialized` flag to indicate success.
 *          If any module fails to initialize, the function returns a corresponding error code.
 *
 * @retval 0 All modules initialized successfully.
 * @retval 1 ModeControl failed to initialize.
 * @retval 2 ZoneControl failed to initialize.
 * @retval 3 Communication failed to initialize.
 * @retval 4 LCDDisplay failed to initialize.
 *
 * @note This function must be called before executing the main application loop.
 */

uint8_t MultizoneApp_Init();
/**
 * @fn MultizoneApp_Run
 * @brief Runs the main loop of the Multizone application.
 * @details This function contains the primary operational logic for the application, 
 *          handling tasks such as processing data, 
 *          state management, and communication.
 *           It is typically called repeatedly within the system's main event loop.
 */
void MultizoneApp_Run();



#endif /* _MULTIZONEAPP_INTERFACE_H_ */