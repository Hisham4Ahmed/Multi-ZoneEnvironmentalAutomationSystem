/**
 * @file     Communication_Program.c
 * @author   Developer: Naira Mohammed (naira.mohammed.76@gmail.com)
 * @author   Developer: Ahmed Ashraf   (ahmedashraf2022222@gmail.com)
 * @brief    Implementation of Communication - Handles Bluetooth command processing and zone data management
 * @version   0.2
 * @date      2025-09-19
 * @copyright Copyright (c) 2025 , Gestell Company 
 */
#include "../../Common/Config.h"
#if Communication_App 

#include "Communication_Interface.h"
#include "../../HAL/LDR/LDR_Interface.h"
#include "Communication_Private.h"
#include "Communication_Config.h"
#include "../../Common/ZoneConfig.h"
#include "../ModeControl/ModeControl_Interface.h"
static uint8_t Communication_Initialized=0;

/**
 * @var ZonesBuffer
 * @brief one Command buffer for all zones
 */
static CommandBuffer_t ZonesBuffer;
/**
 * @fn CMDBufferInit
 * @brief Initialize a command buffer
 * @param Buffer Pointer to the command buffer to initialize
 */
static void CMDBufferInit(CommandBuffer_t *Buffer) 
{
    Buffer->Head = 0;
    Buffer->Tail = 0;
    Buffer->Count = 0;
}

void integer_to_string(uint8_t value , uint8_t* str)
{
    {
    uint8_t temp[3];   
    uint8_t i = 0;
    uint8_t j;

    if (value == 0)
    {
        str[0] = '0';
        str[1] = NullChar;
        return;
    }

    // extract digits (in reverse order)
    while (value > 0)
    {
        temp[i++] = (value % 10) + '0';  // convert digit to char
        value /= 10;
    }

    // reverse digits into final string
    for (j = 0; j < i; j++)
    {
        str[j] = temp[i - j - 1];
    }

    str[i] = NullChar;  // null terminate
}
}

void ClearBuffer(CommandBuffer_t *Buffer)
{
    uint8_t i = 0;
     for (i = 0; i < CMD_BUFFER_SIZE; i++) 
    {
        Buffer->CMDBuffer[i].ZoneId  = 0;
        Buffer->CMDBuffer[i].Actuator = NONE;
        Buffer->CMDBuffer[i].Value    = OFF;
    }
}

uint8_t BufferIsFull(CommandBuffer_t *Buffer)
{
    return (Buffer->Count >= CMD_BUFFER_SIZE);
}

uint8_t BufferIsEmpty(CommandBuffer_t *Buffer)
{
    return (Buffer->Count == 0);
}

void BufferEnqueue(CommandBuffer_t *Buffer, Command_t Command)
{    
    Buffer->CMDBuffer[Buffer->Tail] = Command;
    Buffer->Tail = (Buffer->Tail + 1) % CMD_BUFFER_SIZE;
    Buffer->Count++;
}

uint16_t Convert_Value_to_Integer(const uint8_t* str)
{
    uint16_t Value = 0;
    while (*str>='0' && *str<='9')
    {
        Value = Value * 10 + (*str - '0');
        str++;
    }
    return Value;
}

uint8_t Compare_Strings(const uint8_t* str1, const uint8_t* str2) 
{
    while (*str1==*str2)
    {
        if (*str1 == NullChar)
        {
            return Matches; // Both strings ended together
        }
        else
        {
            str1++;
            str2++;
        }
    }
    
    return NotMatches; // Mismatch found    
}

