/**
 * @file T2_Config.h
 * @author Mohammed Diaa    (mohammeddiaato@gmail.com)  Developer 
 * @author Hesham Ahmed     (Hisham4Ahmed@gmail.com)    Reviewer
 * @brief  This File is made for the configuration of the Timer2 Config file 
 * @version 0.3
 * @date 2025-09-04
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */



#ifndef _T2_CONFIG_H_
#define _T2_CONFIG_H_
#include "T2_Private.h"
#include "../../Common/Macro.h"
/**
 * @def Timer2_Prescaller
 * @brief Prescaler setting for Timer2.
 *
 * @details Defines the clock division factor applied to Timer2.
 *          Example: Prescaller_64 divides system clock by 64.
 */
#define Timer2_Prescaller Prescaller_1
/**
 * @def CompareOutputMode
 * @brief Output polarity configuration for Fast PWM mode.
 *
 * @details Determines waveform behavior:
 *          - Inverting: Output clears on compare match, sets at BOTTOM.
 *          - NonInverting: Output sets on compare match, clears at BOTTOM.
 */
#define CompareOutputMode NonInverting
/**
 * @def Timer2_WaveGenMode
 * @brief Waveform generation mode selection for Timer2.
 *
 * @details Available modes:
 *          - Normal        = 0
 *          - PhaseCorrect  = 1
 *          - CTC           = 2
 *          - FastPwm       = 3 -> what we are covering
 */
#define Timer2_WaveGenMode FastPwm
/**
 * @def initialDutyCycle
 * @brief Initial duty cycle percentage for Timer2 PWM.
 *
 * @details Value range: 0–100 (%). Used to calculate OCR2 value.
 */
#define initialDutyCycle 50

/**
 * @def Timer2_NoClkMask
 * @brief Bit mask to disable Timer2 clock source.
 *
 * @details Clears CS22:CS20 bits in TCCR2 to stop the timer.
 */
#define Timer2_NoClkMask 0xF8
/**
 * @def Timer2_PWMStop
 * @brief Bit mask to stop PWM output on Timer2.
 *
 * @details Clears COM21:COM20 bits in TCCR2 (bits 5 and 4).
 */
#define Timer2_PWMStop 0xCF
/**
 * @def Timer2_Top
 * @brief Maximum count value for Timer2.
 *
 * @details For 8-bit Timer2, the top value is 255.
 */
#define Timer2_Top 255



#endif /*_T2_CONFIG_H_*/