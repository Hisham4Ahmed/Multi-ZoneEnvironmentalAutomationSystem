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

/**
 * @details : Fixed Resistance Used Must Be 10K ohm , Vcc Must be 5V , there's 2 ways of connection
 * @param : these are the parameters of LDR R1 ------> R in 0.1 lux must be equal 127410 ohm , Gamma = 0.8582
 * 
 * 1 -    this is called With_Vcc in this driver
 * 
 *               Vcc
 *                |
 *               LDR 
 *                |----- ADC
 *                R->10K ohm               
 *                |
 *               GND 
 * ---------------------------------------------------
 * 2- this is called With_GND in this driver 
 * 
 *               Vcc
 *                |
 *                R->10K ohm 
 *                |----- ADC
 *               LDR              
 *                |
 *               GND 
 * 
 * -------------------------------------------------------
 * 
 */
#define LDR_Connection_Type            With_Vcc

/**
 * @def LDR_With_Vcc_Edge_point 
 * @brief How Many miliVolts are going to adc when LDR is in With_Vcc
 */

#define LDR_With_Vcc_Edge_point        1793

/**
 * @def LDR_With_GND_Edge_point 
 * @brief How Many miliVolts are going to adc when LDR is in With_GND
 */

#define LDR_With_GND_Edge_point        3201


#endif /*_LCD_CONFIG_H_*/