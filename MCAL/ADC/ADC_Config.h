/**
 * @file      ADC_Config.h
 * @author    Dev. Mohammed Atif (medoatifatif@gmail.com)
 * @author    Rev. Mohammed Diaa (Mohammeddiaato@gmail.com)
 * @brief     User configuration file for ADC driver.
 * @details   Contains user-configurable settings for ADC operation.
 * @version   0.2
 * @date      2025-08-15
 * @copyright Copyright (c) 2025 , Gestell Company
 */

#ifndef _ADC_CONFIG_H_
#define _ADC_CONFIG_H_

#include "ADC_Private.h"

/**
 * @defgroup ADC_Config ADC Configuration
 * @brief User-configurable settings for ADC driver
 * @{
 */

/**
 * @def Volt_Ref_Select
 * @brief Selects voltage reference for ADC
 * @details Options:
 *          - ADC_REF_AREF: External reference on AREF pin
 *          - ADC_REF_AVCC: AVCC with external capacitor
 *          - ADC_REF_INT256: Internal 2.56V reference
 */
#define Volt_Ref_Select ADC_REF_AVCC

/**
 * @def ADC_Interrupt_Status
 * @brief Enable/disable ADC conversion complete interrupt
 * @details Options:
 *          - Enabled: Enable ADC interrupt
 *          - Disabled: Disable ADC interrupt
 * @note Global interrupts must also be enabled to use ADC interrupts
 */
#define ADC_Interrupt_Status    Disabled

/**
 * @def ADC_ModeSelect
 * @brief Selects ADC operation mode
 * @details Options:
 *          - SingleMode: Single conversion mode
 *          - AutoTriggerMode: Auto trigger mode
 */
#define ADC_ModeSelect    SingleMode

/**
 * @def ADC_TriggerSrcSelection
 * @brief Selects auto trigger source
 * @details Options:
 *          - ADC_TRIG_FREE_RUN: Free running mode
 *          - ADC_TRIG_ANALOG_COMP: Analog comparator
 *          - ADC_TRIG_EXT_INT0: External interrupt 0
 *          - ADC_TRIG_TC0_COMP: Timer0 compare match
 *          - ADC_TRIG_TC0_OVF: Timer0 overflow
 *          - ADC_TRIG_TC1_COMPB: Timer1 compare match B
 *          - ADC_TRIG_TC1_OVF: Timer1 overflow
 *          - ADC_TRIG_TC1_CAPT: Timer1 capture event
 * @note Only applicable when ADC_ModeSelect is AutoTriggerMode
 */
#if ADC_ModeSelect == AutoTriggerMode
    #define ADC_TriggerSrcSelection ADC_TRIG_FREE_RUN
#endif

/**
 * @def ADC_PrescalerSelection
 * @brief Selects clock division factor
 * @details Options:
 *          - ADC_Prescaler_2: Division factor 2
 *          - ADC_Prescaler_4: Division factor 4
 *          - ADC_Prescaler_8: Division factor 8
 *          - ADC_Prescaler_16: Division factor 16
 *          - ADC_Prescaler_32: Division factor 32
 *          - ADC_Prescaler_64: Division factor 64
 *          - ADC_Prescaler_128: Division factor 128
 */
#define ADC_PrescalerSelection  ADC_Prescaler_4

/** @} */ // End of ADC_Config group

#endif /* _ADC_CONFIG_H_ */