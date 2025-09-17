/**
 * @file    MULTIZONEAPP_Program.c
 * @author  Mohammed Diaa    (mohammeddiaato@gmail.com)  Developer
 * @author  Hesham Ahmed     (Hisham4Ahmed@gmail.com)    Reviewer
 * @brief   This file implement the APIs used in the Multizone APP
 * @version 0.2
 * @date    2025-09-16
 *
 * @copyright Copyright (c) 2025 , Gestell Company
 */

#include "MultiZoneApp_Interface.h"

/**
 * @note Important to see
 *
 *      Justification about my decision:
 *              1-   these four vars are implemented to indicate that the modules initialized successfully
 *                   this way I can make sure what part is problem and handle it in main or any other option
 *                   So for this reason I made these vars and made the init function return uint8_t type
 *              
 *              2- you can get the idea of these vars from the mode control app files it appears to have my point
 */
extern uint8_t ModeControl_Initialized;
extern uint8_t ZoneControl_Initialized;
extern uint8_t Communication_Initialized;
extern uint8_t LCDDisplay_Initialized;

uint8_t MultizoneApp_Init()
{
    ModeControl_Init();
    if (ModeControl_Initialized == 0)
    {
        return 1;
    }
    ZoneControl_Init();
    if (ZoneControl_Initialized == 0)
    {
        return 2;
    }
    Communication_Init();
    if (Communication_Initialized == 0)
    {
        return 3;
    }
    LCDDisplay_Init();
    if (LCDDisplay_Initialized == 0)
    {
        return 4;
    }
    mGIE_Enable(); // global interrupt enabled

    /**
     * @note i couldnot Understand how should I do something like this here
     * - Set initial state (Mode = StartingMode).  */

    return 0;
}

void MultizoneApp_Run()
{
    while (1)
    {
        ModeControl_Task();
        Communication_Task();
        if (Communication_HasError())
        {
            ModeControl_Task(); // to transform to manual mode to handle it manually
        }
        ZoneControl_Task();

        LCDDisplay_Task();
    }
}