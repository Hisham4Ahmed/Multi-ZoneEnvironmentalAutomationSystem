/**
 * @file     ADC_Interface.h
 * @author   Mohammed Atif
 * @author   Mohammed Diaa
 * @brief    Public interface for the ADC driver.
 * @version  0.1
 * @date     2025-08-15
 * 
 * This header file provides the function prototypes for the ADC driver.
 * Application code should include this file to:
 * - Initialize the ADC with user-defined configurations
 * - Perform single conversion mode readings
 * - Enable or disable the ADC peripheral
 * - Handle ADC Conversion Complete interrupts via the ISR prototype
 * 
 * @note This is the only ADC header file that should be included
 *       in application-level code. Other headers 
 *       (Private, Config) are used internally by the driver.
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_

#include <stdint.h>
#include "../RegistersAddress.h"
#include "../../Common/Macro.h"
#include "ADC_Config.h"
  
void mADC_Init();
void mADC_Disable();
void mADC_Enable();
uint16_t mADC_SingleModeConversion(uint8_t Channel);
uint16_t mADC_ReadValue();
void __vector_16(void) __attribute__((signal));

#endif /*_ADC_INTERFACE_H_*/