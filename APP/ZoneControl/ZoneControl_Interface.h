/**
 * @file     ZoneControl_Interface.h
 * @author   Developer: Mohammed Atif   "medoatifatif@gmail.com"
 * @author   Reviewer:  Hesham Ahmed    (Hisham4Ahmed@gmail.com)
 * @brief    Public Zone Control APIs
 * @version  0.1
 * @date     2025-09-14
 *
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _ZONECONTROL_INTERFACE_H_
#define _ZONECONTROL_INTERFACE_H_

// ZoneControl is the only module allowed to control actuators (Relay, LED, Fan). so no includes

/**
 * @fn      ZoneControl_Init
 * @brief   Initializes all zones in the system. 
 * @details This function iterates through all configured zones (from 1 to MaxZones) 
 *             and initializes the required hardware modules for each zone, including:
 *             - Temperature sensor (LM35)
 *             - Light sensor (LDR)
 *             - Relay
 *             - LED 
 *             - Fan
 *             This ensures that all components in every zone are properly set up 
 *             before operation.
 * 
 * @note    Must be called once at system startup before using any zone-related 
 *             operations.
 */
void ZoneControl_Init(void);

static void AutoExecutionRoutine();
static void ManualExecutionRoutine();

/**
 * @fn         ZoneControl_Task
 * @brief      Executes periodic zone control operations.
 * @details    This function handles the main control logic for each zone. It performs:
 *             - Reading sensor data: Temperature (LM35) and Light status (LDR).
 *             - Controlling actuators based on mode:
 *                - **Automatic Mode**:
 *                   - Controls lighting (Relay + LED) depending on light conditions (Morning/Evening).
 *                   - Adjusts fan speed proportionally to temperature.
 *                - **Manual Mode**:
 *                   - Processes incoming communication commands for actuators (LED, Fan).
 *             - Sends updated zone data (sensors + actuator status) via Communication module.
 * 
 * @note       This function shall be called periodically in the superloop
 *             to ensure continuous monitoring and control of all zones.
 *
 * @note       Adding new zones only requires updating **ZoneConfig.h**. No logic 
 *             changes are needed in ZoneControl.
 * 
 * @warning    ZoneControl_Init() must be called before using this function to ensure
 *             that all sensors and actuators are properly initialized.
 */
void ZoneControl_Task(void);

#endif /* _ZONECONTROL_INTERFACE_H_ */