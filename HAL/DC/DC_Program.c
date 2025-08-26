/**
 * @file        DC_Program.c
 * @author      Developer: Mohamed Diaa "mohammeddiaato@gmail.com"
 * @author      Reviewer:
 * @brief
 * @version   0.2
 * @date      2025-08-15
 *
 * @copyright Copyright (c) 2025 , Gestell Company
 */
#include "DC_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Private.h"

void hFan_Init(uint8_t ZoneNumber)
{
    if (ZoneNumber == Zone1Num)
    {
        DIO_Direction_Pin(Zone1_DCGroup, Zone1_DCpin, Output);
            #if Startin_State == ON
            hFan_On(Zone1Num);
            #elif Startin_State == OFF
            hFan_Off(Zone1Num);
            #endif
    }
    else if (ZoneNumber == Zone2Num)
    {
        DIO_Direction_Pin(Zone2_DCGroup, Zone2_DCpin, Output);
            #if Startin_State == ON
            hFan_On(Zone2Num);
            #elif Startin_State == OFF
            hFan_Off(Zone2Num);
            #endif
    }
    else if (ZoneNumber == Zone3Num)
    {
        DIO_Direction_Pin(Zone3_DCGroup, Zone3_DCpin, Output);

        #if Startin_State == ON
        hFan_On(Zone3Num);
        #elif Startin_State == OFF
        hFan_Off(Zone3Num);
        #endif
    }
    else if (ZoneNumber == Zone4Num)
    {
        DIO_Direction_Pin(Zone4_DCGroup, Zone4_DCpin, Output);

        #if Startin_State == ON
        hFan_On(Zone4Num);
        #elif Startin_State == OFF
        hFan_Off(Zone4Num);
        #endif
    }
    else
    {
        return;
    }
}
void hFan_On(uint8_t ZoneNumber)
{
  
    if (ZoneNumber == Zone1Num)
    {
        DIO_Write_Pin(Zone1_DCGroup, Zone1_DCpin, High);
    }
    else if (ZoneNumber == Zone2Num)
    {
        DIO_Write_Pin(Zone2_DCGroup, Zone2_DCpin, High);
    
    }
    else if (ZoneNumber == Zone3Num)
    {
        DIO_Write_Pin(Zone3_DCGroup, Zone3_DCpin, High);
    
    }
    else if (ZoneNumber == Zone4Num)
    {
        DIO_Write_Pin(Zone4_DCGroup, Zone4_DCpin, High);
    
    }
    else
    {
        return ;
    }
}
void hFan_Off(uint8_t ZoneNumber)
{

  
    if (ZoneNumber == Zone1Num)
    {
        DIO_Write_Pin(Zone1_DCGroup, Zone1_DCpin, Low);
    }
    else if (ZoneNumber == Zone2Num)
    {
        DIO_Write_Pin(Zone2_DCGroup, Zone2_DCpin, Low);
    
    }
    else if (ZoneNumber == Zone3Num)
    {
        DIO_Write_Pin(Zone3_DCGroup, Zone3_DCpin, Low);
    
    }
    else if (ZoneNumber == Zone4Num)
    {
        DIO_Write_Pin(Zone4_DCGroup, Zone4_DCpin, Low);
    
    }
    else
    {
        return ;
    }
}