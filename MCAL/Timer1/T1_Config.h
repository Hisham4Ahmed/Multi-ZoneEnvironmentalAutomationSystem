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
 *          NoClockSource   = 0
            Prescaller_1    = 1
            Prescaller_8    = 2
            Prescaller_32   = 3
            Prescaller_64   = 4
            Prescaller_128  = 5
            Prescaller_256  = 6
            Prescaller_1024 = 7
 */
#define Timer1_Prescaller  Prescaller_1
/**
 * @def Timer1_CompareOutputMode
 * @brief Choosing Mode for Timer1 
 * @details 
 *              NormalOperation =0
                NonInverting    =2
                Inverting       =3 

 */
#define CompareOutputMode  NonInverting
/**
 * @def Timer1_WaveGenMode
 * @brief Choosing Mode for Timer1 
 * @details 
                Normal          =0
                PhaseCorrect    =1
                CTC             =2
                FastPwm         =3

 */

#define initialDutyCycle   50

/**
 * @def   Timer1_NoClkMask
 * @def   Timer1_StopBitMask 
 * @brief Mask for the bits in TCCR2
 */

#define Timer1_NoClkMask          0xF8

#define Timer1_PWMStop              0xCF //5th and 4th bits cleared
/**
 * @def Timer1_Top 
 * @brief The top value in the PWM
 */
#define Timer1_Top  255





#endif /*_T1_CONFIG_H_*/
