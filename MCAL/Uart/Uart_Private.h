/**
 * @file     Uart_Privateh
 * @author   Developer: Naira Mohammed
 * @author   Reviewer: Ahmed Ashraf   
 * @brief    Internal definitions and macros for Uart driver implementation, including Uart registers and its bits 
 * @version   03
 * @date      (Created) 2025-08-19
 * @date      (Updated) 2025-09-09
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#ifndef _UART_PRIVATE_H_
#define _UART_PRIVATE_H_

/**
 * @note Read this section before UART configuration
 *       Key registers:
 *       1) UDR    : USART Data Register
 *       2) UCSRA  : Control and Status Register A
 *       3) UCSRB  : Control and Status Register B
 *       4) UCSRC  : Control and Status Register C
 */


/**
 * @def MPCM_Bit
 * @brief Enables multi processor communication mode
 */
#define MPCM_Bit     0

/**
 * @def U2X_Bit
 * @brief Double transmission speed in asynchronous mode and Must be cleared in synchronous mode
 */
#define U2X_Bit      1

/**
 * @def PE_Bit
 * @brief Indicates a parity error in received data
 */
#define PE_Bit       2

/**
 * @def DOR_Bit
 * @brief Indicates a data overrun condition
 */
#define DOR_Bit      3

/**
 * @def FE_Bit
 * @brief Indicates a frame error in received data
 */
#define FE_Bit       4

/**
 * @def UDRE_Bit
 * @brief USART Data Register Empty flag
 */
#define UDRE_Bit     5

/**
 * @def TXC_Bit
 * @brief USART Transmit Complete flag
 */
#define TXC_Bit      6

/**
 * @def RXC_Bit
 * @brief USART Receive Complete flag
 */
#define RXC_Bit      7

/**
 * @def TXB8_Bit
 * @brief Transmit bit 8 for 9-bit data frames
 */
#define TXB8_Bit     0

/**
 * @def RXB8_Bit
 * @brief Receive bit 8 for 9-bit data frames
 */
#define RXB8_Bit     1

/**
 * @def UCSZ2_Bit
 * @brief Character size bit 2
 */
#define UCSZ2_Bit    2

/**
 * @def TXEN_Bit
 * @brief Transmitter enable bit
 */
#define TXEN_Bit     3

/**
 * @def RXEN_Bit
 * @brief Receiver enable bit
 */
#define RXEN_Bit     4

/**
 * @def UDRIE_Bit
 * @brief USART Data Register Empty Interrupt Enable
 */
#define UDRIE_Bit    5

/**
 * @def TXCIE_Bit
 * @brief Transmit Complete Interrupt Enable
 */
#define TXCIE_Bit    6

/**
 * @def RXCIE_Bit
 * @brief Receive Complete Interrupt Enable
 */
#define RXCIE_Bit    7

/**
 * @def UCPOL_Bit
 * @brief Clock polarity bit (used in synchronous mode)
 */
#define UCPOL_Bit   0

/**
 * @def UCSZ0_Bit
 * @brief Character size bit 0
 */
#define UCSZ0_Bit   1

/**
 * @def UCSZ1_Bit
 * @brief Character size bit 1
 */
#define UCSZ1_Bit   2

/**
 * @def USBS_Bit
 * @brief Stop bit select (0 = 1 bit, 1 = 2 bits)
 */
#define USBS_Bit    3

/**
 * @def UPM0_Bit
 * @brief Parity mode bit 0
 */
#define UPM0_Bit    4

/**
 * @def UPM1_Bit
 * @brief Parity mode bit 1
 */
#define UPM1_Bit    5

/**
 * @def UMSEL_Bit
 * @brief USART mode select (0 = async, 1 = sync)
 */
#define UMSEL_Bit   6

/**
 * @def URSEL_Bit
 * @brief Register select (1 = UCSRC, 0 = UBRRH)
 */
#define URSEL_Bit   7

/**
 * @def Stop1Bit
 * @brief Use 1 stop bit in frame format
 */
#define Stop1Bit       0

/**
 * @def Stop2Bit
 * @brief Use 2 stop bits in frame format
 */
#define Stop2Bit       1

/**
 * @def NormalSpeed
 * @brief Normal transmission speed (U2X = 0)
 */
#define NormalSpeed    0

/**
 * @def DoubleSpeed
 * @brief Double transmission speed (U2X = 1)
 */
#define DoubleSpeed    1

/**
 * @def Rx_Enable
 * @brief Enable receiver only
 */
#define Rx_Enable      0

/**
 * @def Tx_Enable
 * @brief Enable transmitter only
 */
#define Tx_Enable      1

/**
 * @def Rx_Tx_Enable
 * @brief Enable both receiver and transmitter
 */
#define Rx_Tx_Enable   2

/**
 * @def ParityDisable
 * @brief Disable parity check
 */
#define ParityDisable  0

/**
 * @def ParityEven
 * @brief Enable even parity
 */
#define ParityEven     1

/**
 * @def ParityOdd
 * @brief Enable odd parity
 */
#define ParityOdd      2

/**
 * @def Data5Bit
 * @brief 5-bit character size
 */
#define Data5Bit       0

/**
 * @def Data6Bit
 * @brief 6-bit character size
 */
#define Data6Bit       1

/**
 * @def Data7Bit
 * @brief 7-bit character size
 */
#define Data7Bit       2

/**
 * @def Data8Bit
 * @brief 8-bit character size
 */
#define Data8Bit       3

/**
 * @def Data9Bit
 * @brief 9-bit character size
 */
#define Data9Bit       4

/**
 * @def RxPolling
 * @brief Receive data using polling method
 */
#define RxPolling      0

/**
 * @def RxInterrupt
 * @brief Receive data using interrupt method
 */
#define RxInterrupt    1



#endif /*_UART_PRIVATE_H_*/