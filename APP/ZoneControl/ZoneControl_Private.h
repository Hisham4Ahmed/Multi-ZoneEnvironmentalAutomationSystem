/**
 * @file     ZoneControl_Private.h
 * @author   Developer: Mohammed Atif   "medoatifatif@gmail.com"
 * @author   Reviewer:  Hesham Ahmed    (Hisham4Ahmed@gmail.com)
 * @brief    Private Macros
 * @version  0.1
 * @date     2025-09-14
 *
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _ZONECONTROL_PRIVATE_H_
#define _ZONECONTROL_PRIVATE_H_

/**
 * @def Zone_Num_1 
 * @brief define the minimum number of zones
 */
#define MinZones  1

/**
 * @def Zone_Num_1 
 * @brief define the minimum number of zones
 */
#define No_Commands  0xFF


/** 
 * @defgroup Fan_Speed_Formula_Constants
 * @brief Constants used for calculating fan speed within specific threshold
 * @{
 */

#define Min_Temp_Threshold   22   /**< Minimum temperature threshold (°C) */
#define Max_Temp_Threshold   35   /**< Maximum temperature threshold (°C) */
#define Max_Fan_Speed        100  /**< Maximum fan speed (%) */
#define Min_Fan_Speed        0    /**< Minimum fan speed (%) */
#define Fan_Speed_Temp_Range 13   /**< Range of temperatures that map to fan speed changes (°C) */
#define Full_Scale           100  /**< Full scale percentage (100%) */

/** @} */ // end of Fan_Speed_Formula_Constants


#endif /* _ZONECONTROL_PRIVATE_H_ */