/**
 * @file     LM35_Interface.h
 * @author   Developer : Mohammed Atif
 * @author   Reviewer  : Mohammed Diaa
 * @brief 
 * @version   0.1
 * @date      2025-08-31
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _LM35_INTERFACE_H_
#define _LM35_INTERFACE_H_

#include <stdint.h>

void hLm35_Init(uint8_t ZoneNumber);
int8_t hLm35_GetTemp(uint8_t ZoneNumber);

#endif /*_LM35_INTERFACE_H_*/
