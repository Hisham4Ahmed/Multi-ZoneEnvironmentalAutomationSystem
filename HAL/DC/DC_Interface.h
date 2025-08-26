/**
 * @file     DC_Interface.h
 * @author   Developer: MohamedDiaa Mohammeddiaato@gmail.com
 * @author   Reviewer:    
 * @brief 
 * @version   0.1
 * @date      2025-08-15
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#ifndef _DC_INTERFACE_H_
#define _DC_INTERFACE_H_
#include <stdint.h>
#include "../../Common/ZoneConfig.h"
#include "../../Common/Macro.h"
#include "DC_Config.h"

void hFan_Init(uint8_t ZoneNumber);
void hFan_On(uint8_t ZoneNumber);
void hFan_Off(uint8_t ZoneNumber);


#endif /*_DC_INTERFACE_H_*/
