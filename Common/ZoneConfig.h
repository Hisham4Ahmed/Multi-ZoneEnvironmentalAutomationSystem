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

#include "MCAL/DIO/DIO_Private.h"

#define MaxZones    4

/**
 * @brief these macros define button group and pin connected in microcontroller.
 */
#define Zones_BtnGroup   GroupD
#define Zones_BtnPin     Pin2

/* ------------------- Zone 1 ------------------- */
/** @brief Zone 1 LED connection */
#define ZONE1_LED_PORT   GroupC
#define ZONE1_LED_PIN    0

/* ------------------- Zone 2 ------------------- */
/** @brief Zone 2 LED connection */
#define ZONE2_LED_PORT   GroupC
#define ZONE2_LED_PIN    2

/* ------------------- Zone 3 ------------------- */
/** @brief Zone 3 LED connection */
#define ZONE3_LED_PORT   GroupC
#define ZONE3_LED_PIN    4

/* ------------------- Zone 4 ------------------- */
/** @brief Zone 4 LED connection */
#define ZONE4_LED_PORT   GroupC
#define ZONE4_LED_PIN    6


/**
 * @defgroup Relay_Config Relay Configuration
 * @brief Macros for relay zones and pin mapping.
 * @author Developer Mohammed Atif (Email: medoatifatif@gmail.com)
 * These macros define the maximum number of zones, the relay control group,
 * and the relay pin configuration per zone.
 * @{
 */


#define Relays_Group   GroupC

#define Zone1_RelayPin  Pin1
#define Zone2_RelayPin  Pin3
#define Zone3_RelayPin  Pin5
#define Zone4_RelayPin  Pin7

#define Zones_Relay_Pin {Zone1_RelayPin, Zone2_RelayPin, Zone3_RelayPin, Zone4_RelayPin}
/**@}*/

#endif /* _ZONECONFIG_H_ */