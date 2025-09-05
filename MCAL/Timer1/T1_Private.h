/**
 * @file     T1_Private.h
 * @author   Hesham Ahmed       (Hisham4Ahmed@gmail.com)
 * @author   Dev.Hozifa Ahmed   (hozifasedik@gmail.com)
 * @author   Rev.Naira Mohamed  (naira.mohammed.76@gmail.com)
 * @brief    Private definitions for TIMER1 driver.
 *           Contains register bit definitions, prescaler codes,
 *           safe write macros, and helper macros for duty cycle
 *           calculations and timer configuration.
 * @version  0.3
 * @date     2025-09-04
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _T1_PRIVATE_H_
#define _T1_PRIVATE_H_

#include "../../Common/Macro.h"
#include "../RegistersAddress.h"
#include <stdint.h>

/** @defgroup TCCR1A_Bits TCCR1A Register Bit Positions
 * @{
 */
#define T1_WGM10_B   0 /**< Waveform Generation Mode bit 0 */
#define T1_WGM11_B   1 /**< Waveform Generation Mode bit 1 */
#define T1_FOC1B_B   2 /**< Force Output Compare B */
#define T1_FOC1A_B   3 /**< Force Output Compare A */
#define T1_COM1B0_B  4 /**< Compare Output Mode B bit 0 */
#define T1_COM1B1_B  5 /**< Compare Output Mode B bit 1 */
#define T1_COM1A0_B  6 /**< Compare Output Mode A bit 0 */
#define T1_COM1A1_B  7 /**< Compare Output Mode A bit 1 */
/** @} */

/** @defgroup TCCR1B_Bits TCCR1B Register Bit Positions
 * @{
 */
#define T1_CS10_B    0 /**< Clock Select bit 0 */
#define T1_CS11_B    1 /**< Clock Select bit 1 */
#define T1_CS12_B    2 /**< Clock Select bit 2 */
#define T1_WGM12_B   3 /**< Waveform Generation Mode bit 2 */
#define T1_WGM13_B   4 /**< Waveform Generation Mode bit 3 */
/** @} */

/** @defgroup TIMER1_Prescaler Prescaler Codes
 * @brief Values to set Timer1 clock source / prescaler
 */
#define T1_PSC_NO_CLOCK   0u /**< Timer stopped */
#define T1_PSC_CLK_1      1u /**< No prescaling */
#define T1_PSC_CLK_8      2u /**< Clock / 8 */
#define T1_PSC_CLK_64     3u /**< Clock / 64 */
#define T1_PSC_CLK_256    4u /**< Clock / 256 */
#define T1_PSC_CLK_1024   5u /**< Clock / 1024 */
#define T1_PSC_EXT_FALL   6u /**< External clock on falling edge */
#define T1_PSC_EXT_RISE   7u /**< External clock on rising edge */

/** @defgroup TIMER1_SafeWrite Safe 16-bit Register Write Macros
 * @{
 */
#define T1_WRITE_ICR1(val16)  ICR1_Reg  = (uint16_t)(val16)   /**< Write 16-bit value to ICR1 */
#define T1_WRITE_OCR1A(val16) OCR1A_Reg = (uint16_t)(val16)   /**< Write 16-bit value to OCR1A */
#define T1_WRITE_OCR1B(val16) OCR1B_Reg = (uint16_t)(val16)   /**< Write 16-bit value to OCR1B */
/** @} */

/** @defgroup TIMER1_DutyCycle Duty Conversion Helper
 * @brief Convert duty cycle percentage to OCR value
 * @param duty_percent Duty cycle (0..100)
 * @param topVal Maximum counter value (TOP)
 * @return Corresponding OCR register value
 */
#define T1_DUTY_TO_OCR(duty_percent, topVal) \
    ( (uint16_t)( ((uint32_t)(duty_percent) * (uint32_t)((topVal) + 1U)) / 100U ) )

/** @defgroup TIMER1_ConfigMacros Timer Configuration Helpers
 * @{
 */

/**
 * @brief Set Timer1 prescaler
 * @param cs_val Prescaler code (T1_PSC_xxx)
 */
#define T1_SET_PRESCALER(cs_val) \
    do { \
        TCCR1B_Reg &= (uint8_t)(~(0x07u)); \
        TCCR1B_Reg |= (uint8_t)((cs_val) & 0x07u); \
    } while(0)

/**
 * @brief Clear all WGM (Waveform Generation Mode) bits
 */
#define T1_CLEAR_WGM_BITS() \
    do { \
        TCCR1A_Reg &= (uint8_t)(~((1u<<T1_WGM10_B)|(1u<<T1_WGM11_B))); \
        TCCR1B_Reg &= (uint8_t)(~((1u<<T1_WGM12_B)|(1u<<T1_WGM13_B))); \
    } while(0)

/** @} */

#endif /* _T1_PRIVATE_H_ */
