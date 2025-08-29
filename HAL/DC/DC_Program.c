/**
 * @file        DC_Program.c
 * @author      Developer: Mohamed Diaa "mohammeddiaato@gmail.com"
 * @author      Reviewer: Mohammed Atef "medoatifatif@gmail.com"
 * @brief      DC_Motor Impelementing the Functions 
 * @version   0.2
 * @date      2025-08-15
 *
 * @copyright Copyright (c) 2025 , Gestell Company
 */
#include "DC_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Private.h"

/**
 * @def ZonesGroups
 * @def ZonesPins 
 * @brief These two global variables are indicating for the DC_Motor what groups or pins are they for each Group
 * @author Mohammed Diaa
 */
static uint8_t ZonesGroups[MaxZones] = Zones_DCGroups;
static uint8_t ZonesPins[MaxZones] = Zones_DCPins;



void hFan_Init(uint8_t ZoneNumber)
{
    if (ZoneNumber <= MaxZones && ZoneNumber > 0)
    {
        DIO_Direction_Pin(ZonesGroups[ZoneNumber - 1], ZonesPins[ZoneNumber - 1], Output);
    }
    else
    {
        //Handle error
    }
}


void hFan_On(uint8_t ZoneNumber)
{

    if (ZoneNumber <= MaxZones && ZoneNumber > 0)
    {
        DIO_Write_Pin(ZonesGroups[ZoneNumber - 1], ZonesPins[ZoneNumber - 1], High);
    }
    else
    {
        //Handle error
    }
}


void hFan_Off(uint8_t ZoneNumber)
{

    if (ZoneNumber <= MaxZones && ZoneNumber > 0)
    {
        DIO_Write_Pin(ZonesGroups[ZoneNumber - 1], ZonesPins[ZoneNumber - 1], Low);
    }
    else
    {
        //Handle error
    }
}