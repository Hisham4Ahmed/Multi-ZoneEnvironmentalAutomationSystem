 /**
 * @file     T1_Program.c
 * @author   Hesham Ahmed       (Hisham4Ahmed@gmail.com)
 * @author   Dev.Hozifa Ahmed   (hozifasedik@gmail.com)
 * @author   Rev.Naira Mohamed  (naira.mohammed.76@gmail.com)
 * @brief    Timer1 Driver Implementation 
 * @version  0.3
 * @date     2025-09-04
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */
#include "../../Common/Config.h"

#if TIMER1_Driver

#include "../../Common/Macro.h"
#include "../RegistersAddress.h"
#include "T1_Interface.h"
#include "T1_Private.h"
#include "T1_Config.h"

/* ===================== Implementation ===================== */

TIMER1_Status_t T1_Init(void)
{
    /* Clear WGM bits */
    T1_CLEAR_WGM_BITS();

    /* Fast PWM – ICR1 as TOP (mode 14) */
    SetBit(TCCR1B_Reg, T1_WGM13_B);
    SetBit(TCCR1B_Reg, T1_WGM12_B);
    SetBit(TCCR1A_Reg, T1_WGM11_B);
    ClearBit(TCCR1A_Reg, T1_WGM10_B);

    /* Set TOP value */
    T1_WRITE_ICR1(TIMER1_TOP_VALUE);

    /* Configure Compare Output modes (OC1A / OC1B) */
    TCCR1A_Reg &= ~((1<<T1_COM1A1_B)|(1<<T1_COM1A0_B));
    TCCR1A_Reg |= (TIMER1_OC1A_MODE << T1_COM1A0_B);

    TCCR1A_Reg &= ~((1<<T1_COM1B1_B)|(1<<T1_COM1B0_B));
    TCCR1A_Reg |= (TIMER1_OC1B_MODE << T1_COM1B0_B);

    /* Initial duty cycle if configured */
    if (TIMER1_INIT_DUTY_CYCLE > 0)
    {
        uint16_t init_ocr = T1_DUTY_TO_OCR(TIMER1_INIT_DUTY_CYCLE, ICR1_Reg);
        T1_WRITE_OCR1A(init_ocr);
        T1_WRITE_OCR1B(init_ocr);
    }

    return TIMER1_OK;
}

TIMER1_Status_t T1_Start(void)
{
    /* Apply prescaler */
    T1_SET_PRESCALER(TIMER1_PRESCALER);
    return TIMER1_OK;
}

TIMER1_Status_t T1_Stop(void)
{
    /* Stop timer */
    T1_SET_PRESCALER(T1_PSC_NO_CLOCK);
    return TIMER1_OK;
}

TIMER1_Status_t T1_SetDuty(TIMER1_Channel_t channel, uint8_t duty)
{
    if (duty > 100) duty = 100;
    uint16_t compare_value = T1_DUTY_TO_OCR(duty, ICR1_Reg);

    if (channel == T1_CHANNEL_A)
        T1_WRITE_OCR1A(compare_value);
    else if (channel == T1_CHANNEL_B)
        T1_WRITE_OCR1B(compare_value);
    else
        return TIMER1_ERROR;

    return TIMER1_OK;
}

TIMER1_Status_t T1_SetTopValue(uint16_t topValue)
{
    T1_WRITE_ICR1(topValue);
    return TIMER1_OK;
}

#endif /* TIMER1_Driver */