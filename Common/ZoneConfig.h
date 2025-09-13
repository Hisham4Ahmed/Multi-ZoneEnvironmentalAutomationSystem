/**
 * @file      ZoneConfig.h
 * @author    Developer : Hozifa Ahmed
 * @author    Developer : Mohammed Atif      (Email: medoatifatif@gmail.com)
 * @author    Reviewer  :  Ahmed Ashraf
 * @brief     Zone Hardware Mapping Configuration (LED pins) 
 * @version   0.2
 * @date      2025-08-27
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#ifndef _ZONECONFIG_H_
#define _ZONECONFIG_H_



#include "Macro.h"
#include "../MCAL/DIO/DIO_Private.h"
 
#define MaxZones         4
#define Relays_Group     GroupC
#define Zones_BtnGroup   GroupD
#define Zones_BtnPin     Pin2

/** 
  * @defgroup  Zones Mapping
  * @def   Relay_Config Relay Configuration
  * @brief Macros for relay zones and pin mapping.
  * @author Developer Mohammed Atif (Email: medoatifatif@gmail.com)
  * These macros define the maximum number of zones, the relay control group,
  * and the relay pin configuration per zone.
  * @def  Zone1_DCGroup
  * @def  Zone2_DCGroup
  * @def  Zone3_DCGroup
  * @def  Zone4_DCGroup
  * @brief Groups on MCU of the Pins we use on different Zones 
  * @author Mohamed Diaa "mohammeddiaato@gmail.com"
  * @def Zone1_DCpin
  * @def Zone2_DCpin
  * @def Zone3_DCpin
  * @def Zone4_DCpin
  * @brief Pins of MCU we use on different zones of the PWM
  * @author Mohamed Diaa "mohammeddiaato@gmail.com"
  * @def Zone1Num
  * @def Zone2Num
  * @def Zone3Num
  * @def Zone4Num
  * @brief Zone numbers to use them in the functions directly
  * @author Mohamed Diaa "mohammeddiaato@gmail.com"
*/
/* ------------------- Zone 1 ------------------- */
#define Zone1Num         1
#define ZONE1_LED_PORT   GroupC
#define ZONE1_LED_PIN    0
#define Zone1_RelayPin   Pin1
#define Zone1_DCpin      Pin3
#define Zone1_DCGroup    GroupB

/* ------------------- Zone 2 ------------------- */
#define Zone2Num         2
#define ZONE2_LED_PORT   GroupC
#define ZONE2_LED_PIN    2
#define Zone2_RelayPin   Pin3
#define Zone2_DCpin      Pin5
#define Zone2_DCGroup    GroupD


/* ------------------- Zone 3 ------------------- */
#define Zone3Num         3
#define ZONE3_LED_PORT   GroupC
#define ZONE3_LED_PIN    4
#define Zone3_RelayPin   Pin5
#define Zone3_DCpin      Pin4
#define Zone3_DCGroup    GroupD

/* ------------------- Zone 4 ------------------- */
/** @brief Zone 4 LED connection */
#define Zone4Num         4 
#define ZONE4_LED_PORT   GroupC
#define ZONE4_LED_PIN    6
#define Zone4_RelayPin   Pin7
#define Zone4_DCpin      Pin7
#define Zone4_DCGroup    GroupD








/**
 * @def Zones_DCGroups
 * @def Zones_DCPins
 * @brief Collecting the Pins into one entity to use them freely
 * @author Mohamed Diaa "mohammeddiaato@gmail.com"
 * */
#define Zones_DCGroups   {Zone1_DCGroup,Zone2_DCGroup,Zone3_DCGroup,Zone4_DCGroup}
#define Zones_DCPins     {Zone1_DCpin,Zone2_DCpin,Zone3_DCpin,Zone4_DCpin}


#define Zones_Relay_Pin {Zone1_RelayPin, Zone2_RelayPin, Zone3_RelayPin, Zone4_RelayPin}

#endif /* _ZONECONFIG_H_ */