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
#include "ZoneControl_Private.h"
#include "../ModeControl/ModeControl_Interface.h"
#include "../Communication/Communication_Interface.h"
// Sensors APIs
#include "../../HAL/LDR/LDR_Interface.h"
#include "../../HAL/LM35/LM35_Interface.h"
// Actuators APIs
#include "../../HAL/Relay/Relay_Interface.h"
#include "../../HAL/LED/LED_Interface.h"
#include "../../HAL/DC/DC_Interface.h"


static uint8_t ZoneControl_Initialized=0;


/*for loop counter*/
static uint8_t Zone_Index = MinZones;

/*Store Zone Data*/
static ZoneData_t Zone_Data = {0};

/*Store Received Command*/
static Command_t Received_Command = {0};

void ZoneControl_Init(void) {
    for (Zone_Index = MinZones; Zone_Index <= MaxZones; Zone_Index++) {
        hLm35_Init(Zone_Index);
        hLDR_Init(Zone_Index);
        hRelay_Init(Zone_Index);
        hLed_Init(Zone_Index);
        hFan_Init(Zone_Index);
    }
    ZoneControl_Initialized=2;
}

static void AutoExecutionRoutine(void) {
    // Light Control
    if (Zone_Data.LDRRead == Morning) {
        hLed_Off(Zone_Index);  
        Zone_Data.LightState = OFF;      
    }
    else if (Zone_Data.LDRRead == Evening) {
        hLed_On(Zone_Index);        
        Zone_Data.LightState = ON;      
    }
    
    // Fan Speed Control
    if (Zone_Data.Temperature < Min_Temp_Threshold) {
        Zone_Data.FanSpeed = Min_Fan_Speed;
        hFan_Off(Zone_Index);
    }
    else if (Zone_Data.Temperature >= Max_Temp_Threshold) {
        Zone_Data.FanSpeed = Max_Fan_Speed;
        hFan_On(Zone_Index, Zone_Data.FanSpeed);
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
        Zone_Data.FanSpeed = ((Zone_Data.Temperature-Min_Temp_Threshold)*Full_Scale)
                                /Fan_Speed_Temp_Range;
        hFan_On(Zone_Index, Zone_Data.FanSpeed);     
    }
}

static void ManualExecutionRoutine(void) {
    Received_Command = Communication_GetCommand();
    if (Received_Command.ZoneId != No_Commands) {
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
    for (Zone_Index = MinZones; Zone_Index <= MaxZones; Zone_Index++) {
        Zone_Data.LDRRead = hLDR_GetLightStatus(Zone_Index);
        Zone_Data.Temperature = hLm35_GetTemp(Zone_Index);
        Zone_Data.ZoneId = Zone_Index;
        if (ModeControl_GetMode() == Automatic) {
            AutoExecutionRoutine();
        }
        else if (ModeControl_GetMode() == Manual) {
            ManualExecutionRoutine();
        }
        Communication_SendZoneData(Zone_Data);
    }
}

uint8_t ZoneControl_IsInitialized()
{
    return ZoneControl_Initialized; 
}

#endif  /*ZoneControl_App*/