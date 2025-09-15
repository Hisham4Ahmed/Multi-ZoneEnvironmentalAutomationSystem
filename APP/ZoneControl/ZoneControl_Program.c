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

// built-in Libraries
#include <stdint.h> 
// Config Header files
#include "../../Common/ZoneConfig.h"
// APP Header files
#include "ZoneControl_Interface.h"
#include "../ModeControl/ModeControl_Interface.h"
#include "../Communication/Communication_Interface.h"
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
    static uint8_t Temperature = 0;
    static uint8_t Light_Status = 0;
    static uint8_t Fan_Speed = 0;
    static Command_t Received_Command = {0};

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
            /** @warning this portion is for prototyping and might be broken 
            *   @warning Depends on Communication Task implementation 
            * */
            while (Communication_HasNewCommand(Loop_index)) {
                /**
                 * @warning This loop will break when the expression is no longer true
                 *  considering that Communication_GetCommand(Loop_index) 
                 *  clears someting that makes the expression goes false 
                 * */
                Received_Command = Communication_GetCommand(Loop_index);
                if (Received_Command.Actuator == "LED Macro") {
                    if (Received_Command.Value == 0) {
                        hLed_Off(Loop_index);
                    }
                    else if ( Received_Command.Value == 1) {
                        hLed_On(Loop_index);
                    }
                }
                if (Received_Command.Actuator == "Fan Macro") {
                    hFan_On(Loop_index, Received_Command.Value);
                }
            }
        }

        // Fan Speed Control
        if (Temperature < 22) {
            hFan_Off(Loop_index);
            Fan_Speed = 0;
        }
        else if (Temperature >= 35) {
            hFan_On(Loop_index, 100);
            Fan_Speed = 100;
        }
        else {
            // Linear temp-speed relation
            Fan_Speed = ((Temperature-22)*100)/13;
            hFan_On(Loop_index, Fan_Speed);
        }
        
        /**
         * @fn Communication_SendZoneData
         * @param Loop_index Zone Number
         * @param Temperature 
         * @param Light_Status
         * @param Fan_Speed
         * @brief Send zone data (temp,light status, fan speed)
         * @note LDR reading is the same as light stauts no need for seperate parameters
         * 
         * @warning Not Mentioned in DOD of Communication Task
         * @warning Depends on Communication Task implementation
         */
        Communication_SendZoneData(Loop_index, Temperature, Light_Status, Fan_Speed); // and Actuators Status
        
    }
}

#endif  /*ZoneControl_App*/