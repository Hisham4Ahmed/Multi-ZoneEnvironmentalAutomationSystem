/**
 * @file     DC_Config.h
 * @author   Mohammed Diaa    (mohammeddiaato@gmail.com)  Developer
 * @author   Hesham Ahmed     (Hisham4Ahmed@gmail.com)    Reviewer
 * @brief    Configurations for DC Motors 
 * @version  0.1
 * @date     2025-09-11
 *
 * @copyright Copyright (c) 2025 , Gestell Company
 */

#ifndef _DC_CONFIG_H_
#define _DC_CONFIG_H_

#include "../../Common/Macro.h"
#include "../../Common/ZoneConfig.h"

/**
 * @def   Fan_MAXSpeed
 * @brief Defines the maximum speed value for the DC fan.
 * @details
 * This value sets the upper limit for the fan speed control, ensuring
 * the fan does not exceed safe operational parameters.
 */
#define Fan_MAXSpeed       200

/**
 * @def   OutPutCompareMatch
 * @brief Sets the output compare match mode for DC motor control.
 * @details
 * This macro defines the compare match mode (e.g., Non_inverting) used for PWM signal generation
 * to control the DC motor output.
 */
#define OutPutCompareMatch  Non_inverting

#endif
