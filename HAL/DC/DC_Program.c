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

#include "../../Common/Config.h"
#if DC_Driver

#include "DC_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Private.h"
#include "../../MCAL/Timer0/T0_Interface.h"
#include "../../MCAL/Timer1/T1_Interface.h"
#include "../../MCAL/Timer2/T2_Interface.h"
/**
 * @def ZonesGroups
 * @def ZonesPins 
 * @brief These two global variables are indicating for the DC_Motor what groups or pins are they for each Group
 * @author Mohammed Diaa
 */
static uint8_t ZonesGroups[MaxZones] = Zones_DCGroups;
static uint8_t ZonesPins[MaxZones] = Zones_DCPins;
static uint8_t ZonesTimers[MaxZones] = Zones_Timers;



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
void hFan_SpeedControl(uint8_t ZoneNumber,uint16_t RPMSpeed)
{
    uint16_t Percentage=0;
    Percentage= RPMSpeed*100/Fan_MAXSpeed;
    if(Percentage>100) Percentage=100;
    if (ZoneNumber <= MaxZones && ZoneNumber > 0)
    {
       switch (ZoneNumber)
       {
       case Zone1Num:
        mTimer0_ChangeDutyCycle(Percentage,OutPutCompareMatch);
        break;
       case Zone2Num:
        mTimer1_ChangeDutyCycle(Percentage,OC1A_Channel);        
        break;
        case Zone3Num:
        
        mTimer1_ChangeDutyCycle(Percentage,OC1B_Channel);        
        break;
        case Zone4Num:

        mTimer2_ChangeDutyCycle(Percentage);        
        break;
       
       default:
       //Error Handle
       
        break;
       }
    }
    else
    {
        //Handle error
    }
}
#endif /*DC_Driver*/