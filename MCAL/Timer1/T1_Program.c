/**
 * @file     T1_Program.c
 * @author   Hesham Ahmed       (Hisham4Ahmed@gmail.com)
 * @author   Dev.Hozifa Ahmed   (hozifasedik@gmail.com)
 * @author   Rev.Naira Mohamed   (naira.mohammed.76@gmail.com)
 * @brief    Implementation of TIMER1 driver functions with detailed line-by-line explanation.
 *           Provides initialization, start/stop, and PWM control.
 * @version  0.3
 * @date     2025-09-04
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#include "../../Common/Config.h"  /* Include project configuration header */

#if TIMER1_Driver   /* Compile this code only if TIMER1 driver is enabled */

#include "../../Common/Macro.h"           /* Common macros like SetBit, ClearBit */
#include "../RegistersAddress.h"           /* Register addresses for ATmega32 */
#include "T1_Interface.h"                  /* Public interface of TIMER1 driver */
#include "T1_Private.h"                    /* Private definitions for TIMER1 driver */
#include "T1_Config.h"                     /* User configuration for TIMER1 driver */

/* ===================== Implementation ===================== */

/**
 * @brief Initialize TIMER1 peripheral.
 * @details Sets Fast PWM mode, TOP value, output compare modes, and initial duty cycle.
 * @return TIMER1_Status_t Returns TIMER1_OK if initialization succeeds.
 */
TIMER1_Status_t T1_Init(void)
{
    /* Clear all WGM bits first to avoid accidental wrong mode */
    T1_CLEAR_WGM_BITS();

    /* Set Fast PWM – ICR1 as TOP (mode 14) */
    SetBit(TCCR1B_Reg, T1_WGM13_B);    /* Set WGM13 = 1 */
    SetBit(TCCR1B_Reg, T1_WGM12_B);    /* Set WGM12 = 1 */
    SetBit(TCCR1A_Reg, T1_WGM11_B);    /* Set WGM11 = 1 */
    ClearBit(TCCR1A_Reg, T1_WGM10_B);  /* Clear WGM10 = 0 */

    /* Set TOP value from configuration */
    T1_WRITE_ICR1(TIMER1_TOP_VALUE);   /* ICR1 = TOP value, defines PWM period */

    /* Configure Compare Output mode for channel A */
    TCCR1A_Reg &= ~((1<<T1_COM1A1_B)|(1<<T1_COM1A0_B));          /* Clear COM1A1 and COM1A0 */
    TCCR1A_Reg |= (TIMER1_OC1A_MODE << T1_COM1A0_B);             /* Set mode according to config (non-inverting, etc.) */

    /* Configure Compare Output mode for channel B */
    TCCR1A_Reg &= ~((1<<T1_COM1B1_B)|(1<<T1_COM1B0_B));          /* Clear COM1B1 and COM1B0 */
    TCCR1A_Reg |= (TIMER1_OC1B_MODE << T1_COM1B0_B);             /* Set mode according to config */

    /* Set initial duty cycle if it's greater than 0 */
    if (TIMER1_INIT_DUTY_CYCLE > 0)
    {
        /* Convert duty percentage to OCR value */
        uint16_t init_ocr = T1_DUTY_TO_OCR(TIMER1_INIT_DUTY_CYCLE, ICR1_Reg);
        
        /* Write initial duty to channel A */
        T1_WRITE_OCR1A(init_ocr);
        
        /* Write initial duty to channel B */
        T1_WRITE_OCR1B(init_ocr);
    }

    return TIMER1_OK;  /* Initialization successful */
}

/**
 * @brief Start TIMER1 counting.
 * @details Applies prescaler from configuration to start timer.
 * @return TIMER1_Status_t Returns TIMER1_OK on success.
 */
TIMER1_Status_t T1_Start(void)
{
    /* Apply configured prescaler to start timer */
    T1_SET_PRESCALER(TIMER1_PRESCALER);  /* Writes prescaler bits to TCCR1B */
    return TIMER1_OK;                     /* Timer started successfully */
}

/**
 * @brief Stop TIMER1 counting.
 * @details Stops timer by selecting "no clock source".
 * @return TIMER1_Status_t Returns TIMER1_OK on success.
 */
TIMER1_Status_t T1_Stop(void)
{
    /* Set prescaler to 0, effectively stopping the timer */
    T1_SET_PRESCALER(T1_PSC_NO_CLOCK);   /* Timer clock source disconnected */
    return TIMER1_OK;                     /* Timer stopped */
}

/**
 * @brief Set PWM duty cycle for a specific channel.
 * @param[in] channel The PWM channel (T1_CHANNEL_A or T1_CHANNEL_B)
 * @param[in] duty Duty cycle percentage (0..100)
 * @return TIMER1_Status_t Returns TIMER1_OK if successful, TIMER1_ERROR if invalid channel.
 */
TIMER1_Status_t T1_SetDuty(TIMER1_Channel_t channel, uint8_t duty)
{
    /* Clamp duty to max 100% */
    if (duty > 100) duty = 100;

    /* Convert duty percentage to OCR value */
    uint16_t compare_value = T1_DUTY_TO_OCR(duty, ICR1_Reg);

    /* Write compare value to selected channel */
    if (channel == T1_CHANNEL_A)
    {
        T1_WRITE_OCR1A(compare_value);   /* Update OCR1A register */
    }
    else if (channel == T1_CHANNEL_B)
    {
        T1_WRITE_OCR1B(compare_value);   /* Update OCR1B register */
    }
    else
    {
        return TIMER1_ERROR;              /* Invalid channel */
    }

    return TIMER1_OK;                     /* Duty updated successfully */
}

/**
 * @brief Set the TOP value for Timer1 in Fast PWM mode.
 * @param[in] topValue Maximum counter value (ICR1)
 * @return TIMER1_Status_t Returns TIMER1_OK if TOP value is updated successfully.
 */
TIMER1_Status_t T1_SetTopValue(uint16_t topValue)
{
    /* Write new TOP value to ICR1 register */
    T1_WRITE_ICR1(topValue);

    return TIMER1_OK;                     /* TOP value updated successfully */
}

#endif /* TIMER1_Driver */  /* End of TIMER1 driver conditional compilation */
