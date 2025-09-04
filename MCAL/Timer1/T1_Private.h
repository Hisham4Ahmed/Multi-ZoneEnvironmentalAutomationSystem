/**
 * @file     T1_Private.h
 * @author   Hesham Ahmed       (Hisham4Ahmed@gmail.com)
 * @author   Dev.Hozifa Ahmed   (hozifasedik@gmail.com)
 * @author   Rev.Naira Mohamed  (???????????@gmail.com)
 * @brief    Private definitions for TIMER1 driver
 * @version  0.2
 * @date     2025-09-04
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */

#ifndef _T1_PRIVATE_H_
#define _T1_PRIVATE_H_


#include "../../Common/Macro.h"     /* SetBit / ClearBit / GetBit ... */
#include "../RegistersAddress.h"   /* TCCR1A_Reg, TCCR1B_Reg, OCR1A_Reg, ICR1_Reg, SREG_Reg ... */
#include <stdint.h>

/* -------------------- Bit positions (ATmega32) -------------------- */
/* TCCR1A */
#define T1_WGM10_B   0
#define T1_WGM11_B   1
#define T1_FOC1B_B   2
#define T1_FOC1A_B   3
#define T1_COM1B0_B  4
#define T1_COM1B1_B  5
#define T1_COM1A0_B  6
#define T1_COM1A1_B  7

/* TCCR1B */
#define T1_CS10_B    0
#define T1_CS11_B    1
#define T1_CS12_B    2
#define T1_WGM12_B   3
#define T1_WGM13_B   4
#define T1_ICES1_B   6
#define T1_ICNC1_B   7

/* TIMSK / TIFR bits (Timer1 related) */
#define T1_TOIE1_B   2
#define T1_OCIE1B_B  3
#define T1_OCIE1A_B  4
#define T1_TICIE1_B  5

#define T1_TOV1_B    2
#define T1_OCF1B_B   3
#define T1_OCF1A_B   4
#define T1_ICF1_B    5

/* -------------------- Prescaler codes (CS12..CS10) -------------------- */
/* Values written into TCCR1B[CS12:CS10] */
#define T1_PSC_NO_CLOCK   0u
#define T1_PSC_CLK_1      1u
#define T1_PSC_CLK_8      2u
#define T1_PSC_CLK_64     3u
#define T1_PSC_CLK_256    4u
#define T1_PSC_CLK_1024   5u
#define T1_PSC_EXT_FALL   6u
#define T1_PSC_EXT_RISE   7u

/* -------------------- SREG helpers (atomic 16-bit writes) -------------------- */
/* Save SREG and disable global IRQ, return previous SREG value */
static inline uint8_t T1_SaveAndDisableIRQ(void)
{
    uint8_t prev = SREG_Reg;
    ClearBit(SREG_Reg, 7); /* clear I-bit */
    return prev;
}

/* Restore previous SREG value */
static inline void T1_RestoreIRQ(uint8_t prevSREG)
{
    SREG_Reg = prevSREG;
}

/* -------------------- Safe 16-bit write macros -------------------- */
/* Use these to write ICR1 / OCR1A / OCR1B (16-bit registers) atomically */
#define T1_WRITE_ICR1_SAFE(val16)  do { uint8_t __s = T1_SaveAndDisableIRQ(); ICR1_Reg  = (uint16_t)(val16); T1_RestoreIRQ(__s); } while(0)
#define T1_WRITE_OCR1A_SAFE(val16) do { uint8_t __s = T1_SaveAndDisableIRQ(); OCR1A_Reg = (uint16_t)(val16); T1_RestoreIRQ(__s); } while(0)
#define T1_WRITE_OCR1B_SAFE(val16) do { uint8_t __s = T1_SaveAndDisableIRQ(); OCR1B_Reg = (uint16_t)(val16); T1_RestoreIRQ(__s); } while(0)

/* -------------------- Duty conversion helper -------------------- */
/* Convert duty% (0..100) to OCR value given TOP (topVal: ICR1 or OCR1A depending on mode) */
#define T1_DUTY_TO_OCR(duty_percent, topVal) \
    ( (uint16_t)( ((uint32_t)(duty_percent) * (uint32_t)((topVal) + 1U)) / 100U ) )

/* -------------------- Small register helpers -------------------- */
/* Set prescaler (CS12..CS10) without touching other bits of TCCR1B */
#define T1_SET_PRESCALER(cs_val) \
    do { \
        TCCR1B_Reg &= (uint8_t)(~(0x07u)); \
        TCCR1B_Reg |= (uint8_t)((cs_val) & 0x07u); \
    } while(0)

/* Clear WGM bits (we will set appropriate combination in driver init) */
#define T1_CLEAR_WGM_BITS() \
    do { \
        TCCR1A_Reg &= (uint8_t)(~((1u<<T1_WGM10_B)|(1u<<T1_WGM11_B))); \
        TCCR1B_Reg &= (uint8_t)(~((1u<<T1_WGM12_B)|(1u<<T1_WGM13_B))); \
    } while(0)



#endif /*_T1_PRIVATE_H_*/