/**
 * @file     T0_Config.h
 * @author   Ahmed Ashraf
 * @author   Mohamed Atif
 * @brief    Configuration macros for Timer0 on ATmega32.      
 * @version   0.2
 * @date      2025-08-15
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _T0_CONFIG_H_
#define _T0_CONFIG_H_

/**
 * @def     TimerPrescaller0
 * @brief   Prescaler setting for Timer0.
 * @details Defines the clock division factor applied to Timer0.
 *          Example: Timer0Prescaller_64 divides system clock by 64.
 */
#define TimerPrescaller0 Timer0Prescaller_64

/**
 * @def FastPWM_OutputType
 * @brief Output polarity configuration for Fast PWM mode.
 * @details Determines waveform behavior:
 *          - Inverting: Output clears on compare match, sets at BOTTOM.
 *          - Non_inverting: Output sets on compare match, clears at BOTTOM.
 */
#define FastPWM_OutputType Non_inverting

/**
 * @def Timer0_InitDutyCycle
 * @brief Initial duty cycle percentage for Fast PWM signal.
 * @details Value range: 0–100 (%). Used to calculate OCR0 value.
 */
#define Timer0_InitDutyCycle 80

/**
 * @def Timer0_Top
 * @brief Maximum count value for Timer0.
 * @details For 8-bit Timer0, the top value is 255.
 */
#define Timer0_Top 255


#endif /*_T0_CONFIG_H_*/