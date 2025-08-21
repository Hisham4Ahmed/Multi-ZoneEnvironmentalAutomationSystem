/**
 * @file     DIO_Interface.h
 * @author   <Hozifa Ahmed>
 * @author   <Naira Mohamed>
 * @brief    Digital Input/Output Driver Interface
 * @version  0.2
 * @date     2025-08-21
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#include <stdint.h>

/* ------------------- Group Macros ------------------- */
#define GroupA   1
#define GroupB   2
#define GroupC   3
#define GroupD   4

/* ------------------- Pin Macros ------------------- */
#define Pin0       0
#define Pin1       1
#define Pin2       2
#define Pin3       3
#define Pin4       4
#define Pin5       5
#define Pin6       6
#define Pin7       7

/* ------------------- Direction Macros ------------------- */
#define DIO_Input  0
#define DIO_Output 1

/* ------------------- Value Macros ------------------- */
#define DIO_Low    0
#define DIO_High   1

/* ------------------- APIs ------------------- */

/**
 * @brief  Set pin direction (input/output)
 * @param  GroupName      Port group (GroupA, GroupB, GroupC, GroupD)
 * @param  PinNumber      Pin number (0..7)
 * @param  DirectionState Direction (DIO_Input or DIO_Output)
 */
void DIO_Direction_Pin(uint8_t GroupName , uint8_t PinNumber , uint8_t DirectionState);

/**
 * @brief  Write logic value to pin (high/low)
 * @param  GroupName   Port group
 * @param  PinNumber   Pin number
 * @param  OutputType  Output value (DIO_Low, DIO_High)
 */
void DIO_Write_Pin(uint8_t GroupName ,  uint8_t PinNumber , uint8_t OutputType);

/**
 * @brief  Read logic value from pin
 * @param  GroupName   Port group
 * @param  PinNumber   Pin number
 * @return uint8_t     Pin value (0 or 1)
 */
uint8_t DIO_Read_Pin(uint8_t  GroupName, uint8_t PinNumber);

/**
 * @brief  Toggle pin logic value
 * @param  GroupName   Port group
 * @param  PinNumber   Pin number
 */
void DIO_Toggle_Pin(uint8_t GroupName , uint8_t PinNumber);

/**
 * @brief  Set direction for whole port (8 pins)
 * @param  GroupName        Port group
 * @param  DirecationValue  Port direction (0x00 input, 0xFF output, or mixed)
 */
void DIO_Direction_Group(uint8_t GroupName , uint8_t DirecationValue);

/**
 * @brief  Write value to whole port
 * @param  GroupName     Port group
 * @param  OutputValue   Port value (0x00..0xFF)
 */
void DIO_Write_Group(uint8_t GroupName ,  uint8_t OutputValue);

/**
 * @brief  Read value from whole port
 * @param  GroupName   Port group
 * @return uint8_t     Port value
 */
uint8_t DIO_Read_Group(uint8_t  GroupName);

#endif /*_DIO_INTERFACE_H_*/
