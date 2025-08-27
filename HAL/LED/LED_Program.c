/**
 * @file      LED_Program.c
 * @author    Developer : Hozifa Ahmed
 * @author    Reviewer :  Ahmed Ashraf
 * @brief     LED Driver Implementation
 * @version   0.2
 * @date      2025-08-27
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
    switch(ZoneNumber)
    {
        case 1: DIO_Direction_Pin(ZONE1_LED_PORT, ZONE1_LED_PIN, DIO_Output); break;
        case 2: DIO_Direction_Pin(ZONE2_LED_PORT, ZONE2_LED_PIN, DIO_Output); break;
        case 3: DIO_Direction_Pin(ZONE3_LED_PORT, ZONE3_LED_PIN, DIO_Output); break;
        case 4: DIO_Direction_Pin(ZONE4_LED_PORT, ZONE4_LED_PIN, DIO_Output); break;
        default: /* Invalid Zone */ break;
    }
}

void hLed_On(uint8_t ZoneNumber)
{
    switch(ZoneNumber)
    {
        case 1: DIO_Write_Pin(ZONE1_LED_PORT, ZONE1_LED_PIN, DIO_High); break;
        case 2: DIO_Write_Pin(ZONE2_LED_PORT, ZONE2_LED_PIN, DIO_High); break;
        case 3: DIO_Write_Pin(ZONE3_LED_PORT, ZONE3_LED_PIN, DIO_High); break;
        case 4: DIO_Write_Pin(ZONE4_LED_PORT, ZONE4_LED_PIN, DIO_High); break;
        default: /* Invalid Zone */ break;
    }
}

void hLed_Off(uint8_t ZoneNumber)
{
    switch(ZoneNumber)
    {
        case 1: DIO_Write_Pin(ZONE1_LED_PORT, ZONE1_LED_PIN, DIO_Low); break;
        case 2: DIO_Write_Pin(ZONE2_LED_PORT, ZONE2_LED_PIN, DIO_Low); break;
        case 3: DIO_Write_Pin(ZONE3_LED_PORT, ZONE3_LED_PIN, DIO_Low); break;
        case 4: DIO_Write_Pin(ZONE4_LED_PORT, ZONE4_LED_PIN, DIO_Low); break;
        default: /* Invalid Zone */ break;
    }
}


 