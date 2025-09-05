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


/**
 * @fn hHC05_ReceiveChar: this function is to receive char from Hc05 buffer.
 * @param *Char: a pinter to store the received char.
 * @brief Psudo code:
 *          1) check buffer state, if empty, there will be nothing to read.
 *          2) if buffer state isn't empty:
 *                 Read RxBuffer[Head] into *Char, using dequeue static function.
 * @note This function blocks until a character is available.
 */
void hHC05_ReceiveChar(uint8_t *Char);

/**
 * @fn hHC05_ReceiveString: this function receives a String from Hc05 ring buffer.
 * @param *String: a pinter to the destination buffer where the received String will be stored.
 * @param maxLen: maximum number of bytes to be received and stored in RxBuffer,
 *                it prevents buffer overflow by limiting amount of data copied from the ring buffer.
 * @brief Psudo code:
 *          1) initializes counter =0, it tracks how many bytes have been copied from buffer to the string, 
 *             and to ensure it doesn't exceed maxLen.
 *          2) While (state isn't empty) AND (counter < maxLen-1):
 *                 -> Read RxBuffer[Head] into receivedChar, using dequeue static function.
 *                 -> counter++. 
 *                 -> If byte is newline or carriage return, stop reading.
 *          3) Null terminate the received string.
 * @note The function removes bytes from the ring buffer as they are read.
 * @note Reading stops when: buffer empty, maxLen reached, or newline character found.
 */
void hHC05_ReceiveString(uint8_t *String, uint16_t maxLen);

/**
 * @fn hHC05_RxISRHandler: UART Rx interrupt servise routine handler.
 * @param byte: this is the received byte from UART.
 * @brief Psudo code:
 *            1) Check buffer state:
 *                -> if not Full, Write byte at Tail position in RX buffer, by using Enqueue static function.
 *                -> If Full (overflow case), Advance Head by one (usin Dequeue function), 
 *                   then add the byte in buffer usin Enqueue function.
 *            2) Exit ISR.
 */
void hHC05_RxISRHandler(uint16_t byte);


#endif /*_HC05_INTERFACE_H_*/
