/**
 * @file     Communication_Interface.h
 * @author   Developer: Naira Mohammed (naira.mohammed.76@gmail.com)
 * @author   Developer: Ahmed Ashraf 
 * @brief    Public interface for Communication
 * @version   0.2
 * @date      2025-09-14
 * @copyright Copyright (c) 2025 , Gestell Company 
 */
 
#ifndef _COMMUNICATION_INTERFACE_H_
#define _COMMUNICATION_INTERFACE_H_

#include <stdint.h>
#include "../../Common/ZoneConfig.h"
#include "../../Common/Macro.h"
#include "../../HAL/HC05/HC05_Interface.h"
#include "Communication_Config.h"
#include "Communication_Private.h"


/**
 * @fn Communication_Init
 * @brief Initializes the communication module and command buffers.
 * @return void
 */

void Communication_Init(void);

/**
 * @fn Communication_Task
 * @brief Executes the main communication task for handling Bluetooth commands and zone data.
 *
 * This function performs the following:
 *  - Receives a string from the HC05 Bluetooth module via hHC05_ReceiveString.
 *  - Parses the received string into a structured command using Communication_ParseCommand.
 *  - Check buffer mode, then Stores valid commands into the corresponding zone buffer.
 * @param void No parameters.
 * @retval void 
 * @warning Before Using this function, ensure that Communication_Init() has been called to initialize the module.
 */
void Communication_Task(void);

/**
 * @fn Communication_GetCommand
 * @brief Retrieves the next available command from the global command buffer.
 *
 * This function checks the global command buffer 'ZonesBuffer'. If the buffer 
 * is not empty, it dequeues (FIFO) the oldest command, updates the buffer's 
 * head and count, and returns the command. 
 *
 * If the buffer is empty, it returns a "dummy" command with:
 * - ZoneId = 0xFF  
 * - Actuator = NONE  
 * - Value = 0
 *
 * @note This implementation assumes a single shared buffer for all zones.
 *
 * @return Command_t 
 * @retval  - Valid command if available in the buffer.
 *          - Dummy command if the buffer is empty.
 */
Command_t Communication_GetCommand(void);

/**
 * @fn Communication_SendZoneData
 * @brief Sends zone data to the HC05 Bluetooth module.
 *
 * This function formats and transmits the data of a specific zone 
 * (identified by its ZoneId) over the HC05 Bluetooth module. 
 * It sends zone information.
 * 
 * The data is sent in the format:
 *   Z<ZoneId>:Fan Speed=<value>, Light=<ON/OFF>, Temp=<value>, LDR=<Morning/Evening>
 *
 * @param data ZoneData_t structure containing the following:
 *  - ZoneId      : Zone identifier (1 .. MaxZones)
 *  - FanSpeed    : Fan speed value (0–255)
 *  - LightState  : Light state (ON/OFF)
 *  - Temperature : Temperature value
 *  - LDRRead     : LDR status (Morning/Evening)
 *
 * @return void
 */
void Communication_SendZoneData(ZoneData_t data);

#endif /*_COMMUNICATION_INTERFACE_H_*/