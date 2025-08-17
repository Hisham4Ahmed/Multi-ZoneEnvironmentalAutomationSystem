/**
 * @file     EXTI_Interface.h
 * @author   <Developer>
 * @author   <Reviewer>
 * @brief
 * @version   0.1
 * @date      2025-08-15
 *
 * @copyright Copyright (c) 2025 , Gestell Company
 */

#ifndef _EXTI_INTERFACE_H_  
#define _EXTI_INTERFACE_H_





void mEXTI_EnableALLWanted(); 
void mEXTI0_Enable(); 
void mEXTI1_Enable(); 
void mEXTI2_Enable(); 


void mEXTI_DisableALL(); 
void mEXTI0_Disable(); 
void mEXTI1_Disable(); 
void mEXTI2_Disable(); 



/**
 * @brief External Interrupt( INT0)
 * @param [no parameters]
 * @return Void
 */
void __vector_1(void) __attribute__((signal));


/**
 * @brief External Interrupt (INT1)
 * @param [no parameters]
 * @return Void
 */
void __vector_2(void) __attribute__((signal));


/**
 * @brief External Interrupt (INT2)
 * @param [no parameters]
 * @return Void
 */
void __vector_3(void) __attribute__((signal));

#endif /*_EXTI_INTERFACE_H_*/