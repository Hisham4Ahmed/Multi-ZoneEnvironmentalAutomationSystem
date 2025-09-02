/**
 * @file T2_Config.h
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-30
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
 * @brief Choosing Prescaller for Timer2
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
#define Timer2_Prescaller  Prescaller_1
/**
 * @def Timer2_CompareOutputMode
 * @brief Choosing Mode for Timer2 
 * @details 
 *              NormalOperation =0
                NonInverting    =2
                Inverting       =3 

 */
#define CompareOutputMode  NonInverting
/**
 * @def Timer2_WaveGenMode
 * @brief Choosing Mode for Timer2 
 * @details 
                Normal          =0
                PhaseCorrect    =1
                CTC             =2
                FastPwm         =3

 */

#define DefaultDutyCycle   50

#endif /*_T2_CONFIG_H_*/