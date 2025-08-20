/**
 * @file     DIO_Private.h
 * @author   <Hozifa Ahmed>
 * @author   <Reviewer>
 * @brief 
 * @version   0.2
 * @date      2025-08-17
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_
#include <stdint.h>


//Direction Pins
#define DDRA_REG  *((volatile uint8_t*)0x3A)
#define DDRB_REG  *((volatile uint8_t*)0x37)
#define DDRC_REG  *((volatile uint8_t*)0x34)
#define DDRD_REG  *((volatile uint8_t*)0x31)




//Input Pins
#define PORTA_REG *((volatile uint8_t*)0x3B)
#define PORTB_REG *((volatile uint8_t*)0x38)
#define PORTC_REG *((volatile uint8_t*)0x35)
#define PORTD_REG *((volatile uint8_t*)0x32)




//Output pins
#define PINA_REG  *((volatile uint8_t*)0x39)
#define PINB_REG  *((volatile uint8_t*)0x36)
#define PINC_REG  *((volatile uint8_t*)0x33)
#define PIND_REG  *((volatile uint8_t*)0x30)











#endif /*_DIO_PRIVATE_H_*/

