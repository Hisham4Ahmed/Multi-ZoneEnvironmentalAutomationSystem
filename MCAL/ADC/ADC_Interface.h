/**
 * @file     ADC_Interface.h
 * @author   Mohammed Atif
 * @author   Mohammed Diaa
 * @brief 
 * @version   0.1
 * @date      2025-08-15
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
uint16_t mADC_SingleModeConversion(uint8_t Channel);

#endif /*_ADC_INTERFACE_H_*/