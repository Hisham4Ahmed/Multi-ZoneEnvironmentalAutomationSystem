/**
 * @file     DIO_Private.h
 * @author   Hozifa Ahmed
 * @author   Naira Mohamed
 * @brief    Private macros for Digital I/O (DIO) driver.
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
 * @brief Port group identifiers
 */
#define GroupA   1    /**< Port A */
#define GroupB   2    /**< Port B */
#define GroupC   3    /**< Port C */
#define GroupD   4    /**< Port D */

/* ================== Pin Macros ================== */
/**
 * @brief Pin numbers for each port
 */
#define Pin0       0
#define Pin1       1
#define Pin2       2
#define Pin3       3
#define Pin4       4
#define Pin5       5
#define Pin6       6
#define Pin7       7

/* ================== Direction Macros ================== */
/**
 * @brief Pin direction options
 */
#define DIO_Input   0    /**< Configure pin as input */
#define DIO_Output  1    /**< Configure pin as output */

/* ================== Value Macros ================== */
/**
 * @brief Pin value states
 */
#define DIO_Low     0    /**< Pin low state (0V) */
#define DIO_High    1    /**< Pin high state (Vcc) */

#endif /* _DIO_PRIVATE_H_ */
