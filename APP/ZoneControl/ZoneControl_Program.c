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
    static uint8_t Light_Status = 0;
    static Command_t Received_Command = {0};
    static ZoneData_t Zone_Data = {0};

    for (Loop_index = 1; Loop_index <= MaxZones; Loop_index++) {
        Zone_Data.Light_Status = hLDR_GetLightStatus(Loop_index);
        Zone_Data.Temperature = hLm35_GetTemp(Loop_index);

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
            /** @warning this portion might be broken 
            *   @warning Depends on Communication Task implementation 
            * */
            while (Communication_HasNewCommand(Loop_index)) {
                /**
                 * @warning This loop will break when the expression is no longer true
                 *  considering that Communication_GetCommand(Loop_index) 
                 *  clears someting that makes the expression goes false 
                 * */
                Received_Command = Communication_GetCommand(Loop_index);
                if (Received_Command.Actuator == LED) {
                    if (Received_Command.Value == 0) {
                        hLed_Off(Loop_index);
                    }
                    else if ( Received_Command.Value == 1) {
                        hLed_On(Loop_index);
                    }
                }
                if (Received_Command.Actuator == Fan) {
                    hFan_On(Loop_index, Received_Command.Value);
                }
            }
        }

        // Fan Speed Control
        if (Zone_Data.Temperature < 22) {
            hFan_Off(Loop_index);
            Zone_Data.Fan_Speed = 0;
        }
        else if (Zone_Data.Temperature >= 35) {
            hFan_On(Loop_index, 100);
            Zone_Data.Fan_Speed = 100;
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
            Zone_Data.Fan_Speed = ((Zone_Data.Temperature-22)*100)/13;
            hFan_On(Loop_index, Zone_Data.Fan_Speed);
        }
        
        /**
         * @fn Communication_SendZoneData
         * @warning Light_Status is flipped
         * @warning Depends on Communication Task implementation
         */
        Communication_SendZoneData(Loop_index, Zone_Data);
        
    }
}

#endif  /*ZoneControl_App*/