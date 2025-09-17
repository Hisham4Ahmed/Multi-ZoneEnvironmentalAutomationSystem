/**
 * @file     Uart_Config.h
 * @author   Developer: Naira Mohammed
 * @author   Reviewer: Ahmed Ashraf   
 * @brief    User configuration file, allowing user to configure Uart parameters.
 * @version   0.3
 * @date      (Created) 2025-08-19
 * @date      (Updated) 2025-09-09
 * @note this driver supports only Asynchronization Mode 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#ifndef _UART_CONFIG_H_
#define _UART_CONFIG_H_
#include "Uart_Private.h"
/**
 * @def ParityMode
 * @brief UART parity configuration macro.
 *
 * @details Specifies the parity check mode used during UART communication.
 *          Available options:
 *          - ParityDisable : No parity bit is used.
 *          - ParityEven    : Enables even parity.
 *          - ParityOdd     : Enables odd parity.
 *
 * @note Default setting is ParityDisable.
 */
#define ParityMode       ParityDisable

/**
 * @def DataBits
 * @brief UART data bits configuration macro.
 *
 * @details Specifies the number of data bits in each UART frame.
 *          Available options:
 *          - Data5Bit
 *          - Data6Bit
 *          - Data7Bit
 *          - Data8Bit
 *          - Data9Bit
 */
#define DataBits         Data8Bit


/**
 * @def TranceiverMode
 * @brief UART as Transmitter or/and Reciever Configuration macro 
 * 
 * @details Specifies weather the UART Acts like a reciever , a transmitter or both.
 *          Availble options:
 *          - Tx_Enable     : Enable only transmission.
 *          - Rx_Enable     : Enable only reception.
 *          - Rx_Tx_Enable  : Enable both transmission and reception.
 */
#define TranceiverMode   Rx_Tx_Enable

/**
 * @def   UARTSpeed
 * @brief UART Speed Configuration macro.
 * 
 * @details Defines the UART communication speed mode.
 *          Availble Options:
 *          - NormalSpeed  : Standard baud rate.
 *          - DoubleSpeed  : Double the baud rate for faster communication.
 */
#define UARTSpeed       DoubleSpeed

/**
 * @def   StopBits
 * @brief UART number of stop bits configuration macro.
 * 
 * @details Specifies the number of stop bits in the UART frame.
 *          Availble Options:
 *          - Stop1Bit : Use one stop bit.
 *          - Stop2Bit : Use two stop bits.
 */
#define StopBits         Stop1Bit

/**
 * @def UBRR_value
 * @details UART Baud Rate configuration macro.
 *  
 * @details UART Baud Rate Register value 
 *          UBRR value calculations:
 *          Baud rate value = 9600
 *          Foc = 8MHz
 *          at Normal speed: UBRR=((Freq)/16*BaudRate)-1
 *          at double speed: UBRR=((Freq)/8*BaudRate)-1
 *          According to Double Speed, UBRR value = 103.1667
 *          According to Normal Speed, UBRR value = 51
 */
#define UBRR_Value   103

/**
 * @def RxHandling
 * @brief UART receiver handling incoming data configuration macro.
 * 
 * @details Defines how the UART receiver handles incoming data.
 *          Availble Options:
 *          - RxPolling   : Use polling to receive data.
 *          - RxInterrupt : Use interrupts to receive data.
 *
 * @note This driver supports only polling for transmission (Tx),
 *       while reception (Rx) can be handled either by polling or interrupt.
 */
#define RxHandling   RxInterrupt

#endif /*_UART_CONFIG_H_*/