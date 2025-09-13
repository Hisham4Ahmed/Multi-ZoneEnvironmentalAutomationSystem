/**
 * @file      Config.h
 * @author    Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief     This file contains the configurations for the Drivers 
 * @version   0.1
 * @date      2025-08-30
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */

#ifndef _CONFIG_H_
#define _CONFIG_H_
#include "Macro.h"
/**
 * @defgroup DriverState  
 * @brief This is to enable or disable the Drivers
 * @details Enabled : To enable the Driver
 * @details Disabled : To disable the Driver
 * @{
 */
#define ADC_Driver          Enabled
#define DIO_Driver          Enabled
#define EXTI_Driver         Enabled
#define GIE_Driver          Enabled
#define TIMER0_Driver       Enabled
#define TIMER1_Driver       Enabled
#define TIMER2_Driver       Enabled
#define UART_Driver         Enabled

#define Btn_Driver          Enabled
#define HC05_Driver         Disabled
#define LCD_Driver          Enabled
#define LDR_Driver          Disabled
#define LED_Driver          Enabled
#define LM35_Driver         Disabled
#define Relay_Driver        Enabled
#define DC_Driver           Enabled

#define ModeControl_App     Enabled

/** @} */


#endif /*_CONFIG_H_*/
