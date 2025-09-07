/**
 * @file T2_Interface.h
 * @author Mohammed Diaa Developer-> Mohammeddiaato@gmail.com
 * @author Hozifah Ahmed Reviwer  ->
 * @brief  This File is made for the Interfacing Elements of the Timer2  
 * @version 0.1
 * @date 2025-08-30
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */


#ifndef _T2_INTERFACE_H_
#define _T2_INTERFACE_H_
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

/**
 * @brief Enables the Output Compare Interrupt for Timer2.
 *
 * This function activates the interrupt for the Output Compare event on Timer2.
 */
void mTimer2_OutCompINTEnable(void);
 
/**
 * @brief Timer2 Output Compare Interrupt Service Routine.
 *
 * This is the interrupt handler for the Timer2 Output Compare event.
 * It is automatically called when the Output Compare condition is met.
 */
void __vector_4(void) __attribute__((signal));



#endif /*_T2_INTERFACE_H_*/