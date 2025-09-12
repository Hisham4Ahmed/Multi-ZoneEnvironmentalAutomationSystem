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
#include "DC_Config.h"
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
void hFan_On(uint8_t ZoneNumber,uint16_t Speed);
/**
 * @fn      void hFan_OFF(uint8_t ZoneNumber)
 * @brief   Turning OFF the DC motor Zones
 * @return  NONE
 */
void hFan_Off(uint8_t ZoneNumber);

/**
 * @brief Controls the speed of the DC fan in the specified zone.
 * 
 * This function adjusts the speed of the DC fan based on the requirements
 * for the given zone number. The speed control mechanism may use PWM or other
 * techniques depending on the hardware implementation.
 *
 * @param ZoneNumber The zone number of the fan to control.
 * @return None
 */
void hFan_SpeedControl(uint8_t ZoneNumber,uint16_t RPMSpeed);



#endif /*_DC_INTERFACE_H_*/
