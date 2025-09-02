/**
 * @file     LM35_Program.c
 * @author   Developer : Mohammed Atif  "medoatifatif@gmail.com:
 * @author   Reviewer  : Mohammed Diaa  "mohammeddiaato@gmail.com"
 * @brief    Driver functions for LM35 temperature sensor using ADC.
 * @version   0.1
 * @date      2025-08-31
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#include "../../Common/Config.h"
#if LM35_Driver

#include "LM35_Interface.h"

/** LM35 pin mapping for each zone. */
static LM35_Zone[MaxZones] = Zones_ADC_Channel;

void hLm35_Init(uint8_t ZoneNumber) {
    // Initialize ADC :
    DIO_Direction_Pin(GroupA, LM35_Zone[ZoneNumber-1], DIO_Input);
    mADC_Init();
}

/** @warning Still Doesn't support minus Temps */
int8_t hLm35_GetTemp(uint8_t ZoneNumber) {
    static uint16_t DigitalVoltage = 0;
    static uint16_t LastDigitalVoltage = 0;
    static uint16_t AnalogVoltage_mV = 0;
    static int8_t Temp_C = 0;
    
    // Start single conversion :
    DigitalVoltage = mADC_SingleModeConversion(LM35_Zone[ZoneNumber - 1]);
    
    // Convert Digital to Analog volt in mV.    
    if ( LastDigitalVoltage != DigitalVoltage) {
        #if LM35_Mode == Basic
            /**
             *  @var Temp_C
             *  @brief Converts Digital Voltage to Temperature(C) in one step
             * where
             *  Analog Volt in mV = ((uint32_t)DigitalVolt*5000UL)/1024
             *  Temp(C) = Analog Volt / 10mV
             */
            Temp_C = ((uint32_t)DigitalVoltage*5000UL)/10240;
        #elif LM35_Mode == Full_Range
            // Will be supported in future.
        #endif

        LastDigitalVoltage = DigitalVoltage;
    }
    
    // return T(C)
    return Temp_C;
}

#endif /*LM35_Driver*/