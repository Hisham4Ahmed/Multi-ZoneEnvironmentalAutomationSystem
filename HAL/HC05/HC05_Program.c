/**
 * @file     HC05_Program.c
 * @author   Developer: Naira Mohammed (naira.mohammed.76@gmail.com)
 * @author   Reviewer: Ahmed Ashraf 
 * @brief    Implementation of HC05 bluetooth module driver functions.
 * @version   0.1
 * @date      2025-09-03
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#include "../../Common/Config.h"
#if HC05_Driver

#include "HC05_Interface.h"
#include <stdint.h>


/**
 * @brief the ring buffer of the HC05 is declared as RxBufer, it's an array of size 256 bytes.
 *        to implement it, Head,Tail,Count are also declared.
 * @var  Head: points to the first element in the circular queue (the ring buffer).
 * @var  Tail: points to the last added element to the queue.
 * @var  Count: number of elements in buffer.
 */
volatile uint8_t RxBuffer[Buffer_Size];
volatile uint8_t Head=0;
volatile uint8_t Tail=0;  
volatile uint8_t Count=0;  

/**
 * @brief the following static functions are related to the ring buffer, 
 *        they are only used in this file, that's why they are static
 */
static void RxBuffer_Init();
static enum BufferState GetBufferState(); 
static void Enqueue_Buffer(uint8_t Value);
static uint8_t Dequeue_Buffer();          
           

void hHC05_Init(void)
{
    DIO_Direction_Pin(Bluetooth_TxGroup, Bluetooth_TxPin, DIO_Input);
    DIO_Direction_Pin(Bluetooth_RxGroup, Bluetooth_RxPin, DIO_Output);
    mUart_CallBack(hHC05_RxISRHandler);
    RxBuffer_Init();
    USART_Init();
}

void hHC05_SendChar(uint8_t Char)
{
    USART_Transmit(Char);
}

void hHC05_SendString(const uint8_t *String)
  {
    while (*String!=Null)
    {
        hHC05_SendChar(*String);
        String++;
    }
  }

void hHC05_ReceiveChar(uint8_t *Char)
  {
    while (GetBufferState()==Empty)
    {
        // Nothing to be read
    }
    *Char=Dequeue_Buffer();
  }

void hHC05_ReceiveString(uint8_t *String, uint16_t maxLen)
  {
    uint8_t Counter=0;
    uint8_t RxChar=0;
    enum BufferState state = GetBufferState();
    while ((state!=Empty) && (Counter < maxLen-1))
    {
        RxChar=Dequeue_Buffer();
        String[Counter++]=RxChar;
        if (RxChar=='\n' || RxChar=='\r')
        {
            break;
        }
    }
    String[Counter] = Null;
  }

void hHC05_RxISRHandler(uint8_t byte)
{
    enum BufferState state = GetBufferState();
    if (state!=Full)
    {
        Enqueue_Buffer(byte);
    }
    else if(state==Full)
    {
        Dequeue_Buffer();
        Enqueue_Buffer(byte);
    }
}

/**
 * @fn   RxBuffer_Init(): initializes the buffer by setting Head=Tail=Count=0
 */
static void RxBuffer_Init()
{
    Head=0;
    Tail=0;
    Count=0;
}

/** 
 * @fn   BufferState GetBufferState(): this functions has the 3 states of the buffer, 
 *       (Empty, Full, PartiallyFull), it returns the current state of the buffer.
 *       if count=0, return empty buffer.
 *       else if count = buffer size, return full buffer.
 *       else return partially full buffer.
*/
static enum BufferState GetBufferState()        
{
    if (Count==0)
    {
        return Empty;
    }
    else if (Count == Buffer_Size)
    {
        return Full;
    }
    else 
    {
        return PartiallyFull;
    }
}

/**
 * @fn   Enqueue_Buffer: writes data to Rx buffer at the position of tail.
 * @param Value: this is the data byte that will be stored in the buffer.
 * @brief Psudo code:
 *          1) check buffer state:
 *          2) if not full, then i can write in it.
 *               -> increase tail pointer each time, with wrap-around.
 *               -> put value in RxBuffer at the new position of tail.
 *               -> if the state was empty, Head must be set to match tail.
 *               -> increament element count in the queue each time.
 *          3) else, the buffer is full, no operation. 
 */
 
static void Enqueue_Buffer(uint8_t Value)           
{
    enum BufferState state = GetBufferState();
    if (state!=Full)
    {
        Tail = (Tail+1) % Buffer_Size;
        RxBuffer[Tail]=Value;
        if (state==Empty)
        {
            Head=Tail;
        }
        Count++;
    }
    else 
    {
        // buffer is Full, or undefined state
    }    

}

/**
 * @fn   Dequeue_Buffer(): removes and returns data from buffer at the position of head.
 * @return uint8_t the data byte removed from buffer.
 * @brief Psudo code:
 *          1) declare variable to store the returned data in it.
 *          2) check buffer state:
 *               -> if not Empty, then i can read what's inside or drop data out.
 *                  read value from RxBuffer at the position of Head.
 *                  increase Head pointer each time, with wrap around.
 *                  decreament elements count by 1 each time.
 *               -> if the state was empty, nothing to be read and returns 0.
 */
static uint8_t Dequeue_Buffer()           
{
    uint8_t Value=0;
    enum BufferState state = GetBufferState();
    if (state!=Empty)
    {
        Value=RxBuffer[Head];
        Head = (Head+1) % Buffer_Size;
        Count--;
    }
    else if (state==Empty)
    {
        // nothing to be Read
    }
    else 
    {
        // undefined state
    }
    return Value;

}   


#endif /*HC05_Driver*/