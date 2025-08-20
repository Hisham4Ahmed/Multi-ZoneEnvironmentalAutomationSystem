/**
 * @file     DIO_Program.c
 * @author   <Hozifa Ahmed>
 * @author   <Reviewer>
 * @brief 
 * @version   0.2
 * @date      2025-08-20
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */
#include "DIO_Interface.h"
#include "../../Common/Macro.h"
#include "DIO_Private.h"

/* ========== PIN APIs ========== */
void DIO_Direction_Pin(uint8_t GroupName , uint8_t PinNumber , uint8_t DirectionState)
{
    if (PinNumber >= Pin0 && PinNumber <= Pin7)
    {
        if (DirectionState == DIO_Output)
        {
            switch (GroupName)
            {
                case GroupA: SetBit(DDRA_REG, PinNumber); break;
                case GroupB: SetBit(DDRA_REG, PinNumber); break;
                case GroupC: SetBit(DDRC_REG, PinNumber); break;
                case GroupD: SetBit(DDRD_REG, PinNumber); break;
            }
        }
        else if (DirectionState == DIO_Input)
        {
            switch (GroupName)
            {
                case GroupA: ClearBit(DDRA_REG, PinNumber); break;
                case GroupB: ClearBit(DDRA_REG, PinNumber); break;
                case GroupC: ClearBit(DDRC_REG, PinNumber); break;
                case GroupD: ClearBit(DDRD_REG, PinNumber); break;
            }
        }
    }
}

void DIO_Write_Pin(uint8_t GroupName ,  uint8_t PinNumber , uint8_t OutputType)
{
    if (PinNumber >= Pin0 && PinNumber <= Pin7)
    {
        if (OutputType == DIO_High)
        {
            switch (GroupName)
            {
                case GroupA: SetBit(PORTA_REG, PinNumber); break;
                case GroupB: SetBit(PORTB_REG, PinNumber); break;
                case GroupC: SetBit(PORTC_REG, PinNumber); break;
                case GroupD: SetBit(PORTD_REG, PinNumber); break;
            }
        }
        else if (OutputType == DIO_Low)
        {
            switch (GroupName)
            {
                case GroupA: ClearBit(PORTA_REG, PinNumber); break;
                case GroupB: ClearBit(PORTB_REG, PinNumber); break;
                case GroupC: ClearBit(PORTC_REG, PinNumber); break;
                case GroupD: ClearBit(PORTD_REG, PinNumber); break;
            }
        }
    }
}

uint8_t DIO_Read_Pin(uint8_t GroupName, uint8_t PinNumber)
{
    uint8_t InputValue = 0;
    if (PinNumber >= Pin0 && PinNumber <= Pin7)
    {
        switch (GroupName)
        {
            case GroupA: InputValue = GetBit(PINA_REG, PinNumber); break;
            case GroupB: InputValue = GetBit(PINB_REG, PinNumber); break;
            case GroupC: InputValue = GetBit(PINC_REG, PinNumber); break;
            case GroupD: InputValue = GetBit(PIND_REG, PinNumber); break;
        }
    }
    return InputValue;
}

/* ========== GROUP APIs ========== */
void DIO_Direction_Group(uint8_t GroupName , uint8_t DirectionValue)
{
    switch (GroupName)
    {
        case GroupA: DDRA_REG = DirectionValue; break;
        case GroupB: DDRA_REG = DirectionValue; break;
        case GroupC: DDRC_REG = DirectionValue; break;
        case GroupD: DDRD_REG = DirectionValue; break;
    }
}

void DIO_Write_Group(uint8_t GroupName ,  uint8_t OutputValue)
{
    switch (GroupName)
    {
        case GroupA: PORTA_REG = OutputValue; break;
        case GroupB: PORTB_REG = OutputValue; break;
        case GroupC: PORTC_REG = OutputValue; break;
        case GroupD: PORTD_REG = OutputValue; break;
    }
}

uint8_t DIO_Read_Group(uint8_t GroupName)
{
    uint8_t InputValue = 0;
    switch (GroupName)
    {
        case GroupA: InputValue = PINA_REG; break;
        case GroupB: InputValue = PINB_REG; break;
        case GroupC: InputValue = PINC_REG; break;
        case GroupD: InputValue = PIND_REG; break;
    }
    return InputValue;
}
