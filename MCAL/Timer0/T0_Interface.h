/**
 * @file     T0_Interface.h
 * @author   Ahmed Ashraf
 * @author   Mohamed Atif
 * @brief 
 * @version   0.1
 * @date      2025-08-15
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _T0_INTERFACE_H_
#define _T0_INTERFACE_H_

#include "T0_Config.h"
#include "T0_Private.h"
#include "../../Common/Macro.h"
#include "../RegistersAddress.h"
#include <stdint.h>

/**
 * @fn T0_FastPWM_Mode_Init
 * @brief Initializes Timer0 in Fast PWM mode.
 *
 * @details Configures Timer0 registers for Fast PWM operation.
 *          Uses predefined macros for prescaler, duty cycle, and output type.
 *          This setup enables waveform generation with adjustable polarity and resolution.
 *
 * @note Modify `TimerPrescaller0`, `Timer0_InitDutyCycle`, and `FastPWM_OutputType`
 *       in the configuration interface to customize behavior.
 */
void T0_FastPWM_Mode_Init(void);
/**--------------------------------------------------------------*/
/**
 * @fn mTimer0_ChangeDutyCycle
 * @brief Updates the duty cycle of Timer0 in Fast PWM mode.
 *
 * @details Recalculates and sets the OCR0 register based on the desired duty cycle.
 *          Adjusts waveform polarity according to the selected action type.
 *
 * @param DutyCycle Duty cycle percentage (0–100).
 * @param ActionType Output polarity mode.
 *        - `Inverting`: Output clears on compare match.
 *        - `Non_inverting`: Output sets on compare match.
 *
 * @return void
 *
 * @note This function assumes Timer0 is already initialized in Fast PWM mode.
 */
void mTimer0_ChangeDutyCycle(uint8_t DutyCycle, uint8_t ActionType);
#endif /*_T0_INTERFACE_H_*/