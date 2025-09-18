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
 * @brief Light Status Option indicating morning
 */
#define Morning                           1
/**
 * @def     Evening
 * @brief   Light Status Option indicating evening
 */

#define Evening                           0


/**
 *   @def With_Vcc
 *   @brief A macro defines ways of connecting LDR 
 *   @details 
 *   With_Vcc — LDR connected to Vcc, resistor to GND:
 * 
 *     Vcc
 *      |
 *     LDR
 *      |----- ADC
 *     R = 10K ohm
 *      |
 *     GND
 * 
 *
 *
 */
#define With_Vcc                          1
/**
 *   @def With_GND
 *   @brief A macro defines ways of connecting LDR
 *   @details 
 *   With_GND — Resistor connected to Vcc, LDR to GND:
 * 
 *     Vcc
 *      |
 *     R = 10K ohm
 *      |----- ADC
 *     LDR
 *      |
 *     GND
 */
#define With_GND                          0




#endif /*_LCD_PRIVATE_H_*/