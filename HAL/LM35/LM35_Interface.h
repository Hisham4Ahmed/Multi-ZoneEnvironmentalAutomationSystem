/**
 * @file     LM35_Interface.h
 * @author   Developer : Mohammed Atif  "medoatifatif@gmail.com:
 * @author   Reviewer  : Mohammed Diaa  "mohammeddiaato@gmail.com"
 * @brief    Functions prototypes to configure LM35 and obtain temperature in Celsius.
 * @version   0.1
 * @date      2025-08-31
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _LM35_INTERFACE_H_
#define _LM35_INTERFACE_H_

#include <stdint.h>

#include "../../Common/ZoneConfig.h"
#include "LM35_Config.h"
#include "LM35_Private.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"

/**
 * @fn void hLm35_Init(uint8_t ZoneNumber)
 * @param ZoneNumber Zone number of the LM35 sensor.
 * 
 * @brief Initializes the LM35 temperature sensor for a given zone.
 * 
 * @details
 * Configures the pin connected to the LM35 sensor as input
 * and initializes the ADC module for analog-to-digital conversion.
 *
 */
void hLm35_Init(uint8_t ZoneNumber);

/**
 * @fn int8_t hLm35_GetTemp(uint8_t ZoneNumber)
 * @param ZoneNumber The LM35 zone index (1-based).
 * 
 * @brief Gets the temperature in Celsius from the LM35 sensor.
 * 
 * @details
 * Reads the ADC value from the specified zone, converts it to
 * millivolts, and then converts that to temperature in Celsius
 * (10 mV per °C). If the ADC reading hasn't changed since the
 * last call, the cached temperature value is returned.
 * Also returns 255 as error code if the ZoneNumber was invalid.
 * 
 * @return Temperature in Celsius (int8_t).
 */
int8_t hLm35_GetTemp(uint8_t ZoneNumber);

#endif /*_LM35_INTERFACE_H_*/
