/**
 * @file     Relay_Interface.h
 * @author   Developer Mohammed Atif      (Email: medoatifatif@gmail.com)
 * @author   Reviewer Naira Mohammed
 * @brief    Relay interface header containing function prototypes and required header files.
 * @version  0.1
 * @date     2025-08-24
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _RELAY_INTERFACE_H_
#define _RELAY_INTERFACE_H_

#include <stdint.h>

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Private.h"

#include "../../Common/ZoneConfig.h"


/**
 * @fn    void hRelay_Init
 * @brief Initializes the relay for a given zone.
 * @param ZoneNumber Zone number to which the relay belongs.
 */
void hRelay_Init(uint8_t ZoneNumber);

/**
 * @fn    void hRelay_On
 * @brief Turns ON the relay for a given zone.
 * @param ZoneNumber Zone number of the relay to be switched ON
 */
void hRelay_On(uint8_t ZoneNumber);

/**
 * @fn    void hRelay_Off
 * @brief Turns OFF the relay for a given zone.
 * @param ZoneNumber Zone number of the relay to be switched OFF
 */
void hRelay_Off(uint8_t ZoneNumber);

/**
 * @fn    void hRelay_Toggle
 * @brief Toggle the relay for a given zone.
 * @param ZoneNumber Zone number of the relay to be Toggled
 */
void hRelay_Toggle(uint8_t ZoneNumber);

#endif /*_RELAY_INTERFACE_H_*/