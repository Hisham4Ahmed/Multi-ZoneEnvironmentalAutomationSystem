/**
 * @file     T1_Interface.h
 * @author   Hesham Ahmed       (Hisham4Ahmed@gmail.com)
 * @author   Dev.Hozifa Ahmed   (hozifasedik@gmail.com)
 * @author   Rev.Naira Mohamed  (???????????@gmail.com)
 * @brief    Public interface for TIMER1 driver
 * @version  0.2
 * @date     2025-09-04
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */


#ifndef _T1_INTERFACE_H_
#define _T1_INTERFACE_H_


#include "T1_Config.h"
#include <stdint.h>

/*************************************************************
 *                       ENUMS & TYPES
 *************************************************************/

/**
 * @brief Return status for Timer1 functions
 */
typedef enum
{
    TIMER1_OK = 0,
    TIMER1_ERROR
}TIMER1_Status_t;


/**
 * @brief Channels for Timer1
 */
typedef enum
{
    TIMER1_CHANNEL_A = 0,
    TIMER1_CHANNEL_B
}TIMER1_Channel_t;


/*************************************************************
 *                       APIS
 *************************************************************/

/**
 * @brief Initialize Timer1 with the selected configuration
 * 
 * This function configures the mode, prescaler, compare output modes,
 * and initial TOP value (if applicable).
 */
TIMER1_Status_t TIMER1_Init(void);


/**
 * @brief Start Timer1
 */
void TIMER1_Start(void);


/**
 * @brief Stop Timer1
 */
void TIMER1_Stop(void);


/**
 * @brief Set duty cycle for a given channel (OC1A or OC1B)
 * 
 * @param channel   TIMER1_CHANNEL_A or TIMER1_CHANNEL_B
 * @param duty      Duty cycle (0-100 %)
 * @return TIMER1_Status_t 
 */
TIMER1_Status_t TIMER1_SetDutyCycle(TIMER1_Channel_t channel, uint8_t duty);


/**
 * @brief Set TOP value (only valid if mode = Fast PWM with ICR1 as TOP)
 * 
 * @param topValue  The TOP value to set in ICR1 register
 */
void TIMER1_SetTopValue(uint16_t topValue);


/**
 * @brief Register callback for Timer1 overflow interrupt
 * 
 * @param callback Pointer to function to be executed on overflow
 */
void TIMER1_SetOverflowCallback(void (*callback)(void));


/**
 * @brief Register callback for Timer1 Compare Match A interrupt
 */
void TIMER1_SetCompareA_Callback(void (*callback)(void));


/**
 * @brief Register callback for Timer1 Compare Match B interrupt
 */
void TIMER1_SetCompareB_Callback(void (*callback)(void));



#endif /*_T1_INTERFACE_H_*/
