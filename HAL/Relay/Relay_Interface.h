/**
 * @file     Relay_Interface.h
 * @author   Mohammed Atif      (Email: medoatifatif@gmail.com)
 * @author   <Reviewer>
 * @brief 
 * @version   0.1
 * @date      2025-08-15
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _RELAY_INTERFACE_H_
#define _RELAY_INTERFACE_H_

#include <stdint.h>

void hRelay_Init(uint8_t ZoneNumber);
void hRelay_On(uint8_t ZoneNumber);
void hRelay_Off(uint8_t ZoneNumber);

#endif /*_RELAY_INTERFACE_H_*/