/**
 * @file     T1_Interface.h
 * @author   Hesham Ahmed       (Hisham4Ahmed@gmail.com)
 * @author   Dev.Hozifa Ahmed   (hozifasedik@gmail.com)
 * @author   Rev.Naira Mohamed  (naira.mohammed.76@gmail.com)
 * @brief    Public interface for TIMER1 driver.
 *           Provides initialization, start/stop, and PWM control functions.
 * @version  0.3
 * @date     2025-09-04
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _T1_INTERFACE_H_
#define _T1_INTERFACE_H_

#include "T1_Config.h"
#include <stdint.h>

/**
 * @enum TIMER1_Status_t
 * @brief Status codes returned by TIMER1 driver functions.
 */
typedef enum
{
    TIMER1_OK = 0,    /**< Operation completed successfully */
    TIMER1_ERROR      /**< Operation failed */
} TIMER1_Status_t;

/**
 * @enum TIMER1_Channel_t
 * @brief TIMER1 PWM channels.
 */
typedef enum
{
    T1_CHANNEL_A = 0, /**< OC1A channel */
    T1_CHANNEL_B      /**< OC1B channel */
} TIMER1_Channel_t;

/**
 * @brief Initialize TIMER1 peripheral.
 * @details 
 *  Configures Timer1 registers based on settings in T1_Config.h.
 *  Must be called before any other TIMER1 function.
 * 
 * @return TIMER1_Status_t Returns TIMER1_OK if initialization succeeds, TIMER1_ERROR otherwise.
 */
TIMER1_Status_t T1_Init(void);

/**
 * @brief Start TIMER1 counting.
 * @details 
 *  Starts the timer with the prescaler specified in T1_Config.h.
 * 
 * @return TIMER1_Status_t Returns TIMER1_OK on success, TIMER1_ERROR on failure.
 */
TIMER1_Status_t T1_Start(void);

/**
 * @brief Stop TIMER1 counting.
 * @details 
 *  Stops the timer and clears prescaler settings.
 * 
 * @return TIMER1_Status_t Returns TIMER1_OK on success, TIMER1_ERROR on failure.
 */
TIMER1_Status_t T1_Stop(void);

/**
 * @brief Set PWM duty cycle for a specified channel.
 * @param[in] channel The PWM channel (T1_CHANNEL_A or T1_CHANNEL_B)
 * @param[in] duty Duty cycle value (0..100%)
 * @return TIMER1_Status_t Returns TIMER1_OK if duty cycle is updated successfully, TIMER1_ERROR otherwise.
 */
TIMER1_Status_t T1_SetDuty(TIMER1_Channel_t channel, uint8_t duty);

/**
 * @brief Set the TOP value for Timer1 in Fast PWM mode.
 * @param[in] topValue Maximum count value (ICR1)
 * @return TIMER1_Status_t Returns TIMER1_OK if TOP value is set successfully, TIMER1_ERROR otherwise.
 */
TIMER1_Status_t T1_SetTopValue(uint16_t topValue);

#endif /* _T1_INTERFACE_H_ */
