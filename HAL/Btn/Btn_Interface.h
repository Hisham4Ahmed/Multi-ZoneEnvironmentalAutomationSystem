/**
 * @file     Btn_Interface.h
 * @author   Naira Mohamed (naira.mohammed.76@gmil.com)
 * @author   Hozifa Ahmed 
 * @brief    Bublic interface for button driver, includes functions prototypes and user accessible macros.
 * @version   0.2
 * @date      2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _BTN_INTERFACE_H_
#define _BTN_INTERFACE_H_
#include <stdint.h>

/**
 * @brief this macro is to toggle modes when button is pressed
 */
#define Toggle(Mode)  Mode^=1

/**
 * @fn  this function is to initialize button hardware.
 */
void hBtn_Init();

/**
 * @fn this function is to get the status of the button.
 */
uint8_t hBtn_GetStatus(void);

/**
 * @fn this function includes the action to happen when interrupt occurs.
 */
void hBtn_ISRAction();


#endif /*_BTN_INTERFACE_H_*/