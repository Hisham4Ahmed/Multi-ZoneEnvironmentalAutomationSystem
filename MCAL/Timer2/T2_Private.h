/**
 * @file T2_Private.h
 * @author Mohammed Diaa Developer-> Mohammeddiaato@gmail.com
 * @author Eng.Hesham Ahmed
 * @brief  This File is made for the Private elements of the Timer2 Config file 
 * @version 0.3
 * @date 2025-08-30
 *
 * @copyright Copyright (c) 2025 , Gestell Company
 *
 */

#ifndef _T2_PRIVATE_H_
#define _T2_PRIVATE_H_

/**
 * @def WGM21_Bit
 * @def WGM20_Bit
 * @brief Bit positions for Waveform Generation Mode in Timer2.
 * 
 * These bits control the timer mode such as Fast PWM, Phase Correct PWM, CTC, and Normal.
 */
#define WGM20_Bit   6 /**< Waveform Generation Mode bit 0 */
#define WGM21_Bit   3 /**< Waveform Generation Mode bit 1 */

/**
 * @enum Timer2_WaveGenModes
 * @brief Waveform generation modes for Timer2.
 * 
 * These modes define how Timer2 operates in terms of counting and signal generation.
 */
typedef enum
{
  Normal        = 0, /**< Normal counting mode */
  PhaseCorrect  = 1, /**< Phase Correct PWM mode */
  CTC           = 2, /**< Clear Timer on Compare Match mode */
  FastPwm       = 3  /**< Fast PWM mode */
} Timer2_WaveGenModes;

/**
 * @def CS22_Bit
 * @def CS21_Bit
 * @def CS20_Bit
 * @brief Bit positions for Clock Select in Timer2.
 * 
 * These bits determine the prescaler value applied to the system clock for Timer2.
 */
#define CS22_Bit     2 /**< Clock Select bit 2 */
#define CS21_Bit     1 /**< Clock Select bit 1 */
#define CS20_Bit     0 /**< Clock Select bit 0 */

/**
 * @enum Timer2_Prescaller_Set
 * @brief Prescaler settings for Timer2.
 * 
 * These values define the division factor for the timer clock, affecting the frequency of Timer2.
 */
typedef enum
{
    NoClockSource   = 0, /**< Timer stopped (no clock source) */
    Prescaller_1    = 1, /**< No prescaling (direct clock) */
    Prescaller_8    = 2, /**< Clock divided by 8 */
    Prescaller_32   = 3, /**< Clock divided by 32 */
    Prescaller_64   = 4, /**< Clock divided by 64 */
    Prescaller_128  = 5, /**< Clock divided by 128 */
    Prescaller_256  = 6, /**< Clock divided by 256 */
    Prescaller_1024 = 7  /**< Clock divided by 1024 */
} Timer2_Prescaller_Set;

/**
 * @def COM21_Bit
 * @def COM20_Bit
 * @brief Bit positions for Compare Output Mode in Timer2.
 * 
 * These bits control the behavior of the OC2 pin during compare match events.
 */
#define COM21_Bit   5 /**< Compare Output Mode bit 1 */
#define COM20_Bit   4 /**< Compare Output Mode bit 0 */

/**
 * @enum Timer2_COM_FastPWM
 * @brief Compare Output Modes for Fast PWM in Timer2.
 * 
 * These modes define how the OC2 pin behaves during Fast PWM operation.
 */
typedef enum
{
   NormalOperation = 0, /**< Normal port operation, OC2 disconnected */
   NonInverting    = 2, /**< Clear OC2 on compare match, set at BOTTOM */
   Inverting       = 3  /**< Set OC2 on compare match, clear at BOTTOM */
} Timer2_COM_FastPWM;



#endif /*_T2_PRIVATE_H_*/