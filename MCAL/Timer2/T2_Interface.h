/**
 * @file T2_Interface.h
 * @author Mohammed Diaa    (mohammeddiaato@gmail.com)  Developer 
 * @author Hesham Ahmed     (Hisham4Ahmed@gmail.com)    Reviewer
 * @brief  This File is made for the Interfacing Elements of the Timer2  
 * @version 0.3
 * @date 2025-08-30
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */


#ifndef _T2_INTERFACE_H_
#define _T2_INTERFACE_H_

#include <stdint.h>
#include "T2_Private.h"
#include "T2_Config.h"
#include <stdint.h>


/**
 * @fn    void mTimer2_InitFastPWMMode(void);
 * @brief Initializes Timer2 in Fast PWM mode.
 */
void mTimer2_InitFastPWMMode(void);
 
/**
 * @fn    void mTimer2_ChangeDutyCycle(uint8_t DutyCycle );    
 * @brief Changes the duty cycle of the Timer2 Fast PWM output.
 * @param DutyCycle The desired duty cycle percentage (0-100).
 */
void mTimer2_ChangeDutyCycle(uint8_t DutyCycle );
 
/**
 * @fn    void mTimer2_FastPWMStop(void);
 * @brief Stops the Fast PWM operation on Timer2.
 */

void mTimer2_FastPWMStop(void);
/**
 * @fn    void mTimer2_TimerStop(void);
 * @brief Stops the Timer2 operation by making it with no clock
 */
void mTimer2_TimerStop(void);


#endif /*_T2_INTERFACE_H_*/
