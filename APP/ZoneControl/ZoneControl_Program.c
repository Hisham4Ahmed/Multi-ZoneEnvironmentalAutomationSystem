/**
 * @file     ZoneControl_Program.c
 * @author   Developer: Mohammed Atif   "medoatifatif@gmail.com"
 * @author   Reviewer:  Hesham Ahmed    (Hisham4Ahmed@gmail.com)
 * @brief    Implements zone initialization and periodic control tasks.
 * @version  0.1
 * @date     2025-09-14
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */
#include "../../Common/Config.h"
#if ZoneControl_App

// built-in Libraries
#include <stdint.h> 
// Config Header files
#include "../../Common/ZoneConfig.h"
// APP Header files
#include "ZoneControl_Interface.h"
#include "../ModeControl/ModeControl_Interface.h"
#include "../Communication/Communication_Interface.h"
// Sensors APIs
#include "../../HAL/LDR/LDR_Interface.h"
#include "../../HAL/LM35/LM35_Interface.h"
// Actuators APIs
#include "../../HAL/Relay/Relay_Interface.h"
#include "../../HAL/LED/LED_Interface.h"
#include "../../HAL/DC/DC_Interface.h"

/*for loop counter*/
static uint8_t Loop_index = 1;

/*Store Zone Data*/
static ZoneData_t Zone_Data = {0};

/*Store Received Command*/
static Command_t Received_Command = {0};

void ZoneControl_Init(void) {
    for (Loop_index = 1; Loop_index <= MaxZones; Loop_index++) {
        hLm35_Init(Loop_index);
        hLDR_Init(Loop_index);
        hRelay_Init(Loop_index);
        hLed_Init(Loop_index);
        hFan_Init(Loop_index);
    }
}

static void AutoExecutionRoutine(void) {
    // Light Control
    if (Zone_Data.LDRRead == Morning) {
        hLed_Off(Loop_index);  
        Zone_Data.LightState = OFF;      
    }
    else if (Zone_Data.LDRRead == Evening) {
        hLed_On(Loop_index);        
        Zone_Data.LightState = ON;      
    }
    
    // Fan Speed Control
    if (Zone_Data.Temperature < 22) {
        Zone_Data.FanSpeed = 0;
        hFan_Off(Loop_index);
    }
    else if (Zone_Data.Temperature >= 35) {
        Zone_Data.FanSpeed = 100;
        hFan_On(Loop_index, Zone_Data.FanSpeed);
    }
    else {
        /**
         * Linear Temp-Speed relation
         * Temp(°C) | Fan Speed
         *   22     |     0%    MIN
         *   25     |    23%     |
         *   30     |    61%     v
         *   35     |   100%    MAX
         */
        Zone_Data.FanSpeed = ((Zone_Data.Temperature-22)*100)/13;
        hFan_On(Loop_index, Zone_Data.FanSpeed);     
    }
    Communication_SendZoneData(Zone_Data);
}

static void ManualExecutionRoutine(void) {
    Received_Command = Communication_GetCommand();
    if (Received_Command.ZoneId != 0xFF) {
        // Light control
        if (Received_Command.Actuator == LIGHT) {
            if (Received_Command.Value == OFF) {
                hLed_Off(Received_Command.ZoneId);
            }
            else if (Received_Command.Value == ON) {
                hLed_On(Received_Command.ZoneId);
            }
            Zone_Data.LightState = Received_Command.Value;
        }
        // Fan control
        else if (Received_Command.Actuator == FAN) {
            Zone_Data.FanSpeed = Received_Command.Value;
            hFan_On(Received_Command.ZoneId, Zone_Data.FanSpeed);
        }
    }
    else {
        // No Commands
    }
}

void ZoneControl_Task(void) {
    for (Loop_index = 1; Loop_index <= MaxZones; Loop_index++) {
        Zone_Data.LDRRead = hLDR_GetLightStatus(Loop_index);
        Zone_Data.Temperature = hLm35_GetTemp(Loop_index);
        Zone_Data.ZoneId = Loop_index;
        if (ModeControl_GetMode() == Automatic) {
            AutoExecutionRoutine();
        }
        else if (ModeControl_GetMode() == Manual) {
            ManualExecutionRoutine();
        }
        Communication_SendZoneData(Zone_Data);
    }
}

#endif  /*ZoneControl_App*/