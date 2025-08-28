/**
 * @file     Btn_Program.c
 * @author   Developer: Naira Mohamed (naira.mohammed.76@gmail.com)
 * @author   Reviewer: Hozifa Ahmed (hozifasedik@gmail.com)
 * @brief    Implementation of button driver, contains the logic for initialization, 
 *           button status, and interrupt service routine for button action.
 * @version   0.2
 * @date      2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */
#include "HAL/Btn/Btn_Interface.h"
#include "HAL/Btn/Btn_Config.h"
#include "HAL/Btn/Btn_Private.h"
#include "MCAL/GIE/GIE.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Private.h"
#include "Common/Macro.h"

/**
 * @var CurrentMode Global variable to store the current operation mode (Auto/Manual).
 */
uint8_t CurrentMode =  StartingMode;

uint8_t hBtn_GetStatus(void)
{
    uint8_t status = DIO_Read_Pin(GroupD, Pin2);
    return status;
}

void hBtn_ISRAction()
{
    if(hBtn_GetStatus() == 0)  //button is pressed
    {
        Toggle(CurrentMode);
    }
    else 
    {
        //Do Nothing
    }
    
}

void hBtn_Init()
{
    DIO_Direction_Pin(GroupD, Pin2, DIO_Input);
    DIO_Write_Pin(GroupD, Pin2, High);
    mEXTI0_CallBack(hBtn_ISRAction);
    mEXTI0_Enable();
    mGIE_Enable();
}



