/**
 * @file     Btn_Program.c
 * @author   Developer: Naira Mohamed (naira.mohammed.76@gmail.com)
 * @author   Reviewer: Hozifa Ahmed (hozifasedik@gmail.com)
 * @author   Refactor Developer: Mohammed Atif   "medoatifatif@gmailcom"
 * @brief    Implementation of button driver, contains the logic for initialization, 
 *           button status, and interrupt service routine for button action.
 * @version   0.3
 * @date      2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#include "../../Common/Config.h"
#if Btn_Driver

#include "../../Common/Macro.h"
#include "../../MCAL/DIO/DIO_Private.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/EXTI/EXTI_Interface.h"
#include "../../MCAL/GIE/GIE.h"

#include "Btn_Interface.h"
#include "Btn_Config.h"
#include "Btn_Private.h"

/**
 * @var CurrentMode Global variable to store the current operation mode (Auto/Manual).
 */
uint8_t static CurrentMode =  StartingMode;

uint8_t hBtn_GetStatus(void)
{
    return CurrentMode;
}

void hBtn_ISRAction()
{
    Toggle(CurrentMode);
}

void hBtn_Init()
{
    DIO_Direction_Pin(GroupD, Pin2, DIO_Input);
    DIO_Write_Pin(GroupD, Pin2, High);
    mEXTI0_CallBack(hBtn_ISRAction);
    mEXTI0_Enable();
    mGIE_Enable();
}



#endif /* Btn_Driver */