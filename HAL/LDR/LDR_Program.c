/**
 * @file     LDR_Program.c
 * @author   <Developer>
 * @author   <Reviewer>
 * @brief 
 * @version   0.1
 * @date      2025-08-15
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */
#include "../../Common/Config.h"
#if LDR_Driver
#include "LDR_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../MCAL/ADC/ADC_Private.h"
#include "LDR_Interface.h"
static uint8_t LDR_ZonesPins[MaxZones] = Zones_LDRPins;

void hLDR_Init(uint8_t ZoneNumber)
{
mADC_Init();
mADC_Enable();
DIO_Direction_Pin(GroupA , LDR_ZonesPins[ZoneNumber-1], DIO_Input );
}

uint8_t hLDR_GetLightStatus(uint8_t ZoneNumber)
{
    uint8_t LDR_Read = 0;

    switch (ZoneNumber)
    {
        case Zone1Num: LDR_Read = (mADC_SingleModeConversion(Zone1_LDRPin)* 5UL )/1023*14 ; break;
        case Zone2Num: LDR_Read = (mADC_SingleModeConversion(Zone2_LDRPin)* 5UL )/1023*14 ; break;
        case Zone3Num: LDR_Read = (mADC_SingleModeConversion(Zone3_LDRPin)* 5UL )/1023*14 ; break;
        case Zone4Num: LDR_Read = (mADC_SingleModeConversion(Zone4_LDRPin)* 5UL )/1023*14 ; break;
        default: return 0;
    }

    // Scale 10-bit ADC (0–1023) to 8-bit (0–255)
   if (LDR_Read>=LDR_Edge_Point)  //-> 56 leads to 100 lux
   {
   return Morning;
   }
   else
   {
    return Evening ;
   }
   
}










#include "LDR_Interface.h"



#endif /*LDR_Driver*/