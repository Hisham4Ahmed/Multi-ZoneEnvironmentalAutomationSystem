/**
 * @file     T0_Interface.h
 * @author   <Developer>
 * @author   <Reviewer>
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
/*-------------------------------------------------------------------------------------*/
/* CTC Mode */
void T0_CTC_Mode_Init();
/*
* @fn       T0_CTC_Mode_Init
* @brief    This Function is used to initialize Timer0 on CTC Mode 
* @Note     You can change the prescaler or compare value from the interface , Remember To Enable Global Interrupt 
*/

/*ISR For Compare Match*/
void __vector_10(void)  __attribute__((signal));
/*
* @fn(ISR)    void __vector_10(void)
* @brief      This Fn(ISR) is used to perform the a speceific action Contained in the Fn implemenetation
*/

/*-------------------------------------------------------------------------------------- */
/*Fast PWM Mode*/
void T0_FastPWM_Mode_Init();
/*
* @fn       T0_FastPWM_Mode_Init
* @brief    This Function is used to initialize Timer0 on Fast PWM Mode
* @Note     You can change the prescaler or duty cycle or output type from the interface 
*/
void mTimer0_ChangeDutyCycle(uint8_t DutyCycle,uint8_t ActionType );
/*
* @fn       mTimer0_ChangeDutyCycle
* @brief    This Function is used to Change The Duty Cycle of the timer
* @param    DutyCycle : The Value Of The Duty Cycle , options (0~100)
* @param    ActionType: The Type Of Action That Will Be Performed When Changing The Duty Cycle
                         and it's options are :
                                    -inverting
                                    -Non-inverting
*
*/ 


/*---------------------------------------------------------------------------------------*/



#endif /*_T0_INTERFACE_H_*/