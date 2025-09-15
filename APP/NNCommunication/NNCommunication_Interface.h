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


void Communication_Init(void);
void Communication_Task(void);
uint8_t Communication_HasNewCommand(uint8_t ZoneNumber);
Command_t Communication_GetCommand(uint8_t ZoneNumber);
void Communication_SendZoneData(uint8_t ZoneNumber, ZoneData_t data);

#endif /*_NNCOMMUNICATION_INTERFACE_H_*/