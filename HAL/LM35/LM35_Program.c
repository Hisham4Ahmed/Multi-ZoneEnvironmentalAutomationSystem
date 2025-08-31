/**
 * @file     LM35_Program.c
 * @author   Developer : Mohammed Atif
 * @author   Reviewer  : Mohammed Diaa
 * @brief 
 * @version   0.1
 * @date      2025-08-31
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#include "../../Common/Config.h"
#if LM35_Driver

#include "LM35_Interface.h"

void hLm35_Init(uint8_t ZoneNumber) {
    // Initialize ADC :
        // no need for Zone Number !
}

int8_t hLm35_GetTemp(uint8_t ZoneNumber) {
    // Start single mode conversion for :
        // Zone Number
        // Takes Channel -> Zoneconfig.h 0-7
    
    // Convert Digital to Analog volt in mV.

    // Vin = 10mV * T(C)
    // T(C) = Vin / 10mV
    
    // return T(C)
}

#endif /*LM35_Driver*/