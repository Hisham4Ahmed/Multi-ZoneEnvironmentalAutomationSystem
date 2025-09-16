/**
 * @file     Communication_Interface.h
 * @author   Developer: Naira Mohammed (naira.mohammed.76@gmail.com)
 * @author   Developer: Ahmed Ashraf 
 * @brief    Public interface for Communication
 * @version   0.2
 * @date      2025-09-14
 * @copyright Copyright (c) 2025 , Gestell Company 
 */
 
#ifndef _NNCOMMUNICATION_INTERFACE_H_
#define _NNCOMMUNICATION_INTERFACE_H_

#include <stdint.h>
#include "../../Common/ZoneConfig.h"
#include "../../Common/Macro.h"
#include "../../HAL/HC05/HC05_Interface.h"
#include "NNCommunication_Config.h"
#include "NNCommunication_Private.h"


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
 *  - Uses the global TickCounter to periodically trigger sending zone data. *
 * @param void No parameters.
 * @retval void
 * @warning This function should be called periodically in the main loop or a dedicated task scheduler.
 * @warning Before Using this function, ensure that Communication_Init() has been called to initialize the module.
 */
void Communication_Task(void);

/**
 * @fn Communication_HasNewCommand
 * @brief Checks if there is a new command available for a specific zone.
 * @return Returns 1 if a new command is available, 0 otherwise.
 * @param ZoneNumber The zone number to check for new commands (1 to MaxZones).
 */
uint8_t Communication_HasNewCommand(uint8_t ZoneNumber);

/**
 * @fn Communication_GetCommand
 * @brief Retrieves the next available command from a specific zone's buffer.
 *
 * This function checks the command buffer of the given zone. If the buffer
 * is not empty, it dequeues the oldest command (FIFO) and updates the buffer's
 * head and count accordingly.
 * @param ZoneNumber The zone number to retrieve the command from (1 to MaxZones).
 * @return Command_t 
 * @retval 
 * - The next command available in the specified zone's buffer.
 * - Returns an empty command (all fields zeroed) if the buffer is empty 
 *   or if the zone number is invalid.
 */
Command_t Communication_GetCommand(uint8_t ZoneNumber);

/**
 * @fn Communication_SendZoneData
 * @brief Sends the current data of a specified zone via Bluetooth.
 * @param ZoneNumber The zone number to send it's data for (1 to MaxZones).
 * @param data The ZoneData_t structure containing the zone's current data.
 * @return void
 */
void Communication_SendZoneData(uint8_t ZoneNumber, ZoneData_t data);

#endif /*_NNCOMMUNICATION_INTERFACE_H_*/