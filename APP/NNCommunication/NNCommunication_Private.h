/**
 * @file     Communication_Private.h
 * @author   Developer: Naira Mohammed (naira.mohammed.76@gmail.com)
 * @author   Developer: Ahmed Ashraf 
 * @brief    Private definitions and structures for the Communication module
 * @version  0.2
 * @date     2025-09-19
 * @copyright Copyright (c) 2025, Gestell Company 
 */

#ifndef _NNCOMMUNICATION_PRIVATE_H_
#define _NNCOMMUNICATION_PRIVATE_H_

#include "NNCommunication_Config.h"
#include <stdint.h>
#include "../../Common/ZoneConfig.h"

/**
 * @defgroup Flag Values
 * @brief Definitions for command availability status
 * @def New_Command_Available 
 * @brief Indicates a new command is available in the buffer
 * @def No_New_Command
 * @brief Indicates no new command is available in the buffer
 * 
 */
#define New_Command_Available 1
#define No_New_Command        0

/**
 * @defgroup String Comparison Results
 * @def Matches
 * @brief Indicates that two strings match
 * @def NotMatches
 * @brief Indicates that two strings do not match
 */

#define Matches 0
#define NotMatches 1

/**
 * @defgroup Command String Indices and Characters
 * @brief Definitions for parsing command strings
 * @def Zone_Char_Index
 * @brief Refers to the index of Character Z in recieved Command
 * @def   ZoneId_Char
 * @brief Refers to the Index of Zone Id (1~4) in recieved Command
 * @def  Actuator_Start_Char
 * @brief Refers to the index of the first Char of the actuator
 * @def  Zones_Start 
 * @brief refers to the Character of one '1' , which indicates the id of first zone
 * @def Zones_End
 * @brief refers to the Character of Four '4' , which indicates the id of Last zone
 * @def  Zone_Char
 * @brief Refers to the Character of 'Z' which refers to 
 */

#define Zone_Char_Index          0
#define ZoneId_Char              1
#define Actuator_Start_Char      2
#define Zones_Start             '1'
#define Zones_End               '4'
#define Zone_char               'Z'

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
 * @var CMDBuffer
 * @brief  Array of commands
 * 
 * @var Head
 * @brief Index of the oldest command
 * 
 * @var Tail
 * @brief Index where next command will be added
 */
typedef struct {
    Command_t CMDBuffer[CMD_BUFFER_SIZE];  
    uint8_t Head;       
    uint8_t Tail;       
    uint8_t Count;      
} CommandBuffer_t;

/**
 * @fn BufferInit
 * @brief Initialize a command buffer
 * @param Buffer Pointer to the command buffer to initialize
 */
void CMDBufferInit(CommandBuffer_t *Buffer);

/**
 * @fn ClearBuffer
 * @brief Reset a command buffer to its initial state.
 *
 * @details This function clears all stored commands in the buffer by resetting
 * each element to default values:
 * - ZoneId   = 0
 * - Actuator = NONE
 * - Value    = OFF
 *
 * @param Buffer Pointer to the command buffer to reset.
 * @note The buffer size is defined by CMD_BUFFER_SIZE.
 */
void ClearBuffer(CommandBuffer_t *Buffer);

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
 * @fn Convert_Value_to_Integer
 * @brief Convert a numeric string into an integer value.
 *
 * @details This function parses a null-terminated string containing digits ('0'–'9')
 * and converts it into an unsigned 16-bit integer. Conversion stops when 
 * a non-digit character is encountered.
 *
 * @param str Pointer to the null-terminated string to convert.
 * @return uint16_t value
 * @retval The integer value converted from the string.
 *
 * @note Example: "123" -> 123
 */
uint16_t Convert_Value_to_Integer(const uint8_t* str);


/**
 * @fn Compare_Strings
 * @brief Compare two strings.
 *
 * @details This function compares two null-terminated strings character by character 
 * based on their ASCII values.
 *
 * @param str1 Pointer to the first string.
 * @param str2 Pointer to the second string.
 * @return uint8_t comparison result
 * @retval Matches if strings are identical.
 * @retval NotMatches if strings differ.
 */
uint8_t Compare_Strings(const uint8_t* str1, const uint8_t* str2);

/**
 * @fn Communication_ParseCommand
 * @brief Parse a command string into a Command_t structure.
 * @details This function validates and parses a command string received over communication, 
 * it extracts zone, actuator, and value information.
 * 
 * The expected format is:
 *   - For FAN:    "Z<ZoneId>FAN=<Speed>"
 *       - Example: "Z1FAN=75" (Zone 1, FAN speed 75%)
 *   - For LIGHT:  "Z<ZoneId>LIGHT=<ON|OFF>"
 *       - Example: "Z2LIGHT=ON" (Zone 2, LIGHT turned ON)
 * @param str Pointer to the null-terminated command string to parse.
 * @param Cmd Pointer to the Command_t structured to store the parsed command.
 * @return uint8_t 
 * @retval if success return (1), else return (0)
 */
uint8_t Communication_ParseCommand(const uint8_t *str, Command_t *Cmd);

/**
 * @fn integer_to_string
 * @brief Convert an integer value (0-255) to a null-terminated string.
 * @details this function is used to convert integer values to strings for sending via Bluetooth.
 * @param value The integer value to convert (0-255).
 * @param str Pointer to a character array where the resulting string will be stored.
 */
void integer_to_string(uint8_t value , uint8_t* str);

#endif /*  _NNCOMMUNICATION_PRIVATE_H_  */