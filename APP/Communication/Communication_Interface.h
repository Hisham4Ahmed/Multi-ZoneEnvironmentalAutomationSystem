/**
 * @file     Communication_Program.h
 * @author   Developer: Naira Mohammed (naira.mohammed.76@gmail.com)
 * @author   Developer: Ahmed Ashraf    (ahmedashraf2022222@gmail.com)
 * @brief    Function prototypes for Communication application functions.
 * @version   0.1
 * @date      2025-09-14
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


 #ifndef COMMUNICATION_INTERFACE_H
 #define COMMUNICATION_INTERFACE_H
 #include "Communication_Config.h"
 #include "Communication_Private.h"
#include "../../HAL/HC05/HC05_Interface.h"

void Communication_Init(void);
void Communication_Task(void);
uint8_t Communication_HasNewCommand(uint8_t ZoneNumber);
Command_t Communication_GetCommand(uint8_t ZoneNumber);
void Communication_SendZoneData(uint8_t ZoneNumber, ZoneData_t data);



 #endif