/**
 * @file     DIO_Interface.h
 * @author   Dev. Hozifa Ahmed (hozifasedik@gmail.com)
 * @author   Rev. Naira Mohamed (naira.mohammed.76@gmail.com)
 * @brief    Digital Input/Output (DIO) Driver Interface    
 * @details  Provides APIs for configuring and controlling DIO pins and ports
 * @version  0.2
 * @date     2025-08-21
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#include <stdint.h>



/* ------------------- APIs ------------------- */

/**
 * @defgroup DIO_Driver DIO Driver
 * @brief Digital Input/Output Driver APIs
 * @{
 */

/**
 * @brief  Set pin direction (input/output)
 * @param  GroupName      Port group (GroupA, GroupB, GroupC, GroupD)
 * @param  PinNumber      Pin number (0..7)
 * @param  DirectionState Direction (DIO_Input or DIO_Output)
 * @return void
 */

void DIO_Direction_Pin(uint8_t GroupName , uint8_t PinNumber , uint8_t DirectionState);

/**
 * @brief  Write logic value to pin (high/low)
 * @param  GroupName   Port group
 * @param  PinNumber   Pin number
 * @param  OutputType  Output value (DIO_Low, DIO_High)
 * @return void
 */

void DIO_Write_Pin(uint8_t GroupName ,  uint8_t PinNumber , uint8_t OutputType);

/**
 * @brief  Read logic value from pin
 * @param  GroupName   Port group
 * @param  PinNumber   Pin number
 * @return uint8_t     Pin value (0 or 1)
 * @retval 0 Pin is in low state
 * @retval 1 Pin is in high state
 */

uint8_t DIO_Read_Pin(uint8_t  GroupName, uint8_t PinNumber);

/**
 * @brief  Toggle pin logic value
 * @param  GroupName   Port group
 * @param  PinNumber   Pin number
 * @return void
 */

void DIO_Toggle_Pin(uint8_t GroupName , uint8_t PinNumber);

/**
 * @brief  Set direction for whole port (8 pins)
 * @param  GroupName        Port group
 * @param  DirectionValue   Port direction (0x00 input, 0xFF output, or mixed)
 * @return void
 */

void DIO_Direction_Group(uint8_t GroupName , uint8_t DirectionValue);

/**
 * @brief  Write value to whole port
 * @param  GroupName     Port group
 * @param  OutputValue   Port value (0x00..0xFF)
 * @return void
 */

void DIO_Write_Group(uint8_t GroupName ,  uint8_t OutputValue);

/**
 * @brief  Read value from whole port
 * @param  GroupName   Port group
 * @return uint8_t     Port value (0x00..0xFF)
 */

uint8_t DIO_Read_Group(uint8_t  GroupName);

/** @} */ // End of DIO_Driver group

#endif /*_DIO_INTERFACE_H_*/
