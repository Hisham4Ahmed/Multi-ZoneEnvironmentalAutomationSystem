/**
 * @file     T1_Config.h
 * @author   Hesham Ahmed       (Hisham4Ahmed@gmail.com)
 * @author   Dev.Hozifa Ahmed   (hozifasedik@gmail.com)
 * @author   Rev.Naira Mohamed  (???????????@gmail.com)
 * @brief    Configuration file for TIMER1 driver
 * @version  0.2
 * @date     2025-09-04
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */

#ifndef _T1_CONFIG_H_
#define _T1_CONFIG_H_


/*************************************************************
 *                  TIMER1 CONFIGURATIONS
 *************************************************************/

/**
 * @brief Select Timer1 mode
 * Options:
 *        0 -> Normal mode
 *        1 -> CTC mode (OCR1A as TOP)
 *        2 -> Fast PWM mode (8-bit)
 *        3 -> Fast PWM mode (9-bit)
 *        4 -> Fast PWM mode (10-bit)
 *        5 -> Fast PWM mode (ICR1 as TOP)   
 */
#define TIMER1_MODE   5


/**
 * @brief Select Timer1 prescaler
 * Options:
 *        1   -> No prescaling
 *        8   -> clk/8
 *        64  -> clk/64
 *        256 -> clk/256
 *        1024-> clk/1024
 */
#define TIMER1_PRESCALER   8


/**
 * @brief Select Output Compare Mode for Channel A
 * Options:
 *        0 -> Normal port operation, OC1A disconnected
 *        1 -> Toggle OC1A on compare match
 *        2 -> Clear OC1A on compare match (non-inverting PWM)
 *        3 -> Set OC1A on compare match (inverting PWM)
 */
#define TIMER1_OC1A_MODE   2


/**
 * @brief Select Output Compare Mode for Channel B
 * Options:
 *        0 -> Normal port operation, OC1B disconnected
 *        1 -> Toggle OC1B on compare match
 *        2 -> Clear OC1B on compare match (non-inverting PWM)
 *        3 -> Set OC1B on compare match (inverting PWM)
 */
#define TIMER1_OC1B_MODE   2


/**
 * @brief Initial TOP value (used when mode = Fast PWM with ICR1 as TOP)
 */
#define TIMER1_TOP_VALUE   19999   // for 50Hz PWM @16MHz clock, prescaler=8


/**
 * @brief Initial duty cycle (0 - 100)
 */
#define TIMER1_INIT_DUTY_CYCLE   0





#endif /*_T1_CONFIG_H_*/
