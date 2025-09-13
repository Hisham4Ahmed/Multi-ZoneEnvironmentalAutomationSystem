/**
 * @file     HC05_Interface.h
 * @author   Developer: Naira Mohammed (naira.mohammed.76@gmail.com)
 * @author   Reviewer: Ahmed Ashraf 
 * @brief    Public interface for HC05 driver implementation.
 * @version   0.2
 * @date      2025-09-03
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

 

#ifndef _HC05_INTERFACE_H_
#define _HC05_INTERFACE_H_

#include "HC05_Config.h"
#include "HC05_Private.h"
#include "../../MCAL/Uart/Uart_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../Common/ZoneConfig.h"
 
#include <stdint.h>
/**
 * @fn hHC05_Init: this function initializes HC05 module.
 * @brief This Function Initializes HC05 module
 * @details Psudo code:
 *          1) set direction pins:
 *                 Bluetooth Tx → MCU Rx (PD0) as Input
 *                 Bluetooth Rx → MCU Tx (PD1) as Output
 *          2) set Uart callback to hHC05_RxISRHandler().
 *          3) Initialize internal RX buffer.
 *          4) Call Uart init function.
 * @return void      
 */
void hHC05_Init();



 /**
 * @fn hHC05_SendChar: this function sends char via bluetooth.
 * @brief   Call USART_Transmit(uint16_t TxData); and let it send char.
 * @param char
 * @brief The Char To be Sent.
 */
void hHC05_SendChar(uint8_t Char);

/**
 * @fn hHC05_SendString: this function sends string of chars via bluetooth.
 * @param *String: string is an array of chars, the (*) is to access chars and send them.
 * @brief Psudo code:
 *          1) while current char != to Null
 *               -> call hHC05_SendChar and let it's arguments (*String), 
 *                  to access the chars of the string array and send them 
 *                  one by one.
 *               -> Repeat until end of string.
 */
void hHC05_SendString(const uint8_t *String);

/**
 * @fn hHC05_ReceiveChar: this function is to receive char from Hc05 buffer.
 * @param *Char: a pointer to store the received char.
 * @brief This Function receives a char from Hc05 ring buffer.
 * @details Psudo code:
 *          1) check buffer state, if empty, there will be nothing to read.
 *          2) if buffer state isn't empty:
 *                 Read RxBuffer[Head] into *Char, using dequeue static function.
 * @note This function blocks until a character is available.
 */
void hHC05_ReceiveChar(uint8_t *Char);

/**
 * @fn hHC05_ReceiveString
 * @brief : this function receives a String from Hc05 ring buffer. 
 * @param *String: a pinter to the destination buffer where the received String will be stored.
 * @param maxLen: maximum number of bytes to be received and stored in RxBuffer,
 *                it prevents buffer overflow by limiting amount of data copied from the ring buffer.
 * @details  Psudo code:
 *          1) initializes counter =0, it tracks how many bytes have been copied from buffer to the string, 
 *             and to ensure it doesn't exceed maxLen.
 *          2) While (state isn't empty) AND (counter < maxLen-1):
 *                 -> Read RxBuffer[Head] into receivedChar, using dequeue static function.
 *                 -> counter++. 
 *                 -> If byte is newline or carriage return, stop reading.
 *          3) Null terminate the received string.
 * @note The function removes bytes from the ring buffer as they are read.
 * @note Reading stops when: buffer empty, maxLen reached, or newline character found.
 * @note This Function does not block if no data is available 
 *       -> a delay may be needed before calling it to allow data to arrive.
 */
void hHC05_ReceiveString(uint8_t *String, uint16_t maxLen);

/**
 * @fn hHC05_RxISRHandler
 * @brief This is the UART RX interrupt service routine (ISR) handler for HC05 module.
 * @param byte: this is the received byte from UART.
 * @details Psudo code:
 *            1) Check buffer state:
 *                -> if not Full, Write byte at Tail position in RX buffer, by using Enqueue static function.
 *                -> If Full (overflow case), Advance Head by one (usin Dequeue function), 
 *                   then add the byte in buffer usin Enqueue function.
 *            2) Exit ISR.
 */
void hHC05_RxISRHandler(uint16_t byte);


#endif /*_HC05_INTERFACE_H_*/