uint8_t  Communication_ParseCommand(const uint8_t *str, Command_t *Cmd)
{
    uint8_t i = 0;
    uint8_t j = 0;
    uint8_t temp[10];  // buffer to hold actuator substring ("FAN" or "LIGHT")

    // Check start: must be 'Z' and ID between 1..4
    if (str[Zone_Char_Index] != Zone_char || str[ZoneId_Char] < Zones_Start || str[ZoneId_Char] > Zones_End)
    {
        return 0;
    }
    Cmd->ZoneId = str[ZoneId_Char] - '0';  // Convert char → number

    // Find '='
    for (i = Actuator_Start_Char; str[i] != '=' && str[i] != NullChar; i++)
    {
        // just increment i till it finds '=' or end of string
    }
    if (str[i] != '=')
    {
        return 0; // '=' not found
    }
    // Copy substring [2 .. i-1] into temp
    for (j = Actuator_Start_Char; j < i; j++)
    {
        temp[j - Actuator_Start_Char] = str[j];
    }
        temp[i - Actuator_Start_Char]=NullChar;

    // Match actuator 
    if (Compare_Strings(temp, "FAN") == Matches)
    {
     
        Cmd->Actuator = FAN;
    }
    else if (Compare_Strings(temp, "LIGHT") == Matches)
    {
    Cmd->Actuator = LIGHT;
    }
    else
    {
        return 0; // Invalid actuator
    }
    // Parse value (string after '=')
    i++; // move past '='

    if (Cmd->Actuator == FAN)
    {
        Cmd->Value = Convert_Value_to_Integer(&str[i]);
        if (Cmd->Value > 100)
        {
            return 0; // invalid speed
        }
        else 
        {
            return 1; // success
        }
    }
    else if (Cmd->Actuator == LIGHT)
    {
        if (Compare_Strings(&str[i], "ON ") == Matches)
           
        {
             Cmd->Value = ON;
        }
        else if (Compare_Strings(&str[i], "OFF") == Matches)
        {
            Cmd->Value = OFF;
        }
        else
        {
            return 0; // invalid light command
        }
        return 1; // success
    }
}

void Communication_Init(void)
{
   hHC05_Init();
   CMDBufferInit(&ZonesBuffer);
   Communication_Initialized=3;

}

void Communication_Task(void)  
{ if (ModeControl_GetMode() == Manual) 
    {// only in manual mode we receive commands
    uint8_t CommandBuffer[MAXCommandLength]= {0};
    Command_t Command;
    hHC05_ReceiveString(CommandBuffer,MAXCommandLength);
    //parse the received string and check validity
    if(Communication_ParseCommand(CommandBuffer,&Command))
    {
        //store it in zones buffer
        uint8_t Zone=Command.ZoneId;
        if(!BufferIsFull(&ZonesBuffer))
        {
            BufferEnqueue(&ZonesBuffer , Command);
        }
        else
        {
            ClearBuffer(&ZonesBuffer);
            CMDBufferInit(&ZonesBuffer);
            BufferEnqueue(&ZonesBuffer , Command);
        }
    }
    else 
    {
        //Non valid command
    }
}
else 
{
    // in automatic mode we do not receive commands
}
}

Command_t Communication_GetCommand(void)
{
    Command_t Command = {0};
    CommandBuffer_t *Buff = &ZonesBuffer;
    if (!BufferIsEmpty(Buff))
    {
        Command = Buff->CMDBuffer[Buff->Head];
        Buff->Head = (Buff->Head + 1) % CMD_BUFFER_SIZE;
        Buff->Count--;
        return Command;
    }
    else
    {
        Command.ZoneId = 0xFF;    
        Command.Actuator = NONE;  
        Command.Value = 0;        
    }  
    return Command;
}

void Communication_SendZoneData( ZoneData_t data) // zoneid
{
    if (data.ZoneId >= 1 && data.ZoneId <= MaxZones)
    {
        uint8_t Temp_string[4];  // enough for "255"

        // Zone header
        hHC05_SendString("\r\n"); // added for better zone data sending
        hHC05_SendChar('Z');
        hHC05_SendChar(data.ZoneId + '0'); 
        hHC05_SendChar(':');

        // Fan speed
        hHC05_SendString("Fan Speed=");
        integer_to_string(data.FanSpeed, Temp_string);
        hHC05_SendString(Temp_string);

        // Light state
        hHC05_SendString(", Led State="); //LED_STATE
        if (data.LightState)
            hHC05_SendString("ON");
        else
            hHC05_SendString("OFF");

        // Temperature
        hHC05_SendString(", Temp=");
        integer_to_string(data.Temperature, Temp_string);
        hHC05_SendString(Temp_string);

        // LDR Reading
        hHC05_SendString(", Light State=");  // Light State
        if (data.LDRRead==Morning)
        {
            hHC05_SendString("Morning");
        }
        else
        {
            hHC05_SendString("Evening");
        }
        // New line
        hHC05_SendString("\r\n");
    }
}
uint8_t Communication_IsInitialized()
{
    return Communication_Initialized;
    
}


#endif
