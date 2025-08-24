/**
 * @file     ZoneConfig.h
 * @author   Developer  Mohammed Atif      (Email: medoatifatif@gmail.com)
 * @author   <Reviewer>
 * @brief 
 * @version   0.1
 * @date      2025-08-15
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#ifndef _ZONECONFIG_H_
#define _ZONECONFIG_H_


/**
 * @defgroup Relay_Config Relay Configuration
 * @brief Macros for relay zones and pin mapping.
 *
 * These macros define the maximum number of zones, the relay control group,
 * and the relay pin configuration per zone.
 * @{
 */
#define MaxZones    4

#define Relays_Group   GroupC

#define Zone1_RelayPin  1
#define Zone2_RelayPin  3
#define Zone3_RelayPin  5
#define Zone4_RelayPin  7

#define Zones_Relay_Pin {Zone1_RelayPin, Zone2_RelayPin, Zone3_RelayPin, Zone4_RelayPin}
/**@}*/

#endif /* _ZONECONFIG_H_ */