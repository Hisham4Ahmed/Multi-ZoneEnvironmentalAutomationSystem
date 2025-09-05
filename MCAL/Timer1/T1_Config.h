/**
 * @file     T1_Config.h
 * @author   Hesham Ahmed       (Hisham4Ahmed@gmail.com)
 * @author   Dev.Hozifa Ahmed   (hozifasedik@gmail.com)
 * @author   Rev.Naira Mohamed  (naira.mohammed.76@gmail.com)
 * @brief    Configuration header file for TIMER1 driver.
 *           This file contains user-configurable macros for
 *           setting Timer1 mode, prescaler, output compare behavior,
 *           top value, and initial duty cycle.
 * @version  0.3
 * @date     2025-09-04
 * 
 * @copyright Copyright (c) 2025, Gestell Company
 */

#ifndef _T1_CONFIG_H_
#define _T1_CONFIG_H_

/**
 * @defgroup TIMER1_MODE Selection of Timer1 Operating Mode
 * @{
 */

/** 
 * @brief Timer1 mode selection
 * @details 
 *  Set the mode of Timer1. Options depend on ATmega32 datasheet.
 *  Mode 14 corresponds to Fast PWM with ICR1 as TOP.
 */
#define TIMER1_MODE   14   /**< Fast PWM, ICR1 as TOP */

/** @} */

/**
 * @defgroup TIMER1_PRESCALER Timer1 Clock Prescaler
 * @{
 */

/**
 * @brief Timer1 clock prescaler
 * @details 
 *  Select the prescaler for Timer1. Options:
 *   - T1_PSC_CLK_1
 *   - T1_PSC_CLK_8
 *   - T1_PSC_CLK_64
 *   - T1_PSC_CLK_256
 *   - T1_PSC_CLK_1024
 */
#define TIMER1_PRESCALER   T1_PSC_CLK_8

/** @} */

/**
 * @defgroup TIMER1_OC_MODE Output Compare Mode
 * @{
 */

/**
 * @brief Output Compare mode for OC1A
 * @details 
 *  2 = Clear OC1A on compare match (non-inverting PWM)
 */
#define TIMER1_OC1A_MODE   2

/**
 * @brief Output Compare mode for OC1B
 * @details 
 *  2 = Clear OC1B on compare match (non-inverting PWM)
 */
#define TIMER1_OC1B_MODE   2

/** @} */

/**
 * @defgroup TIMER1_TOP_DUTY Timer1 TOP value and initial duty cycle
 * @{
 */

/**
 * @brief Maximum counter value for Timer1
 * @details 
 *  Used as TOP in Fast PWM mode when ICR1 is used as TOP.
 */
#define TIMER1_TOP_VALUE   0xFFFF  /**< Max value for ICR1 */

/**
 * @brief Initial duty cycle of PWM
 * @details 
 *  Set the starting duty cycle (0..100%). Can be changed at runtime.
 */
#define TIMER1_INIT_DUTY_CYCLE   0

/** @} */

#endif /* _T1_CONFIG_H_ */
