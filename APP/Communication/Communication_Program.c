/**
 * @file     Communication_Program.h
 * @author   Developer: Naira Mohammed (naira.mohammed.76@gmail.com)
 * @author   Developer: Ahmed Ashraf    (ahmedashraf2022222@gmail.com)
 * @brief    Implementation of Communication application functions.
 * @version   0.1
 * @date      2025-09-14
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

 #include "Communication_Interface.h"

   static Command_t ZonesBuffer[MaxZones];

void BufferInit(CommandBuffer_t *Buffer)
{
    Buffer->Head = 0;
    Buffer->Tail = 0;
    Buffer->Count = 0;
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

Command_t BufferDequeue(CommandBuffer_t *Buff)
{
    Command_t Command = {0};
    
    if (!BufferIsEmpty(Buff))
    {
        Command = Buff->Buffer[Buff->Head];
        Buff->Head = (Buff->Head + 1) % CMD_BUFFER_SIZE;
        Buff->Count--;
    }
    
    return Command;
}

void Communication_Init(void)
{
    /* Initialize buffers for all zones */
    for (uint8_t i = 0; i < MaxZones; i++)
    {
        BufferInit(&ZonesBuffer[i]);
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

}
uint8_t Communication_HasNewCommand(uint8_t ZoneNumber);
Command_t Communication_GetCommand(uint8_t ZoneNumber);
void Communication_SendZoneData(uint8_t ZoneNumber, ZoneData_t data);

