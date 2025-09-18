/**
 * @file     LDR_Interface.h
 * @author   Developer : Ahmed Ashraf
 * @author   Reviewer  : Mohamed Atif
 * @brief  This Driver to Set and initialize LDR 
 * @version   0.1
 * @date      2025-08-31
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#ifndef _LDR_INTERFACE_H_
#define _LDR_INTERFACE_H_

#include <stdint.h>
#include "../../Common/Macro.h"
#include "../../MCAL/RegistersAddress.h"
#include "LDR_Config.h"
#include "LDR_Private.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../Common/ZoneConfig.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Private.h"
/**
 * @fn hLDR_Init
 * @brief This Function is used to initialize LDR According to it's Zone
 * @param ZoneNumber Zone number indicates which zone initialize 
 */
void hLDR_Init(uint8_t ZoneNumber) ;

/**
 * @fn hLDR_GetLightStatus
 * @brief Function Used to get the Status of ldr (Morning , Evening)
 * @param ZoneNumber Zone number indicates which zone to get the status from
 */
uint8_t hLDR_GetLightStatus(uint8_t ZoneNumber);

#endif /*_LCD_INTERFACE_H_*/