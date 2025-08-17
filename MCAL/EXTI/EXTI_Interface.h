/**
 * @file        EXTI_Interface.h
 * @author      Develpoer:  Mohamed Diaa
 * @author      Reviewer:   Hozaifa Ahmed
 * @brief       External Interrupt Interfacing components
 * @version     0.2
 * @date        2025-08-17
 *
 * @copyright Copyright (c) 2025 , Gestell Company
 */

#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_

/**
 * @brief       Enabling the External Interrupt INT0
 * @param       [no parameters]
 * @return      None
 */

void mEXTI0_Enable();
/*----------------------------------------------*/

/**
 * @brief       Enabling the External Interrupt INT1
 * @param       [no parameters]
 * @return      None
 */

void mEXTI1_Enable();
/*----------------------------------------------*/

/**
 * @brief       Enabling the External Interrupt INT2
 * @param       [no parameters]
 * @return      None
 */

void mEXTI2_Enable();
//--------------------------------------


/**
 * @brief External Interrupt( INT0) ISR
 * @param [no parameters]
 * @return Void
 */
void __vector_1(void) __attribute__((signal));

/**
 * @brief External Interrupt (INT1) ISR
 * @param [no parameters]
 * @return Void
 */
void __vector_2(void) __attribute__((signal));

/**
 * @brief External Interrupt (INT2) ISR
 * @param [no parameters]
 * @return Void
 */
void __vector_3(void) __attribute__((signal));

#endif /*_EXTI_INTERFACE_H_*/