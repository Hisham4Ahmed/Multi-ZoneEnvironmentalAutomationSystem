/**
 * @file     ZoneConfig.h
 * @author   <Developer>
 * @author   <Reviewer>
 * @brief 
 * @version   0.1
 * @date      2025-08-15
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#ifndef _ZONECONFIG_H_
#define _ZONECONFIG_H_
/*--------------------------------------------------------------*/
#include "../MCAL/DIO/DIO_Interface.h"

// DC MOTOR(Fans) Macros
/**
 * @def Zone1_DCpin
 * @def Zone1_DCpin
 * @def Zone1_DCpin
 * @def Zone1_DCpin
 * @brief Pins of MCU we use on different zones of the PWM
 * @author Mohamed Diaa "mohammeddiaato@gmail.com"
 *  */
#define Zone1_DCpin    Pin3
#define Zone2_DCpin    Pin5
#define Zone3_DCpin    Pin4
#define Zone4_DCpin    Pin7

/**
 * @def Zone1_DCGroup
 * @def Zone1_DCGroup
 * @def Zone1_DCGroup
 * @def Zone1_DCGroup
 * @brief Groups on MCU of the Pins we use on different Zones 
 * @author Mohamed Diaa "mohammeddiaato@gmail.com"
 *  */
#define Zone1_DCGroup  GroupB
#define Zone2_DCGroup  GroupD
#define Zone3_DCGroup  GroupD
#define Zone4_DCGroup  GroupD



/**
 * @def Zones_DCGroups
 * @def Zones_DCPins
 * @brief Collecting the Pins into one entity to use them freely
 * @author Mohamed Diaa "mohammeddiaato@gmail.com"
 * */
#define Zones_DCGroups   {Zone1_DCGroup,Zone2_DCGroup,Zone3_DCGroup,Zone4_DCGroup}
#define Zones_DCPins     {Zone1_DCpin,Zone2_DCpin,Zone3_DCpin,Zone4_DCpin}
/*--------------------------------------------------------------*/
/**
 * @def Zone1Num
 * @def Zone2Num
 * @def Zone3Num
 * @def Zone4Num
 * @def NumberOfZones 
 * @brief Zone numbers to use them in the functions directly
 * @author Mohamed Diaa "mohammeddiaato@gmail.com"
 */
#define Zone1Num 1
#define Zone2Num 2
#define Zone3Num 3
#define Zone4Num 4
#define NumberOfZones 4
#endif /* _ZONECONFIG_H_ */