/**
 * @file     LDR_Private.h
 * @author   Developer : Ahmed Ashraf
 * @author   Reviewer  : Mohamed Atif
 * @brief  This Driver to Set and initialize LDR 
 * @version   0.1
 * @date      2025-08-31
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _LDR_PRIVATE_H_
#define _LDR_PRIVATE_H_
/**
 * @def Morning
 * @def Evening
 * @brief Light Status Options
 */
#define Morning             1
#define Evening             0


/**
 * @def LDR_Edge_Point
 * @brief LDR Edge Point (if Exceeded -> Morning) , else -> Evening
 * @note if the Edge_Point Changed Calculations needs to be done again
 */

#define LDR_Edge_Point      56


#endif /*_LCD_PRIVATE_H_*/