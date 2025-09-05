/**
 * @file     LM35_Config.h
 * @author   Developer : Mohammed Atif  "medoatifatif@gmail.com:
 * @author   Reviewer  : Mohammed Diaa  "mohammeddiaato@gmail.com"
 * @brief    User configuration file for LM35 sensor driver.
 * @version   0.1
 * @date      2025-08-15
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _LM35_CONFIG_H_
#define _LM35_CONFIG_H_
/**
 * @def LM35_Mode
 * @brief Selects the operating mode for the LM35 temperature sensor.
 * 
 * Possible values:
 * - Basic : Sets the measurement range from 2°C to 150°C
 * - Full_Range : Sets the measurement range from -55°C to 150°C
 */
#define LM35_Mode   Basic

/**
 * @def V_Ref_mV
 * @brief Reference voltage in millivolts used for ADC calculations.
 * 
 * This value should match the actual reference voltage applied to the ADC.
 * For example, 5000 mV corresponds to a 5V reference.
 */
#define V_Ref_mV    5000

#endif /*_LM35_CONFIG_H_*/