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

/*ISR For Compare Match*/
void __vector_10(void)  __attribute__((signal));

/*-------------------------------------------------------------------------------------- */
/*Fast PWM Mode*/
void T0_FastPWM_Mode_Init();




/*---------------------------------------------------------------------------------------*/

#define CompareValue 250

#define Num_of_Compare_Match 1000
#define Prescalar_value 64

#endif /*_T0_INTERFACE_H_*/