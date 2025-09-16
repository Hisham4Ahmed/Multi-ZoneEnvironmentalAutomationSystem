/**
 * @file     Communication_Program.c
 * @author   Developer: Naira Mohammed (naira.mohammed.76@gmail.com)
 * @author   Developer: Ahmed Ashraf 
 * @brief    Implementation of Communication - Handles Bluetooth command processing and zone data management
 * @version   0.2
 * @date      2025-09-14
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#include "NNCommunication_Interface.h"
/**
 * @var ZonesBuffer
 * @brief Command buffers for each zone 
 */
static Command_t ZonesBuffer[MaxZones];
/**
 * @var TickCounter
 * @brief Global tick counter used for periodic operations in Communication_Task().
 *
 * This counter is incremented each time Communication_Task() is called.
 * Once it reaches a defined threshold, it is reset and triggers sending 
 * periodic zone data.
 */
unsigned long TickCounter=0;

void BufferInit(CommandBuffer_t *Buffer)
{
    Buffer->Head = 0;
    Buffer->Tail = 0;
    Buffer->Count = 0;
}

void integer_to_string(uint8_t value , char* str)
{
    {
    uint8_t temp[3];    // max "255"
    uint8_t i = 0;
    uint8_t j;

    if (value == 0)
    {
        str[0] = '0';
        str[1] = '\0';
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

    str[i] = '\0';  // null terminate
}
}

void ClearBuffer(CommandBuffer_t *Buffer)
{
     for (uint16_t i = 0; i < CMD_BUFFER_SIZE; i++)
    {
        Buffer->Buffer[i].ZoneId  = 0;
        Buffer->Buffer[i].Actuator = NONE;
        Buffer->Buffer[i].Value    = OFF;
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

void BufferEnqueue(CommandBuffer_t *Buff, Command_t Command)
{
    if (!BufferIsFull(Buff))
    {
        Buff->Buffer[Buff->Tail] = Command;
        Buff->Tail = (Buff->Tail + 1) % CMD_BUFFER_SIZE;
        Buff->Count++;
    }
}

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

uint16_t Compare_Strings(const char* str1, const char* str2)
{
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
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
        {
            return 0; // invalid speed
        }
            return 1; // success
    }
    else if (Cmd->Actuator == LIGHT)
    {
        if (Compare_Strings(&str[i], "ON") == 0)
           
        {
             Cmd->Value = ON;
        }
        else if (Compare_Strings(&str[i], "OFF") == 0)
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

    for (uint8_t i = 0; i < MaxZones; i++)
    {
        BufferInit(&ZonesBuffer[i]);
    }
}

void Communication_Task(void)  
{
    uint8_t RxBuffer[RX_MAX_STRING]= {0};
    Command_t Command;
    hHC05_ReceiveString(RxBuffer,RX_MAX_STRING);
    //parse the received string and check validity
    if(Communication_ParseCommand(RxBuffer,&Command))
    {
        //store it in it's zones buffer
        uint8_t Zone=Command.ZoneId;
        if(Zone>=1 && Zone<=MaxZones) // -> Zone validation was done in parsing function
        {
            if(!BufferIsFull(&ZonesBuffer[Zone-1]))
            {
                BufferEnqueue(&ZonesBuffer[Zone-1],Command);
            }
            else
            {
                ClearBuffer(&ZonesBuffer[Zone]);
                BufferEnqueue(&ZonesBuffer[Zone-1],Command);
            }
        }
        else
        {
            //Undefined Zone 
        }
    }
    else 
    {
        //Non valid command
    }
    
    TickCounter++;
    if (TickCounter>=10000)
    {
        TickCounter=0;
        //send zonos data 
        for (uint8_t Zone=1; Zone<=MaxZones; Zone++)
        {
            ZoneData_t Data;
            Communication_SendZoneData(Zone, Data);
        }
    }
}

uint8_t Communication_HasNewCommand(uint8_t ZoneNumber)
{
   // psudo code:
   // 1) check if the zone number is valid (1 to MaxZones)
   if (ZoneNumber >0 && ZoneNumber <= MaxZones)
   {
       CommandBuffer_t *Buff = &ZonesBuffer[ZoneNumber];
       if (!BufferIsEmpty(Buff))
        {
            return New_Command_Available;   // buffer has a new command
        }
            else
        {
            return No_New_Command;   // buffer empty
        }
   }
   
}

Command_t Communication_GetCommand(uint8_t ZoneNumber)
{
    Command_t Command = {0};

    if (ZoneNumber >= 1 && ZoneNumber <= MaxZones)  
    {
        CommandBuffer_t *Buff = &ZonesBuffer[ZoneNumber];

        if (!BufferIsEmpty(Buff))
        {
            Command = Buff->Buffer[Buff->Head];
            Buff->Head = (Buff->Head + 1) % CMD_BUFFER_SIZE;
            Buff->Count--;
        }
    }

    return Command;
}

void Communication_SendZoneData(uint8_t ZoneNumber, ZoneData_t data)
{
    if (ZoneNumber >= 1 && ZoneNumber <= MaxZones)
    {
        uint8_t Temp_string[4];  // enough for "255"

        // Zone header
        hHC05_SendChar('Z');
        hHC05_SendChar(ZoneNumber + '0'); 
        hHC05_SendChar(':');

        // Fan speed
        hHC05_SendString("Fan Speed=");
        integer_to_string(data.FanSpeed, Temp_string);
        hHC05_SendString(Temp_string);

        // Light state
        hHC05_SendString(", Light=");
        if (data.LightState)
            hHC05_SendString("ON");
        else
            hHC05_SendString("OFF");

        // Temperature
        hHC05_SendString(", Temp=");
        integer_to_string(data.Temperature, Temp_string);
        hHC05_SendString(Temp_string);

        // New line
        hHC05_SendString("\r\n");
    }
}