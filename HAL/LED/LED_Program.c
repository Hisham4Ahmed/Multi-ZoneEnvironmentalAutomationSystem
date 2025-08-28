/**
 * @file      LED_Program.c
 * @author    Developer : Hozifa Ahmed
 * @author    Reviewer :  Ahmed Ashraf
 * @brief     LED Driver Implementation
 * @version   0.3
 * @date      2025-08-28
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Private.h"
#include "../../Common/ZoneConfig.h"
#include "LED_Interface.h"
#include "LED_Config.h"

/* ------------------- APIs Implementation ------------------- */

void hLed_Init(uint8_t ZoneNumber)
{
    if (ZoneNumber >= 1 && ZoneNumber <= LED_TOTAL_NUMBER)
    {
        DIO_Direction_Pin(
            LED_Array[ZoneNumber - 1].Port,
            LED_Array[ZoneNumber - 1].Pin,
            DIO_Output
        );
    }
}

void hLed_On(uint8_t ZoneNumber)
{
    if (ZoneNumber >= 1 && ZoneNumber <= LED_TOTAL_NUMBER)
    {
#if (LED_CONNECTION == LED_ACTIVE_HIGH)
        DIO_Write_Pin(
            LED_Array[ZoneNumber - 1].Port,
            LED_Array[ZoneNumber - 1].Pin,
            DIO_High
        );
#elif (LED_CONNECTION == LED_ACTIVE_LOW)
        DIO_Write_Pin(
            LED_Array[ZoneNumber - 1].Port,
            LED_Array[ZoneNumber - 1].Pin,
            DIO_Low
        );
#endif
    }
}

void hLed_Off(uint8_t ZoneNumber)
{
    if (ZoneNumber >= 1 && ZoneNumber <= LED_TOTAL_NUMBER)
    {
#if (LED_CONNECTION == LED_ACTIVE_HIGH)
        DIO_Write_Pin(
            LED_Array[ZoneNumber - 1].Port,
            LED_Array[ZoneNumber - 1].Pin,
            DIO_Low
        );
#elif (LED_CONNECTION == LED_ACTIVE_LOW)
        DIO_Write_Pin(
            LED_Array[ZoneNumber - 1].Port,
            LED_Array[ZoneNumber - 1].Pin,
            DIO_High
        );
#endif
    }
}

 