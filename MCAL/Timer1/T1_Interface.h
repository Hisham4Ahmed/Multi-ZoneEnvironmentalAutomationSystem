/**
 * @file T1_Interface.h
 * @author Mohammed Diaa    (mohammeddiaato@gmail.com)  Developer 
 * @author Hesham Ahmed     (Hisham4Ahmed@gmail.com)    Reviewer
 * @brief  This File is made for showing APIs of Timer1
 * @version 0.3
 * @date 2025-08-30
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */


#ifndef _T1_INTERFACE_H_
#define _T1_INTERFACE_H_
#include "T1_Private.h"
#include "T1_Config.h"
#include <stdint.h>
#include "../RegistersAddress.h"

/**
 * @fn void mTimer1_InitFastPWMMode(void)
 * @brief Initializes Timer1 in Fast PWM mode.
 *
 * @details Configures Timer1 registers for Fast PWM operation using ICR1 as TOP.
 *          Sets waveform generation mode, output compare behavior, and prescaler.
 *
 * @note Configuration parameters (prescaler, duty cycle, output mode) must be
 *       defined in T1_Config.h before calling this function.
 */
void mTimer1_InitFastPWMMode(void);

/**
 * @fn void mTimer1_ChangeDutyCycle(uint8_t DutyCycle, uint8_t Channel)
 * @brief Updates the duty cycle of Timer1 Fast PWM output.
 *
 * @details Calculates and sets the OCR1A or OCR1B register based on the selected channel.
 *          Adjusts PWM output to reflect the new duty cycle percentage.
 *
 * @param DutyCycle Duty cycle percentage (0–100).
 * @param Channel Output channel selector:
 *        - OC1A_Channel -> Update OCR1A
 *        - OC1B_Channel -> Update OCR1B
 *        - Channel_All -> Update both channels
 *
 * @note Timer1 must be initialized in Fast PWM mode before calling this function.
 */
void mTimer1_ChangeDutyCycle(uint8_t DutyCycle, uint8_t Channel);

/**
 * @fn void mTimer1_FastPWMStop(uint8_t Channel)
 * @brief Disables Fast PWM output on the selected Timer1 channel.
 *
 * @details Clears the COM1A/COM1B bits to disconnect PWM output from OC1A/OC1B.
 *
 * @param Channel Output channel to disable:
 *        - OC1A_Channel
 *        - OC1B_Channel
 *        - Channel_All
 */
void mTimer1_FastPWMStop(uint8_t Channel);

/**
 * @fn void mTimer1_TimerStop(void)
 * @brief Stops Timer1 by disabling its clock source.
 *
 * @details Clears the CS12:CS10 bits to halt Timer1 operation.
 *          This function effectively disables counting and PWM generation.
 *
 * @note Use this to fully shut down Timer1 without modifying other registers.
 */
void mTimer1_TimerStop(void);



#endif /*_T1_INTERFACE_H_*/
