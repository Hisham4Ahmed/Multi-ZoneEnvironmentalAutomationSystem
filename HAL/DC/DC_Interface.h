/**
 * @file     DC_Interface.h
 * @author      Developer: Mohamed Diaa "mohammeddiaato@gmail.com"
 * @author      Reviewer: Mohammed Atef "medoatifatif@gmail.com"
 * @brief       DC_Motor Interfacing functions 
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
/**
 * @fn      void hFan_Init(uint8_t ZoneNumber)
 * @brief   Initialization Function OF the DC motor Zones
 * @return  NONE
 */
void hFan_Init(uint8_t ZoneNumber);
/**
 * @fn      void hFan_ON(uint8_t ZoneNumber)
 * @brief    Turning ON the DC motor Zones
 * @return  NONE
 */
void hFan_On(uint8_t ZoneNumber);
/**
 * @fn      void hFan_OFF(uint8_t ZoneNumber)
 * @brief   Turning OFF the DC motor Zones
 * @return  NONE
 */
void hFan_Off(uint8_t ZoneNumber);

#define Fan_MAXSpeed   500


#endif /*_DC_INTERFACE_H_*/
