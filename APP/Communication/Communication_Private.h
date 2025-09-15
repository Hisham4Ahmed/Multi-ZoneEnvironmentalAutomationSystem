/**
 * @file     Communication_Program.h
 * @author   Developer: Naira Mohammed (naira.mohammed.76@gmail.com)
 * @author   Developer: Ahmed Ashraf    (ahmedashraf2022222@gmail.com)
 * @brief    Contains private definitions and configurations for the Communication application.
 * @version   0.1
 * @date      2025-09-14
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef COMMUNICATION_PRIVATE_H
#define COMMUNICATION_PRIVATE_H
#include <stdint.h>
#include "../../Common/Macro.h"
#include "../../Common/ZoneConfig.h"
/**
 * @var ZonesBuffer
 * @brief Command buffers for each zone 
 */
static CommandBuffer_t ZonesBuffer[MaxZones]; // MaxZones Expands to 4 , we start from 0 index

/**
 * @fn BufferInit
 * @brief Initialize a command buffer
 * @param Buffer Pointer to the command buffer to initialize
 */
void BufferInit(CommandBuffer_t *Buffer);

/**
 * @fn BufferIsFull
 * @brief Check if a command buffer is full
 * @param Buffer Pointer to the command buffer to check
 * @return uint8_t, this function return vlaue that indicate buffer state
 * @retval 1 if buffer is full, 0 otherwise
 */
uint8_t BufferIsFull(CommandBuffer_t *Buffer);

/**
 * @fn BufferIsEmpty
 * @brief Check if a command buffer is empty
 * @param Buffer Pointer to the command buffer to check
 * @return uint8_t, this function return vlaue that indicate buffer state
 * @retval 1 if buffer is empty, 0 otherwise
 */
uint8_t BufferIsEmpty(CommandBuffer_t *Buffer);

/**
 * @fn BufferEnqueue
 * @brief Add a command to the buffer (enqueue)
 * @param Buff Pointer to the command buffer
 * @param Command The command to add to the buffer
 */
void BufferEnqueue(CommandBuffer_t *Buff, Command_t Command);

/**
 * @fn BufferDequeue
 * @brief Remove a command from the buffer (dequeue)
 * @param Buff Pointer to the command buffer
 * @retval Structure (Command_t)
 * @return The command removed from the buffer
 */
Command_t BufferDequeue(CommandBuffer_t *Buff);

/**
 * @enum Actuator_t
 * @brief Enumeration of supported actuator types
 * 
 * @var NONE
 * @brief No actuator specified
 * 
 * @var FAN
 * @brief Fan Actuator
 * 
 * @var LIGHT
 * @brief Light Actuator
 */
typedef enum {
    NONE,  
    FAN,   
    LIGHT, 
} Actuator_t;

/**
 * @enum Value_t
 * @brief Enumeration of possible actuator values
 * 
 * @var OFF
 * @brief Actuator off state
 * 
 * @var ON 
 * @brief Actuator on state
 */
typedef enum {
    OFF,    
    ON      
} Value_t;

/**
 * @struct Command_t
 * @brief Structure representing a command received from communication interface
 * 
 * @var ZoneId
 * @brief Zone identifier 
 * 
 * @var Actuator
 * @brief Type of actuator to control
 * 
 * @var Value
 * @brief Value to set for the actuator
 */
typedef struct {
    uint8_t ZoneId;     
    Actuator_t Actuator;
    Value_t Value;      
} Command_t;

/**
 * @struct CommandBuffer_t
 * @brief Circular buffer structure for storing commands
 * 
 * @var Buffer
 * @brief  Array of commands
 * 
 * @var Head
 * @brief Index of the oldest command
 * 
 * @var Tail
 * @brief Index where next command will be added
 */
typedef struct {
    Command_t Buffer[CMD_BUFFER_SIZE];  
    uint8_t Head;       
    uint8_t Tail;       
    uint8_t Count;      
} CommandBuffer_t;

/**
 * @struct ZoneData_t
 * @brief Structure representing zone sensor data and actuator states to be sent
 * 
 * @var FanSpeed
 * @brief  Current fan speed (0-100%)
 * 
 * @var LightState
 * @brief Current light state (ON/OFF)
 * 
 * @var Temperature
 * @brief Current temperature reading
 * 
 */
typedef struct {
    uint8_t FanSpeed;      
    uint8_t LightState;    
    uint8_t Temperature;      
} ZoneData_t;
uint16_t Compare_Strings(const char* str1, const char* str2);
uint16_t Compare_Strings(const char* str1, const char* str2)
{
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

// void ClearBuffer(uint8_t *buf, uint16_t len)
// {
//     for (uint16_t i = 0; i < len; i++)
//         buf[i] = NullChar;
// }

// make the parsing Function 

uint16_t Convert_Value_to_Integer(const char* str)
{
    uint16_t Value = 0;
    while (*str>='0' && *str<='9')
    {
        Value = Value * 10 + (*str - '0');
        str++;
    }
    return Value;

   
}

uint8_t Communication_ParseCommand(const uint8_t *str, Command_t *Cmd)
{
    uint8_t i = 0;
    uint8_t j = 0;
    uint8_t temp[10];  // buffer to hold actuator substring ("FAN" or "LIGHT")

    // Check start: must be 'Z' and ID between 1..4
    if (str[0] != 'Z' || str[1] < '1' || str[1] > '4')
        return 0;

    Cmd->ZoneId = str[1] - '0';  // Convert char → number

    // Find '='
    for (i = 2; str[i] != '=' && str[i] != NullChar; i++);
    if (str[i] != '=')
        return 0; // '=' not found

    // Copy substring [2 .. i-1] into temp
    for (j = 2; j < i; j++)
        temp[j - 2] = str[j];
    temp[j - 2] = NullChar;  // null-terminate

    // Match actuator
    if (Compare_Strings(temp, "FAN") == 0)
        Cmd->Actuator = FAN;
    else if (Compare_Strings(temp, "LIGHT") == 0)
        Cmd->Actuator = LIGHT;
    else
        return 0; // Invalid actuator

    // Parse value (string after '=')
    i++; // move past '='

    if (Cmd->Actuator == FAN)
    {
        Cmd->Value = Convert_Value_to_Integer(&str[i]);
        if (Cmd->Value > 100)
            return 0; // invalid speed
        return 1; // success
    }
    else if (Cmd->Actuator == LIGHT)
    {
        if (Compare_Strings(&str[i], "ON") == 0)
            Cmd->Value = ON;
        else if (Compare_Strings(&str[i], "OFF") == 0)
            Cmd->Value = OFF;
        else
            return 0; // invalid light command
        return 1; // success
    }

    return 0; // fallback (shouldn’t reach here)
}


#endif