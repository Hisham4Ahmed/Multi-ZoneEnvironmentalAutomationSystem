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
 * @brief Choosing Prescaller for Timer1
 * @details 
    NoClockSource      = 0, //< Timer stopped (no clock source) 
    Prescaller_1       = 1, //< No prescaling (direct clock) 
    Prescaller_8       = 2, //< Clock divided by 8 
    Prescaller_64      = 3, //< Clock divided by 64 
    Prescaller_256     = 4, //< Clock divided by 256 
    Prescaller_1024    = 5, //< Clock divided by 1024 
    Ext_Source_Falling = 6, //< External clock on T1 pin, falling edge 
    Ext_Source_Rising  = 7  //< External clock on T1 pin, rising edge 
 */
#define Timer1_Prescaller  Prescaller_1
/**
 * @def Timer1_CompareOutputMode
 * @brief Choosing Mode for Timer1 
 * @details 
    NormalOperation = 0, //< Normal port operation, OC1A/OC1B disconnected 
    NonInverting    = 2, //< Clear OC1A/OC1B on compare match, set at BOTTOM 
    Inverting       = 3  //< Set OC1A/OC1B on compare match, clear at BOTTOM 

 */
#define CompareOutputMode  NonInverting
/**
 * @def Timer1_WaveGenMode
 * @brief Choosing Mode for Timer1 
 * @details 
    Normal   = 0,  < Normal counting mode 
    FastPwm  = 14  < Fast PWM mode using ICR1 as TOP 

 */

#define initialDutyCycle   50

/**
 * @def   Timer1_NoClkMask
 * @def   Timer1_StopBitMask 
 * @brief Mask for the bits in TCCR1A and TCCR1B
 */

#define Timer1_NoClkMask                 0xF8
#define Timer1_OC1A_PWMStop              0x3F //7th and 6th bits cleared
#define Timer1_OC1B_PWMStop              0xCF //5th and 4th bits cleared

/**
 * @def Timer1_Top 
 * @brief The top value in the PWM
 */
#define Timer1_Top  255
/**
 * @def OC1A_FastPWM
 * @def OC1B_FastPWM
 * @def FastPWM_All
 * @brief Macros Used to make App developer choose What PWM output pin stops or do actions on them 
 */

#define OC1A_Channel   0
#define OC1B_Channel   1
#define Channel_All    2

/**
 * 
 */
#define NonInverting_BitMask    0xA0 
#define Inverting_BitMask       0xF0


#endif /*_T1_CONFIG_H_*/
