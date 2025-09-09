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

/**
 * @fn    void mTimer1_InitFastPWMMode(void);
 * @brief Initializes Timer1 in Fast PWM mode.
 */
void mTimer1_InitFastPWMMode(void);
 
/**
 * @fn    void mTimer1_ChangeDutyCycle(uint8_t DutyCycle );    
 * @brief Changes the duty cycle of the Timer1 Fast PWM output.
 * @param DutyCycle The desired duty cycle percentage (0-100).
 */
void mTimer1_ChangeDutyCycle(uint8_t DutyCycle );
 
/**
 * @fn    void mTimer1_FastPWMStop(void);
 * @brief Stops the Fast PWM operation on Timer1.
 */

void mTimer1_FastPWMStop(void);
/**
 * @fn    void mTimer1_TimerStop(void);
 * @brief Stops the Timer1 operation by making it with no clock
 */
void mTimer1_TimerStop(void);


#endif /*_T1_INTERFACE_H_*/
