/**
 * @file T1_Config.h
 * @author Mohammed Diaa    (mohammeddiaato@gmail.com)  Developer 
 * @author Hesham Ahmed     (Hisham4Ahmed@gmail.com)    Reviewer
 * @brief  This File Is Done For Using PWM on Timer1 pins 
 * @version 0.3
 * @date 2025-08-30
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */

#ifndef _T1_CONFIG_H_
#define _T1_CONFIG_H_
/**
 * @def Timer1_Prescaller
 * @brief Prescaler setting for Timer1.
 *
 * @details Selects the clock source and division factor:
 * - NoClockSource      = 0  -> Timer stopped
 * - Prescaller_1       = 1  -> No prescaling
 * - Prescaller_8       = 2  -> Clock ÷ 8
 * - Prescaller_64      = 3  -> Clock ÷ 64
 * - Prescaller_256     = 4  -> Clock ÷ 256
 * - Prescaller_1024    = 5  -> Clock ÷ 1024
 * - Ext_Source_Falling = 6  -> External clock on T1 (falling edge)
 * - Ext_Source_Rising  = 7  -> External clock on T1 (rising edge)
 */
#define Timer1_Prescaller T1_Prescaller_8

/**
 * @def Timer1_CompareOutputMode
 * @brief Output compare mode for Timer1.
 *
 * @details Defines OC1A/OC1B behavior:
 * - NormalOperation = 0 -> Disconnected
 * - NonInverting    = 2 -> Clear on compare match, set at BOTTOM
 * - Inverting       = 3 -> Set on compare match, clear at BOTTOM
 */
#define CompareOutputMode T1_NonInverting

/**
 * @def Timer1_WaveGenMode
 * @brief Waveform generation mode for Timer1.
 *
 * @details Selects counting behavior:
 * - Normal  = 0   -> Normal counting
 * - FastPwm = 14  -> Fast PWM using ICR1 as TOP
 */
#define Timer1_WaveGenMode FastPwm

/**
 * @def initialDutyCycle
 * @brief Initial duty cycle percentage for Timer1 PWM.
 *
 * @note Value range: 0–100 percentage
 */
#define initialDutyCycle 70


/**
 * @def Timer1_NoClkMask
 * @brief Mask to disable Timer1 clock source (CS12:CS10 cleared).
 */
#define Timer1_NoClkMask 0xF8

/**
 * @def Timer1_OC1A_PWMStop
 * @brief Mask to stop PWM on OC1A (COM1A1:COM1A0 cleared).
 */
#define Timer1_OC1A_PWMStop 0x3F

/**
 * @def Timer1_OC1B_PWMStop
 * @brief Mask to stop PWM on OC1B (COM1B1:COM1B0 cleared).
 */
#define Timer1_OC1B_PWMStop 0xCF


/**
 * @def Timer1_Top
 * @brief Top value for Timer1 PWM (ICR1).
 *
 * @note Defines the PWM period. For 16-bit Timer1, typical range is 0–65535.
 */
#define Timer1_Top 999

/**
 * @def NonInverting_BitMask
 * @brief Bit mask for setting OC1A/OC1B to non-inverting mode.
 */
#define NonInverting_BitMask 0xA0

/**
 * @def Inverting_BitMask
 * @brief Bit mask for setting OC1A/OC1B to inverting mode.
 */
#define Inverting_BitMask 0xF0

/**
 * @def OC1A_Channel
 * @brief Identifier for OC1A output channel.
 */
#define OC1A_Channel 0

/**
 * @def OC1B_Channel
 * @brief Identifier for OC1B output channel.
 */
#define OC1B_Channel 1

/**
 * @def Channel_All
 * @brief Identifier for both OC1A and OC1B channels.
 */
#define Channel_All 2




#endif /*_T1_CONFIG_H_*/
