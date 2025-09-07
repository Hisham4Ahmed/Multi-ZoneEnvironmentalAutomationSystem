/**
 * @file     Uart_Private.h
 * @author   Developer: Naira Mohammed
 * @author   Reviewer: Ahmed Ashraf   
 * @brief    Internal definitions and macros for Uart driver implementation, including Uart registers and its bits. 
 * @version   0.3
 * @date      2025-08-19
 * @date      2025-09-07
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#ifndef _UART_PRIVATE_H_
#define _UART_PRIVATE_H_

/**
 * 1) UDR: USART data register
*/

/**
 * 2) UCSRA: control and status register A
 */
#define MPCM_Bit     0  // enables multi processor communication mode
#define U2X_Bit      1  // when (Async), it doubles transmission speed making divisor = 8
                        // when (Sync), make it 0
#define PE_Bit       2  // Parity error
#define DOR_Bit      3  // Data overrun
#define FE_Bit       4  // Frame error
#define UDRE_Bit     5  // USART data register empty
#define TXC_Bit      6  // USART transmit complete
#define RXC_Bit      7  // USART receive complete

/**
 * 3) UCSRB: control and status register B
 */
#define TXB8_Bit     0  // Transmit data bit 8
#define RXB8_Bit     1  // Receive data bit 8
#define UCSZ2_Bit    2  // Character size bit 2
#define TXEN_Bit     3  // Transmitter enable 
#define RXEN_Bit     4  // Receiver enable 
#define UDRIE_Bit    5  // USART data register empty interrupt enable
#define TXCIE_Bit    6  // TX complete interrupt enable 
#define RXCIE_Bit    7  // RX commplete interrupt enable 

/**
 * 4) UCSRC: Control and Status Register C
 */
#define UCPOL_Bit   0   // Clock polarity
#define UCSZ0_Bit   1   // Character size bit 0
#define UCSZ1_Bit   2   // Character size bit 1
#define USBS_Bit    3   // Stop bit select
#define UPM0_Bit    4   // Parity mode bit 0
#define UPM1_Bit    5   // Parity mode bit 1
#define UMSEL_Bit   6   // USART mode select
#define URSEL_Bit   7   // Register select (1 = UCSRC, 0 = UBRRH)

 /**
  * Stop Bits 
  */
#define Stop1Bit       0
#define Stop2Bit       1
/*
 * Speed Modes 
 */
#define NormalSpeed    0
#define DoubleSpeed    1
/**
 * Tranceiver Modes 
 */
#define Rx_Enable      0
#define Tx_Enable      1
#define Rx_Tx_Enable   2
/**
 * Parity Modes
 */
#define ParityDisable  0
#define ParityEven     1
#define ParityOdd      2
/**
 * Char Size Options
 */
#define Data5Bit       0
#define Data6Bit       1
#define Data7Bit       2
#define Data8Bit       3
#define Data9Bit       4
/**
 * Receiving Mode
 */
#define RxPolling      0
#define RxInterrupt    1




#endif /*_UART_PRIVATE_H_*/