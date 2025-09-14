/**
 * @file     ZoneControl_Program.c
 * @author   Developer: Mohammed Atif   "medoatifatif@gmail.com"
 * @author   Reviewer:  Hesham Ahmed    (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version   0.1
 * @date      2025-09-14
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */
#include "../../Common/Config.h"
#if ZoneControl_App

#include <stdint.h> 

#include "ZoneControl_Interface.h"
#include "../ModeControl/ModeControl_Interface.h"
#include "../../Common/ZoneConfig.h"
// Sensors
#include "../../HAL/LDR/LDR_Interface.h"
#include "../../HAL/LM35/LM35_Interface.h"
// Actuators
#include "../../HAL/Relay/Relay_Interface.h"
#include "../../HAL/LED/LED_Interface.h"
#include "../../HAL/DC/DC_Interface.h"

static uint8_t Loop_index = 1;

void ZoneControl_Init(void) {
    for (Loop_index = 1; Loop_index <= MaxZones; Loop_index++) {
        hLm35_Init(Loop_index);
        hLDR_Init(Loop_index);
        hRelay_Init(Loop_index);
        hLed_Init(Loop_index);
        hFan_Init(Loop_index);
    }
}

void ZoneControl_Task(void) {
    // Read and reutrn sensors values
    uint8_t Temperature = 0;
    uint8_t Light_Status = 0;

    for (Loop_index = 1; Loop_index <= MaxZones; Loop_index++) {
        Light_Status = hLDR_GetLightStatus(Loop_index);
        Temperature = hLm35_GetTemp(Loop_index);

        // Light Control
        if (ModeControl_GetMode() == Automatic) {
            if (Light_Status == Morning) {
                hRelay_Off(Loop_index);
                hLed_Off(Loop_index);        
            }
            else if (Light_Status == Evening) {
                hRelay_On(Loop_index);
                hLed_On(Loop_index);        
            }
        }
        else if (ModeControl_GetMode() == Manual) {
            /** @todo Check Commands from Communication_Task */
        }

        // Fan Speed Control
        if (Temperature < 22) {
            hFan_Off(Loop_index);
        }
        else if (Temperature >= 35) {
            hFan_On(Loop_index, 100);
        }
        else {
            // Linear temp-speed relation
            hFan_On(Loop_index, ((Temperature-22)*100)/13);
        }
        
        /** @todo Send sensor Readings to Mobile App */
            // Via Communication_SendZoneData();
    }
}

#endif