/**
 * @file     DIO_Private.h
 * @author   Dev. Hozifa Ahmed (hozifasedik@gmail.com)
 * @author   Rev. Naira Mohamed (naira.mohammed.76@gmail.com)
 * @brief    Private macros and definitions for Digital I/O (DIO) driver
 * @details  Contains internal definitions and constants used by DIO driver
 * @version  0.2
 * @date     2025-08-21
 * 
 * @copyright Copyright (c) 2025 , Gestell Company
 */

#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_

#include <stdint.h>

/* ================== Group Macros ================== */
/**
 * @defgroup DIO_Groups Port Groups
 * @brief Port group identifiers
 * @{
 */

#define GroupA   1    /**< Port A */
#define GroupB   2    /**< Port B */
#define GroupC   3    /**< Port C */
#define GroupD   4    /**< Port D */

/** @} */ // End of DIO_Groups group


/* ================== Pin Macros ================== */
/**
 * @defgroup DIO_Pins Pin Numbers
 * @brief Pin numbers for each port
 * @{
 */

#define Pin0       0  /**< Pin 0 */
#define Pin1       1  /**< Pin 1 */
#define Pin2       2  /**< Pin 2 */
#define Pin3       3  /**< Pin 3 */
#define Pin4       4  /**< Pin 4 */
#define Pin5       5  /**< Pin 5 */
#define Pin6       6  /**< Pin 6 */
#define Pin7       7  /**< Pin 7 */

/** @} */ // End of DIO_Pins group


/* ================== Direction Macros ================== */
/**
 * @defgroup DIO_Directions Direction Options
 * @brief Pin direction configuration options
 * @{
 */

#define DIO_Input   0    /**< Configure pin as input */
#define DIO_Output  1    /**< Configure pin as output */

/** @} */ // End of DIO_Directions group


/* ================== Value Macros ================== */
/**
 * @defgroup DIO_Values Pin Values
 * @brief Pin logic level states
 * @{
 */

#define DIO_Low     0    /**< Pin low state (0V) */
#define DIO_High    1    /**< Pin high state (Vcc) */

/** @} */ // End of DIO_Values group

#endif /* _DIO_PRIVATE_H_ */
