/**
 * @file     Btn_Interface.h
 * @author   Developer: Naira Mohamed (naira.mohammed.76@gmail.com)
 * @author   Reviewer: Hozifa Ahmed (hozifasedik@gmail.com)
 * @brief    Bublic interface for button driver, includes functions prototypes and user accessible macros.
 * @version   0.2
 * @date      2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _BTN_INTERFACE_H_
#define _BTN_INTERFACE_H_
#include <stdint.h>

#include "Btn_Private.h"

/**
 * @brief this macro is to toggle modes when button is pressed
 */
#define Toggle(Mode)  Mode^=1

/**
 * @fn this function is to get the status of the button, 
 *       if pressed, it will return 0
 *       if Not pressed, it will return 1
 */
uint8_t hBtn_GetStatus(void);

/**
 * @fn This function includes the action to happen when interrupt occurs.
 *     When interrupt, the mode will toggle from auto to manual or vice versa.
 */
void hBtn_ISRAction();

/**
 * @fn  this function is to initialize button hardware.
 * @note  In this function:
 *           1) Make button pin as input
 *           2) Enable internal pull up
 *           3) Register EXTI0 callback with sense control "Falling Edge"
 *           4) Enable EXTI0 and Global Interrupt
 */
void hBtn_Init();

#endif /*_BTN_INTERFACE_H_*/