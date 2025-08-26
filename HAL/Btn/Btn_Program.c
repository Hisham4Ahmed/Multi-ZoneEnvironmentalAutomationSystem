/**
 * @file     Btn_Program.c
 * @author   Naira Mohamed (naira.mohammed.76@gmil.com)
 * @author   Hozifa Ahmed 
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
 * @var this is a global variable to store the mode of the program.
 */
uint8_t CurrentMode =  StartingMode;
/**
 * @fn    This function is to initiate the button
 * @note  In this function:
 *           1) Make button pin as input
 *           2) Enable internal pull up
 *           3) Interrupt Enable of EXTI0 with sense control "Falling Edge"
 */
void hBtn_Init()
{
    DIO_Direction_Pin(GroupD, Pin2, DIO_Input);
    DIO_Write_Pin(GroupD, Pin2, High);
    mEXTI0_Enable();
    mGIE_Enable();
}

/**
 * @fn   this function will return the status of the button
 *       if pressed, it will return 0
 *       if Not pressed, it will return 1
 */
uint8_t hBtn_GetStatus(void)
{
    uint8_t status = DIO_Read_Pin(GroupD, Pin2);
    return status;
}

/**
 * @fn   This function is to indicate the action that will happen when interrupt occurs
 *       When interrupt, the mode will toggle from auto to manual or vice versa.
 */
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