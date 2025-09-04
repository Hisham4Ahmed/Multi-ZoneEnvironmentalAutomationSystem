/**
 * @file     T1_Program.c
 * @author   Hesham Ahmed       (Hisham4Ahmed@gmail.com)
 * @author   Dev.Hozifa Ahmed   (hozifasedik@gmail.com)
 * @author   Rev.Naira Mohamed  (???????????@gmail.com)
 * @brief    Timer1 Driver Implementation (Fast PWM – OC1A/OC1B)
 * @version  0.2
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

/*------------------------- Implementation -------------------------*/

/**
 * @brief Initialize Timer1 in Fast PWM mode (ICR1 as TOP)
 */
void T1_Init(uint16_t top_value)
{
    /* Set Fast PWM Mode 14: WGM13:0 = 1110 */
    SET_BIT(TCCR1B_Reg, T1_WGM13_B);
    SET_BIT(TCCR1B_Reg, T1_WGM12_B);
    SET_BIT(TCCR1A_Reg, T1_WGM11_B);
    CLR_BIT(TCCR1A_Reg, T1_WGM10_B);

    /* Clear OC1A & OC1B on Compare Match, non-inverting mode */
    SET_BIT(TCCR1A_Reg, T1_COM1A1_B);
    CLR_BIT(TCCR1A_Reg, T1_COM1A0_B);

    SET_BIT(TCCR1A_Reg, T1_COM1B1_B);
    CLR_BIT(TCCR1A_Reg, T1_COM1B0_B);

    /* Set TOP value */
    ICR1_Reg = top_value;
}

/**
 * @brief Set Duty Cycle for OC1A or OC1B
 * 
 * @param channel : T1_CHANNEL_A / T1_CHANNEL_B
 * @param duty    : duty cycle percentage (0–100)
 */
void T1_SetDuty(uint8_t channel, uint8_t duty)
{
    uint16_t compare_value = (ICR1_Reg * duty) / 100;

    if(channel == T1_CHANNEL_A)
    {
        OCR1A_Reg = compare_value;
    }
    else if(channel == T1_CHANNEL_B)
    {
        OCR1B_Reg = compare_value;
    }
}

/**
 * @brief Start Timer1 with prescaler
 * 
 * @param prescaler : choose from T1_NO_CLOCK, T1_PRESCALER_1, T1_PRESCALER_8, ...
 */
void T1_Start(uint8_t prescaler)
{
    /* Clear CS12:0 bits */
    TCCR1B_Reg &= ~((1<<T1_CS12_B)|(1<<T1_CS11_B)|(1<<T1_CS10_B));

    /* Apply prescaler */
    TCCR1B_Reg |= prescaler;
}

/**
 * @brief Stop Timer1
 */
void T1_Stop(void)
{
    /* Clear clock source bits → timer stops */
    TCCR1B_Reg &= ~((1<<T1_CS12_B)|(1<<T1_CS11_B)|(1<<T1_CS10_B));
}



#endif /* TIMER1_Driver */
