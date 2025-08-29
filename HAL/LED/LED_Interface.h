/**
 * @file      LED_Interface.h
 * @author    Developer : Hozifa Ahmed
 * @author    Reviewer :  Ahmed Ashraf
 * @brief     High Level LED Driver Interface
 * @version   0.2
 * @date      2025-08-27
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_

#include <stdint.h>

/* ------------------- APIs ------------------- */

/**
 * @brief  Initialize LED pin direction for specific Zone
 * @param  ZoneNumber   Zone ID (1..4)
 * @retval None
 */

void hLed_Init(uint8_t ZoneNumber);

/**
 * @brief  Turn ON LED for specific Zone
 * @param  ZoneNumber   Zone ID (1..4)
 * @retval None
 */

void hLed_On(uint8_t ZoneNumber);

/**
 * @brief  Turn OFF LED for specific Zone
 * @param  ZoneNumber   Zone ID (1..4)
 * @retval None
 */

void hLed_Off(uint8_t ZoneNumber);


#endif /*_LED_INTERFACE_H*/