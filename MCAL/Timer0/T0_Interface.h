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
/*-------------------------------------------------------------------------------------*/
/* CTC Mode */
/** 
* @fn       T0_CTC_Mode_Init
* @brief    This Function is used to initialize Timer0 on CTC Mode 
* @note     You can change the prescaler or compare value from the Config.h 
*/

void T0_CTC_Mode_Init();
/*--------------------------------------------------*/

/** 
* @fn(ISR)    void __vector_10(void)
* @brief      This Fn(ISR) is used to perform the a speceific action Contained in the Fn implemenetation
* @note       Remember To Enable Global Interrupt 
*/

void __vector_10(void)  __attribute__((signal));

/*-------------------------------------------------------------------------------------- */
/** 
* @fn       T0_FastPWM_Mode_Init
* @brief    This Function is used to initialize Timer0 on Fast PWM Mode
* @note     You can change the prescaler or duty cycle or output type from the interface 
*/

void T0_FastPWM_Mode_Init();

/*------------------------------------------------*/

/** 
* @fn       mTimer0_ChangeDutyCycle
* @brief    This Function is used to Change The Duty Cycle of the timer
* @param    DutyCycle : The Value Of The Duty Cycle , options (0~100)
* @param    ActionType: The Type Of Action That Will Be Performed When Changing The Duty Cycle
                         and it's options are :
                                    -inverting
                                    -Non-inverting
*
*/ 

void mTimer0_ChangeDutyCycle(uint8_t DutyCycle,uint8_t ActionType );



/*---------------------------------------------------------------------------------------*/

/**
 * @fn       T0_Call_Back_fn
 * @brief    This Function is used to set the Call Back Function That will be executed in Timer0 ISR
 * @param    PF : Pointer to Function that will be executed in the ISR
 */
void T0_Call_Back_fn(void(*PF)(void));



#endif /*_T0_INTERFACE_H_*/