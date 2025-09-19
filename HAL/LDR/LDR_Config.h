/**
 * @file     LDR_Config.h
 * @author   Developer : Ahmed Ashraf
 * @author   Reviewer  : Mohamed Atif
 * @brief  This Driver to Set and initialize LDR 
 * @version   0.1
 * @date      2025-08-31
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _LDR_CONFIG_H_
#define _LDR_CONFIG_H_

/*------------------- LDR Configuration --------------------------*/


/**
 * @def     LDR_Connection_Type
 * @brief   Selects the wiring method used for LDR voltage divider
 * @details
 * Two supported connection types:
 * 
 * 1. With_Vcc — LDR connected to Vcc, resistor to GND:
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
 * 2. With_GND — Resistor connected to Vcc, LDR to GND:
 * 
 *     Vcc
 *      |
 *     R = 10K ohm
 *      |----- ADC
 *     LDR
 *      |
 *     GND
 * 
 * @note Read these notes:
 *              1- Fixed resistance must be 10K ohm, Vcc must be 5V
 *              2- LDR parameters: R at 0.1 lux = 127410 ohm, Gamma = 0.8582
 *              3- If parameters change, measure voltage in millivolts from ADC,
 *                 multiply by Vcc (in mV) × UL / 1023, and adjust edge point in config
 *              4- ADC reading can be verified using a voltmeter or printed as:
 *                 `ADC * 5000UL / 1023` on LCD
 */
#define LDR_Connection_Type            With_Vcc

/**
 * @def   LDR_With_Vcc_Edge_point 
 * @brief How Many miliVolts are going to adc when LDR is in With_Vcc
 */

#define LDR_With_Vcc_Edge_point        1808  //1808-> in proteus , 1793 -> in simulide

/**
 * @def   LDR_With_GND_Edge_point 
 * @brief How Many miliVolts are going to adc when LDR is in With_GND
 */

#define LDR_With_GND_Edge_point        3196   //3196-> in proteus  , 3201 in simulide


#endif /*_LCD_CONFIG_H_*/