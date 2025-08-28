/**
 * @file      LED_Private.h
 * @author    Developer : Hozifa Ahmed
 * @author    Reviewer :  Ahmed Ashraf
 * @brief     Private macros and helpers for LED Driver
 * @version   0.3
 * @date      2025-08-28
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#ifndef _LED_PRIVATE_H_
#define _LED_PRIVATE_H_


/**
 *  @def LED_ACTIVE_HIGH
 *  @brief LED connected as source (ON = High, OFF = Low)
 */
#define LED_ACTIVE_HIGH   1

/**
 *  @def LED_ACTIVE_LOW
 *  @brief LED connected as sink (ON = Low, OFF = High)
 */
#define LED_ACTIVE_LOW    0


/* --------- Struct for LED Mapping --------- */
typedef struct 
{
    uint8_t Port;   /**< LED Port (GroupA..GroupD) */
    uint8_t Pin;    /**< LED Pin  (0..7) */
} LED_ConfigType;



#endif  /*_LED_PRIVATE_H_*/