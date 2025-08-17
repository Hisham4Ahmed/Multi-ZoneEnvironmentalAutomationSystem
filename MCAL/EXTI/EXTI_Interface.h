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
#include "../RegistersAddress.h"
/**
 * @brief Reset pin Interrupting( RESET)
 * @param [no parameters]
 * @return Void
 */
void __vector_0(void) __attribute__((signal));


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


/**
 * @brief  Timer/Counter2 Compare Match Interrupting (TIMER2 COMP)
 * @param [no parameters]
 * @return Void
 */
void __vector_4(void) __attribute__((signal));


/**
 * @brief  Timer/Counter2 Overflow Interrupting ( TIMER2 OVF)
 * @param [no parameters]
 * @return Void
 */
void __vector_5(void) __attribute__((signal));


/**
 * @brief  Timer/Counter1 Capture Event Interrupting  (TIMER1 CAPT)
 * @param [no parameters]
 * @return Void
 */
void __vector_6(void) __attribute__((signal));


/**
 * @brief  Timer/Counter1 Compare Match A Interrupting (TIMER1 COMPA)
 * @param [no parameters]
 * @return Void
 */
void __vector_7(void) __attribute__((signal));


/**
 * @brief Timer/Counter1 Compare Match B Interrupting  (TIMER1 COMPB) 
 * @param [no parameters]
 * @return Void
 */
void __vector_8(void) __attribute__((signal));


/**
 * @brief  Timer/Counter1 Overflow Interrupting  ( TIMER1 OVF)
 * @param [no parameters]
 * @return Void
 */
void __vector_9(void) __attribute__((signal));


/**
 * @brief Timer/Counter0 Compare Match Interrupting  ( TIMER0 COMP)
 * @param [no parameters]
 * @return Void
 */
void __vector_10(void) __attribute__((signal));


/**
 * @brief Timer/Counter0 Overflow Interrupting  (TIMER0 OVF)
 * @param [no parameters]
 * @return Void
 */
void __vector_11(void) __attribute__((signal));


/**
 * @brief Serial Transfer Complete Interrupting  ( SPI, STC)
 * @param [no parameters]
 * @return Void
 */
void __vector_12(void) __attribute__((signal));


/**
 * @brief USART, Rx Complete Interrupting  (USART, RXC)
 * @param [no parameters]
 * @return Void
 */
void __vector_13(void) __attribute__((signal));


/**
 * @brief USART Data Register Empty Interrupting  ( USART, UDRE)
 * @param [no parameters]
 * @return Void
 */
void __vector_14(void) __attribute__((signal));


/**
 * @brief USART, Tx Complete Interrupting  ( USART, TXC)
 * @param [no parameters]
 * @return Void
 */
void __vector_15(void) __attribute__((signal));


/**
 * @brief  ADC Conversion Complete Interrupting  ( ADC)
 * @param [no parameters]
 * @return Void
 */
void __vector_16(void) __attribute__((signal));


/**
 * @brief EEPROM Ready Interrupting  ( EE_RDY)
 * @param [no parameters]
 * @return Void
 */
void __vector_17(void) __attribute__((signal));


/**
 * @brief Analog Comparator Interrupting  ( ANA_COMP)
 * @param [no parameters]
 * @return Void
 */
void __vector_18(void) __attribute__((signal));


/**
 * @brief Two-wire Serial Interface Interrupting  (TWI)
 * @param [no parameters]
 * @return Void
 */
void __vector_19(void) __attribute__((signal));


/**
 * @brief Store Program Memory Ready Interrupting  (SPM_RDY)
 * @param [no parameters]
 * @return Void
 */
void __vector_20(void) __attribute__((signal));

#endif /*_EXTI_INTERFACE_H_*/