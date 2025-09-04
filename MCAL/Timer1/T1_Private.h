/**
 * @file     T1_Private.h
 * @author   Hesham Ahmed       (Hisham4Ahmed@gmail.com)
 * @author   Dev.Hozifa Ahmed   (hozifasedik@gmail.com)
 * @author   Rev.Naira Mohamed  (naira.mohammed.76@gmail.com)
 * @brief    Private definitions for TIMER1 driver
 * @version  0.3
 * @date     2025-09-04
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */

#ifndef _T1_PRIVATE_H_
#define _T1_PRIVATE_H_


#include "../../Common/Macro.h"
#include "../RegistersAddress.h"
#include <stdint.h>

/* TCCR1A Bits */
#define T1_WGM10_B   0
#define T1_WGM11_B   1
#define T1_FOC1B_B   2
#define T1_FOC1A_B   3
#define T1_COM1B0_B  4
#define T1_COM1B1_B  5
#define T1_COM1A0_B  6
#define T1_COM1A1_B  7

/* TCCR1B Bits */
#define T1_CS10_B    0
#define T1_CS11_B    1
#define T1_CS12_B    2
#define T1_WGM12_B   3
#define T1_WGM13_B   4

/* Prescaler codes */
#define T1_PSC_NO_CLOCK   0u
#define T1_PSC_CLK_1      1u
#define T1_PSC_CLK_8      2u
#define T1_PSC_CLK_64     3u
#define T1_PSC_CLK_256    4u
#define T1_PSC_CLK_1024   5u
#define T1_PSC_EXT_FALL   6u
#define T1_PSC_EXT_RISE   7u

/* Safe 16-bit write macros */
#define T1_WRITE_ICR1(val16)  ICR1_Reg  = (uint16_t)(val16)
#define T1_WRITE_OCR1A(val16) OCR1A_Reg = (uint16_t)(val16)
#define T1_WRITE_OCR1B(val16) OCR1B_Reg = (uint16_t)(val16)

/* Duty conversion helper */
#define T1_DUTY_TO_OCR(duty_percent, topVal) \
    ( (uint16_t)( ((uint32_t)(duty_percent) * (uint32_t)((topVal) + 1U)) / 100U ) )

/* Set prescaler */
#define T1_SET_PRESCALER(cs_val) \
    do { \
        TCCR1B_Reg &= (uint8_t)(~(0x07u)); \
        TCCR1B_Reg |= (uint8_t)((cs_val) & 0x07u); \
    } while(0)

/* Clear WGM bits */
#define T1_CLEAR_WGM_BITS() \
    do { \
        TCCR1A_Reg &= (uint8_t)(~((1u<<T1_WGM10_B)|(1u<<T1_WGM11_B))); \
        TCCR1B_Reg &= (uint8_t)(~((1u<<T1_WGM12_B)|(1u<<T1_WGM13_B))); \
    } while(0)



#endif /*_T1_PRIVATE_H_*/