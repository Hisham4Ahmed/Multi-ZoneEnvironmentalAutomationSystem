/**
 * @file      LED_Config.h
 * @author    Developer : Hozifa Ahmed
 * @author    Reviewer :  Ahmed Ashraf
 * @brief     LED Driver General Configuration
 * @version   0.3
 * @date      2025-08-28
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#ifndef _LED_CONFIG_H_
#define _LED_CONFIG_H_

#include "LED_Private.h"
#include "../../Common/ZoneConfig.h"

/** 
 * @def LED_CONNECTION
 *  @brief Select LED connection type (LED_ACTIVE_HIGH / LED_ACTIVE_LOW)
 */
#define LED_CONNECTION   LED_ACTIVE_HIGH

/**
 *  @def LED_TOTAL_NUMBER
 *  @brief Total number of LEDs (zones supported)
 */
#define LED_TOTAL_NUMBER   4

/* --------- LED Array Mapping --------- */
static const LED_ConfigType LED_Array[LED_TOTAL_NUMBER] =
{
    {ZONE1_LED_PORT, ZONE1_LED_PIN},
    {ZONE2_LED_PORT, ZONE2_LED_PIN},
    {ZONE3_LED_PORT, ZONE3_LED_PIN},
    {ZONE4_LED_PORT, ZONE4_LED_PIN}
};


#endif  /*_LED_CONFIG_H_*/