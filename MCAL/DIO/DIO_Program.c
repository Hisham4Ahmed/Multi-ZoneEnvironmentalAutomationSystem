/**
 * @file     DIO_Program.c
 * @author   Dev. Hozifa Ahmed (hozifasedik@gmail.com)
 * @author   Rev. Naira Mohamed (naira.mohammed.76@gmail.com)
 * @brief    Digital Input/Output Driver Implementation
 * @details  Provides implementation for DIO pin and port control functions
 * @version  0.2
 * @date     2025-08-21
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#include "../../Common/Config.h"

#if  DIO_Driver 

#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "../../Common/Macro.h"
#include "../../MCAL/RegistersAddress.h"

/* ========== PIN APIs ========== */

/**
 * @brief  Configure single pin direction
 * @param  GroupName      Port group
 * @param  PinNumber      Pin number
 * @param  DirectionState Direction (input/output)
 * @return void
 * @note Valid pin numbers are 0-7, invalid pins are ignored
 */

void DIO_Direction_Pin(uint8_t GroupName , uint8_t PinNumber , uint8_t DirectionState)
{
    if (PinNumber >= Pin0 && PinNumber <= Pin7)
    {
        if (DirectionState == DIO_Output)
        {
            switch (GroupName)
            {
                case GroupA: SetBit(DDRA_Reg, PinNumber); break;
                case GroupB: SetBit(DDRB_Reg, PinNumber); break;
                case GroupC: SetBit(DDRC_Reg, PinNumber); break;
                case GroupD: SetBit(DDRD_Reg, PinNumber); break;
                default: break;
            }
        }
        else if (DirectionState == DIO_Input)
        {
            switch (GroupName)
            {
                case GroupA: ClearBit(DDRA_Reg, PinNumber); break;
                case GroupB: ClearBit(DDRB_Reg, PinNumber); break;
                case GroupC: ClearBit(DDRC_Reg, PinNumber); break;
                case GroupD: ClearBit(DDRD_Reg, PinNumber); break;
                default: break;
            }
        }
        else
        {
           /* Invalid direction state - do nothing */
        }
    }
    else
    {
         /* Invalid pin number - do nothing */
    }
}

/**
 * @brief  Write logic value to single pin
 * @param  GroupName   Port group
 * @param  PinNumber   Pin number
 * @param  OutputType  Output value (high/low)
 * @return void
 * @note Valid pin numbers are 0-7, invalid pins are ignored
 */

void DIO_Write_Pin(uint8_t GroupName ,  uint8_t PinNumber , uint8_t OutputType)
{
    if (PinNumber >= Pin0 && PinNumber <= Pin7)
    {
        if (OutputType == DIO_High)
        {
            switch (GroupName)
            {
                case GroupA: SetBit(PORTA_Reg, PinNumber); break;
                case GroupB: SetBit(PORTB_Reg, PinNumber); break;
                case GroupC: SetBit(PORTC_Reg, PinNumber); break;
                case GroupD: SetBit(PORTD_Reg, PinNumber); break;
                default: break;
            }
        }
        else if (OutputType == DIO_Low)
        {
            switch (GroupName)
            {
                case GroupA: ClearBit(PORTA_Reg, PinNumber); break;
                case GroupB: ClearBit(PORTB_Reg, PinNumber); break;
                case GroupC: ClearBit(PORTC_Reg, PinNumber); break;
                case GroupD: ClearBit(PORTD_Reg, PinNumber); break;
                default: break;
            }
        }
        else
        {
           /* Invalid output type - do nothing */
        }
    }
    else
    {
         /* Invalid pin number - do nothing */
    }
}

/**
 * @brief  Read logic value from single pin
 * @param  GroupName   Port group
 * @param  PinNumber   Pin number
 * @return uint8_t     Pin value (0 or 1)
 * @retval 0 Pin is in low state
 * @retval 1 Pin is in high state
 * @note Returns 0 for invalid pin numbers or groups
 */

uint8_t DIO_Read_Pin(uint8_t GroupName, uint8_t PinNumber)
{
    uint8_t InputValue = 0;
    if (PinNumber >= Pin0 && PinNumber <= Pin7)
    {
        switch (GroupName)
        {
            case GroupA: InputValue = GetBit(PINA_Reg, PinNumber); break;
            case GroupB: InputValue = GetBit(PINB_Reg, PinNumber); break;
            case GroupC: InputValue = GetBit(PINC_Reg, PinNumber); break;
            case GroupD: InputValue = GetBit(PIND_Reg, PinNumber); break;
            default: break;
        }
    }
    else
    {
        /* Invalid pin number - return 0 */
    }
    return InputValue;
}

/**
 * @brief  Toggle pin logic value
 * @param  GroupName   Port group
 * @param  PinNumber   Pin number
 * @return void
 * @note Valid pin numbers are 0-7, invalid pins are ignored
 */

void DIO_Toggle_Pin(uint8_t GroupName , uint8_t PinNumber)
{
    if (PinNumber >= Pin0 && PinNumber <= Pin7)
    {
        switch (GroupName)
        {
            case GroupA: ToggleBit(PORTA_Reg, PinNumber); break;
            case GroupB: ToggleBit(PORTB_Reg, PinNumber); break;
            case GroupC: ToggleBit(PORTC_Reg, PinNumber); break;
            case GroupD: ToggleBit(PORTD_Reg, PinNumber); break;
            default: break;
        }
    }
    else
    {
        /* Invalid pin number - do nothing */
    }
}

/* ========== GROUP APIs ========== */

/**
 * @brief  Set direction for whole port
 * @param  GroupName        Port group
 * @param  DirectionValue   Port direction value
 * @return void
 * @note DirectionValue: 0x00 = all inputs, 0xFF = all outputs
 */

void DIO_Direction_Group(uint8_t GroupName , uint8_t DirectionValue)
{
    switch (GroupName)
    {
        case GroupA: DDRA_Reg = DirectionValue; break;
        case GroupB: DDRB_Reg = DirectionValue; break;
        case GroupC: DDRC_Reg = DirectionValue; break;
        case GroupD: DDRD_Reg = DirectionValue; break;
        default: break;
    }
}

/**
 * @brief  Write value to whole port
 * @param  GroupName     Port group
 * @param  OutputValue   Port output value
 * @return void
 * @note OutputValue: 0x00 = all low, 0xFF = all high
 */

void DIO_Write_Group(uint8_t GroupName ,  uint8_t OutputValue)
{
    switch (GroupName)
    {
        case GroupA: PORTA_Reg = OutputValue; break;
        case GroupB: PORTB_Reg = OutputValue; break;
        case GroupC: PORTC_Reg = OutputValue; break;
        case GroupD: PORTD_Reg = OutputValue; break;
        default: break;
    }
}

/**
 * @brief  Read value from whole port
 * @param  GroupName   Port group
 * @return uint8_t     Port input value
 * @note Returns 0 for invalid port groups
 */

uint8_t DIO_Read_Group(uint8_t GroupName)
{
    uint8_t InputValue = 0;
    switch (GroupName)
    {
        case GroupA: InputValue = PINA_Reg; break;
        case GroupB: InputValue = PINB_Reg; break;
        case GroupC: InputValue = PINC_Reg; break;
        case GroupD: InputValue = PIND_Reg; break;
        default: break;
    }
    return InputValue;
}


#endif /* DIO_Driver */