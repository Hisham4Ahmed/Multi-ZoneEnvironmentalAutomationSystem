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

#include "../ZoneControl/ZoneControl_Interface.h"
#include "../ModeControl/ModeControl_Interface.h"
//#include "../Communication/Communication_Interface.h"
#include "../../HAL/LCD/LCD_Interface.h"
#include "../../MCAL/GIE/GIE.h"

/**
 * @fn MultizoneApp_Init
 * @brief Initializes the Multizone application.
 * @details This function initializes all necessary peripherals, drivers, and 
 *         components for the Multizone application needed for operation it should be called once at system startup.
 * @note This function must be called before any other application functions.
 */
void MultizoneApp_Init();
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