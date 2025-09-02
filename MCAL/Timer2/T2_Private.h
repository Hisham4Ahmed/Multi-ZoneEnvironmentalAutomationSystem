/**
 * @file T2_Private.h
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief
 * @version 0.1
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
 * @brief These are the Bits that control the Timer mode like PWM fast, Phase correct and So on
 */
#define WGM20_Bit   6
#define WGM21_Bit   3
/**
 * @def   CS22_Bit
 * @def   CS21_Bit
 * @def   CS20_Bit
 * @brief These are the Bits That Controls the Prescallers Options from timer to be off unill 1024 prescaller
 */

#define CS22_Bit    2
#define CS21_Bit     1
#define CS20_Bit     0

/**
 * @def     Timer2_Prescaller_Set 
 * @brief   This is Timer 2 prescaller PWM freq vlaues  
 */
typedef enum
{
    Timer2_NoClockSource   = 0,
    Timer2_Prescaller_1    = 1,
    Timer2_Prescaller_8    = 2,
    Timer2_Prescaller_32   = 3,
    Timer2_Prescaller_64   = 4,
    Timer2_Prescaller_128  = 5,
    Timer2_Prescaller_256  = 6,
    Timer2_Prescaller_1024 = 7

} Timer2_Prescaller_Set;


/**
 * @def   COM21_Bit
 * @def   COM20_Bit
 * @brief These are the Bits that controls Compare output mode Bits 
 */
#define COM21_Bit   5
#define COM20_Bit   4
/**
 * @def     Timer2_COM_FastPWM 
 * @brief    
 */
typedef enum
{
   NormalOperation=0,
   NonInverting=2,
   Inverting=3, 



}    Timer2_COM_FastPWM ;



#endif /*_T2_PRIVATE_H_*/