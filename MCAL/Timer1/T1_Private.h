/**
 * @file T1_Private.h
 * @author Mohammed Diaa    (mohammeddiaato@gmail.com)  Developer 
 * @author Hesham Ahmed     (Hisham4Ahmed@gmail.com)    Reviewer
 * @brief This File is made for writing Private Data of Timer1
 * @version 0.3
 * @date 2025-08-30
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */

#ifndef _T1_PRIVATE_H_
#define _T1_PRIVATE_H_

/**
 * @brief Bit positions for TCCR1A register configuration.
 * 
 * These bits are used to configure the Compare Output Mode and Waveform Generation Mode
 * for Timer/Counter1 in the TCCR1A register.
 */
typedef enum
{
    COM1A1_Bit = 7, /**< Compare Output Mode for Channel A, bit 1 */
    COM1A0_Bit = 6, /**< Compare Output Mode for Channel A, bit 0 */
    COM1B1_Bit = 5, /**< Compare Output Mode for Channel B, bit 1 */
    COM1B0_Bit = 4, /**< Compare Output Mode for Channel B, bit 0 */
    WGM11_Bit  = 1, /**< Waveform Generation Mode bit 0 */
    WGM10_Bit  = 0  /**< Waveform Generation Mode bit 1 */
} TCCR1A_Bits;

/**
 * @brief Bit positions for TCCR1B register configuration.
 * 
 * These bits are used to configure the Waveform Generation Mode and Clock Select
 * for Timer/Counter1 in the TCCR1B register.
 */
typedef enum
{
    WGM13_Bit = 4, /**< Waveform Generation Mode bit 3 */
    WGM12_Bit = 3, /**< Waveform Generation Mode bit 2 */
    CS12_Bit  = 2, /**< Clock Select bit 2 */
    CS11_Bit  = 1, /**< Clock Select bit 1 */
    CS10_Bit  = 0  /**< Clock Select bit 0 */
} TCCR1B_Bits;

/**
 * @brief Prescaler settings for Timer1 clock source.
 * 
 * These values determine the division factor applied to the system clock
 * before feeding it to Timer1.
 */
typedef enum
{
    T1_NoClockSource      = 0, /**< Timer stopped (no clock source) */
    T1_Prescaller_1       = 1, /**< No prescaling (direct clock) */
    T1_Prescaller_8       = 2, /**< Clock divided by 8 */
    T1_Prescaller_64      = 3, /**< Clock divided by 64 */
    T1_Prescaller_256     = 4, /**< Clock divided by 256 */
    T1_Prescaller_1024    = 5, /**< Clock divided by 1024 */
    Ext_Source_Falling = 6, /**< External clock on T1 pin, falling edge */
    Ext_Source_Rising  = 7  /**< External clock on T1 pin, rising edge */
} Timer1_Prescaller_Set;

/**
 * @brief Waveform generation modes for Timer1.
 * 
 * These modes define how the timer counts and generates output signals.
 */
typedef enum
{
    T1_Normal   = 0,  /**< Normal counting mode */
    T1_FastPwm  = 14  /**< Fast PWM mode using ICR1 as TOP */
} Timer1_WaveGenModes;

/**
 * @brief Compare Output Modes for Fast PWM operation.
 * 
 * These modes define the behavior of the output compare pins (OC1A/OC1B)
 * during Fast PWM operation.
 */
typedef enum
{
    T1_NormalOperation = 0, /**< Normal port operation, OC1A/OC1B disconnected */
    T1_NonInverting    = 2, /**< Clear OC1A/OC1B on compare match, set at BOTTOM */
    T1_Inverting       = 3  /**< Set OC1A/OC1B on compare match, clear at BOTTOM */
} Timer1_COM_FastPWM;

#endif /*_T1_PRIVATE_H_*/