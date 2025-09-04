/**
 * @file     LDR_Program.c
 * @author   Developer : Ahmed Ashraf
 * @author   Reviewer  : Mohamed Atif
 * @brief  This driver is to initialize and operate LDR
 * @version   0.1
 * @date      2025-08-31
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */
#include "../../Common/Config.h"
#if LDR_Driver
#include "LDR_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../MCAL/ADC/ADC_Private.h"

static uint8_t ADC_initializied = 0;

static uint8_t LDR_ZonesPins[MaxZones] = Zones_LDRPins;

void hLDR_Init(uint8_t ZoneNumber)  
{
  if (ADC_initializied==0)
  {
    mADC_Init();
    ADC_initializied=1 ;

  }
  else
  {
     // do nothing
  }
   if (ZoneNumber <= MaxZones && ZoneNumber > 0)
   {
    DIO_Direction_Pin(GroupA , LDR_ZonesPins[ZoneNumber-1], DIO_Input );
   }
   else
   {
    // do nothing
   }
}

uint8_t hLDR_GetLightStatus(uint8_t ZoneNumber)
{
    uint16_t LDR_Read = 0;

    if (ZoneNumber >= 1 && ZoneNumber <= MaxZones)
    {
      LDR_Read = (mADC_SingleModeConversion(LDR_ZonesPins[ZoneNumber-1] )*5000UL /1023) ;
    }
    else
    {
        // Do Nothing
    }
   #if LDR_Connection_Type == With_Vcc
    
   if (LDR_Read<=LDR_With_Vcc_Edge_point)  // This Value Leads To 10 Lux in our case
   {
   return Evening;
   }
   else
   {
    return Morning ;
   }
   
    #elif  LDR_Connection_Type == With_GND
    {
     if (LDR_Read<=LDR_With_GND_Edge_point)  
       {
       return Morning;
       }
       else
       {
        return Evening ;
       }
     }
#endif
}










#include "LDR_Interface.h"



#endif /*LDR_Driver*/