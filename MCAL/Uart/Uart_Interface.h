/**
 * @file     Uart_Interface.h
 * @author   Naira Mohammed
 * @author   Ahmed Ashraf
 * @brief    Public API's and function prototypes for Uart driver, allowing the user to initialize and use Uart peripheral 
 * @version   0.2
 * @date      2025-08-19
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#ifndef _UART_INTERFACE_H_
#define _UART_INTERFACE_H_
#include "Uart_Config.h"
#include <stdint.h>
/**
 * @fn this is the call back function of UART.
 */
void USART_RxCallBack(void(*PointerFunc)(uint16_t Data));


/**
 * @fn this function is to intialize USART
 */
void USART_Init();

/**
 * @fn this function is to Transmit data of 16_bits size
 */
void USART_Transmit(uint16_t TxData);

/**
 * @fn this function is to receive data of 16_bits size
 */
uint16_t USART_Receive();

/**
 * @brief USART RX Complete Interrupt Service Routine (ISR).
 *
 *        This ISR is triggered automatically when the USART finishes 
 *        receiving a complete frame of data. 
 */
void __vector_13(void) __attribute__((signal)); // ISR For RX complete 


#endif /*_UART_INTERFACE_H_*/