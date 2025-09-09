/**
 * @file     Uart_Interface.h
 * @author   Developer: Naira Mohammed
 * @author   Reviewer: Ahmed Ashraf   
 * @brief    Public API's and function prototypes for Uart driver, allowing the user to initialize and use Uart peripheral 
 * @version   0.3
 * @date      (Created) 2025-08-19
 * @date      (Updated) 2025-09-09
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _UART_INTERFACE_H_
#define _UART_INTERFACE_H_
#include "Uart_Config.h"
#include "../../Common/Macro.h"
#include "../RegistersAddress.h"
#include <stdint.h>
/**
 * @fn A callback function to be executed when UART receives data.
 * @brief A callback function to be executed when UART receives data.
 *       This function sets callback function that will be called 
 *       when the UART receive complete interrupt occurs. It also enables the 
 *       corresponding interrupt.
 *
 * @param PointerFunc A pointer to the callback function. 
 *        must not be NULL, otherwise no action will be taken.
 */
void mUART_RxCallBack(void(*PointerFunc)(uint16_t Data));


/**
 * @fn mUART_Init()
 * @brief This function is to initialize UART communication protocol:
 *     1)Mode select -> Asynchronization
 *            * clear UMSEL_Bit in UCSRC_Reg
 *            * clear clock polarity bit (UCPOL_Bit) in UCSRC
 *     2)Frame format
 *            * char size 
 *                5-bit size ->
 *                  UCSZ0_Bit in UCSRC = 0
 *                  UCSZ1_Bit in UCSRC = 0
 *                  UCSZ2_Bit in UCSRB = 0
 *                6-bit size ->
 *                  UCSZ0_Bit in UCSRC = 1
 *                  UCSZ1_Bit in UCSRC = 0
 *                  UCSZ2_Bit in UCSRB = 0
 *                7-bit size ->
 *                  UCSZ0_Bit in UCSRC = 0
 *                  UCSZ1_Bit in UCSRC = 1
 *                  UCSZ2_Bit in UCSRB = 0
 *                8-bit size ->
 *                  UCSZ0_Bit   in   UCSRC = 1
 *                  UCSZ1_Bit   in   UCSRC = 1
 *                  UCSZ2_Bit   in   UCSRB = 0
 *                9bit size ->
 *                  UCSZ0_Bit   in   UCSRC = 1
 *                  UCSZ1_Bit   in   UCSRC = 1
 *                  UCSZ2_Bit   in   UCSRB = 1
 *            * Parity mode
 *                  Disabled ->
 *                   UPM0_Bit in UCSRC = 0
 *                   UPM1_Bit in UCSRC = 0
 *                
 *                 Even Parity ->
 *                   UPM0_Bit in UCSRC = 0
 *                   UPM1_Bit in UCSRC = 1
 *                
 *                 Odd Parity ->
 *                   UPM0_Bit in UCSRC = 1
 *                   UPM1_Bit in UCSRC = 1
 *            * Stop Bits
 *                 1 Stop Bit ->
 *                   USBS_Bit in UCSRC = 0
 *                 2 Stop Bits ->
 *                   USBS_Bit in UCSRC = 1
 *     3) speed select 
 *            *Normal mode: 
 *                 Clear U2X bit in UCSRA register to 0
 *            *Double Speed: 
 *                 Set U2X bit in UCSRA register to 1
 *     4) setting baud rate into UBRR register
 *             UBRR register has a size of 16 bits
 *                if UBRR value has a size lower than or equal to 1111 1111 (255), it will be stored in UBRRL 
 *                if the value is greater, the first 8 bits in UBRRL wil be completed 
 *                   then the second [9:16]bits will be stored in UBRRH
 *     5) Tranceiver mode 
 *            *Tx enable: 
 *                 Set TXEN bit in UCSRB register to 1
 *                 Clear RXEN bit in UCSRB register to 0
 *            *Rx enable: 
 *                 Clear TXEN bit in UCSRB register to 0
 *                 Set RXEN bit in UCSRB register to 1
 *            *Tx or Rx enable: 
 *                 Set TXEN bit in UCSRB register to 1
 *                 Set RXEN bit in UCSRB register to 1
 *     6) Disable Interrupt
 *            Disable For RX complete interrupt (RXCIE) - > 0 in UCSRB
 *            Disable For Tx complete interrupt (TXCIE) - > 0 in UCSRB
 *            Disable For UDR empty interrupt (UDRIE) - > 0 in UCSRB
 *     7) set URSEL bit in UCSRC to choose to write in UCSRC 
 *       instead of UBRRH     
 */ 
 
void mUART_Init();

/**
 * @fn mUART_Transmit
 *
 * @param TxData:  Data to be transmitted (5, 6, 6, 7, 8 or 9 bits depending on configuration).
 *
 * @brief This function transmits data using UART communication protocol. 
 *        Pseudo Code:
 *       1) Wait until UDR register is empty (UDRE) in (UCSRA) register.
 *       2) Check Char Size (5, 6, 7, 8 or 9 bits).
 *       3) Write data to UDR register.
 *       4) Wait until TX complete flag (TCX bit) is set in (UCSRA) register.
 *       5) Clear TX complete flag (TXC bit) by setting it to 1.
 */
void mUART_Transmit(uint16_t TxData);

/**
 * @fn mUART_Receive_and_RxInterruptMode
 * @brief Receives data using the UART communication protocol.
 *
 * Pseudo code:
 * - Check Rx handling mode (polling or interrupt), as configured in configuration file.
 *   - If polling:
 *         1. Wait until data is received (RXC flag in UCSRA).
 *         2. Read data from the UDR register.
 *   - If interrupt:
 *         1. Enable the receive interrupt.
 *         2. Data will be handled by the ISR and passed to the registered callback function.
 *
 * @retval uint16_t The received data (8 or 9-bit depending on configuration).
 */
uint16_t mUART_Receive_and_RxInterruptMode();

/**
 * @brief USART RX Complete Interrupt Service Routine.
 *
 *        This ISR is automatically executed when a new data frame 
 *        has been completely received through the UART.
 *
 * @note This corresponds to vector number 13 in the interrupt vector table.
 *       The received data is usually read from the UDR register inside this ISR 
 *       and passed to a callback handler.
 */
void __vector_13(void) __attribute__((signal)); 


#endif /*_UART_INTERFACE_H_*/