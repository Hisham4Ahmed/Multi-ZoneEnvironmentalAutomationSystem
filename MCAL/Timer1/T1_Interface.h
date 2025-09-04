/**
 * @file     T1_Interface.h
 * @author   Hesham Ahmed       (Hisham4Ahmed@gmail.com)
 * @author   Dev.Hozifa Ahmed   (hozifasedik@gmail.com)
 * @author   Rev.Naira Mohamed  (naira.mohammed.76@gmail.com)
 * @brief    Public interface for TIMER1 driver
 * @version  0.3
 * @date     2025-09-04
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */


#ifndef _T1_INTERFACE_H_
#define _T1_INTERFACE_H_


#include "T1_Config.h"
#include <stdint.h>

typedef enum
{
    TIMER1_OK = 0,
    TIMER1_ERROR
} TIMER1_Status_t;

typedef enum
{
    T1_CHANNEL_A = 0,
    T1_CHANNEL_B
} TIMER1_Channel_t;

/* Initialization / control */
TIMER1_Status_t T1_Init(void);
TIMER1_Status_t T1_Start(void);
TIMER1_Status_t T1_Stop(void);

/* PWM control */
TIMER1_Status_t T1_SetDuty(TIMER1_Channel_t channel, uint8_t duty);
TIMER1_Status_t T1_SetTopValue(uint16_t topValue);


#endif /*_T1_INTERFACE_H_*/
