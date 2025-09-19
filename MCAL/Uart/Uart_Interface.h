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
 * 
 * @fn void mUART_RxCallBack(void(*PointerFunc)(uint16_t Data));
 * @brief A callback function to be executed when UART receives data.
 * 
 * @details This function sets callback function that will be called (using pointer to function)
 *          when the UART receive complete interrupt occurs. It also enables the 
 *          corresponding interrupt.
 *
 * @param PointerFunc A pointer to the callback function. 
 *                   must not be NULL, otherwise no action will be taken.
 * 
 */
void mUART_RxCallBack(void(*PointerFunc)(uint16_t Data));


/**
 * @fn      mUART_Init
 * @brief   Initializes the UART communication protocol.
 * @details This function configures the UART peripheral with the following steps:
 *          1. Select asynchronous mode:
 *             - Clear UMSEL_Bit in UCSRC_Reg.
 *             - Clear UCPOL_Bit in UCSRC_Reg.
 *          2. Set frame format:
 *             - Character size selection (5, 6, 7, 8, or 9 bits) using UCSZ0, UCSZ1, UCSZ2 bits.
 *             - Parity mode selection (Disabled, Even, Odd) using UPM0 and UPM1 bits.
 *             - Stop bit selection (1 or 2 bits) using USBS_Bit.
 *          3. Select speed mode:
 *             - Normal mode: Clear U2X bit in UCSRA.
 *             - Double speed: Set U2X bit in UCSRA.
 *          4. Set baud rate:
 *             - Configure UBRR register (16 bits: UBRRL and UBRRH).
 *          5. Set transceiver mode:
 *             - Enable TX, RX, or both using TXEN and RXEN bits in UCSRB.
 *          6. Disable UART interrupts:
 *             - RXCIE, TXCIE, and UDRIE bits in UCSRB are cleared.
 *          7. Set URSEL bit in UCSRC to select UCSRC register for configuration.
 * @note    If receive interrupt is enabled, implement UART_Receive_and_RxInterruptMode() in the communicating module initialization.
 */
 
void mUART_Init();

/**
 * @fn      mUART_Transmit
 * @brief   UART data transmissin Function
 * @details This function transmits data using UART communication protocol.
 *          1. Wait until UDR register is empty (UDRE) in (UCSRA) register.
 *          2. Check Char Size (5, 6, 7, 8 or 9 bits).
 *          3. Write data to UDR register.
 *          4. Wait until TX complete flag (TCX bit) is set in (UCSRA) register.
 *          5. Clear TX complete flag (TXC bit) by setting it to 1.
 * @param TxData:  Data to be transmitted (5, 6, 6, 7, 8 or 9 bits depending on configuration).
 */
void mUART_Transmit(uint16_t TxData);

/**
 * @fn mUART_Receive_and_RxInterruptMode
 * @brief   UART data Recieve Function
 * 
 * @details Receives data using the UART communication protocol.
 *          - Check Rx handling mode (polling or interrupt), as configured in configuration file.
 *          - If polling:
 *              1. Wait until data is received (RXC flag in UCSRA).
 *              2. Read data from the UDR register.
 *          - If interrupt:
 *              1. Enable the receive interrupt.
 *              2. Data will be handled by the ISR and passed to the registered callback function.
 *
 * @retval uint16_t The received data (8 or 9-bit depending on configuration).
 * 
 * @note   We Configured the UART as polling
 */
uint16_t mUART_Receive_and_RxInterruptMode();

/**
 * @fn    void __vector_13(void) __attribute__((signal)); 
 * @brief USART RX Complete ISR(Interrupt Service Routine).
 *
 * @details This corresponds to vector number 13 in the interrupt vector table.
 *          The received data is usually read from the UDR register inside this ISR 
 *          and passed to a callback handler.
 *          This ISR is automatically executed when a new data frame 
 *          has been completely received through the UART.
 * 
 * @note    this interrupt happen only if you have enabled the RX Complete Interrupt RCIE bit is enabled
 */
void __vector_13(void) __attribute__((signal)); 


#endif /*_UART_INTERFACE_H_*/