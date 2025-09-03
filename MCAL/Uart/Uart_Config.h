/**
 * @file     Uart_Config.h
 * @author   Naira Mohammed
 * @author   Ahmed Ashraf
 * @brief    User configuration file, allowing user to configure Uart parameters.
 * @version   0.2
 * @date      2025-08-19
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#ifndef _UART_CONFIG_H_
#define _UART_CONFIG_H_
#include "Uart_Private.h"
/**
 * @note this drive supports only Asynchronization Mode 
 */

 /**
 * @def ParityMode
 * @brief Defines the parity check mode used in USART communication.
 * 
 * Options:
 * - ParityDisable      : No parity bit is used.
 * - ParityEven         : Even parity mode.
 * - ParityOdd          : Odd parity mode.
 */
#define ParityMode       ParityDisable

/**
 * @def DataBits
 * @brief Defines the number of data bits used in USART frame.
 * 
 * Options:
 * - Data5Bit, Data6Bit, Data7Bit, Data8Bit, Data9Bit
 */
#define DataBits         Data8Bit

/**
 * @def TranceiverMode
 * @brief Defines whether the USART operates as transmitter, receiver, or both.
 * 
 * Options:
 * - Tx_Enable     : Enable only transmission.
 * - Rx_Enable     : Enable only reception.
 * - Rx_Tx_Enable  : Enable both transmission and reception.
 */
#define TranceiverMode   Rx_Tx_Enable

/**
 * @def USARTSpeed
 * @brief Defines the USART communication speed mode.
 * 
 * Options:
 * - NormalSpeed  : Standard baud rate.
 * - DoubleSpeed  : Double the baud rate for faster communication.
 */
#define USARTSpeed       DoubleSpeed

/**
 * @def StopBits
 * @brief Defines the number of stop bits in the USART frame.
 * 
 * Options:
 * - Stop1Bit : Use one stop bit.
 * - Stop2Bit : Use two stop bits.
 */
#define StopBits         Stop1Bit

/* Baud rate after calculate
 * Baud rate value = 9600
 * Foc = 8MHz
 *     Normal speed: UBRR=((Freq)/16*BaudRate)-1
 *     double speed: UBRR=((Freq)/8*BaudRate)-1
 * According to Double Speed, UBRR value = 103.1667
 * According to Normal Speed, UBRR value = 51
 */
#define UBRR_Value   103

/**
 * @note this drive supports only polling for Tx
 *       while it supports polling or interrupt for Rx
 */
#define RxHandling   RxInterrupt

#endif /*_UART_CONFIG_H_*/