/**
 * @file     ADC_Config.h
 * @author   Mohammed Atif
 * @author   Mohammed Diaa
 * @brief     
 * @version   0.1
 * @date      2025-08-15
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _ADC_CONFIG_H_
#define _ADC_CONFIG_H_

#include "ADC_Private.h"

/**
 * @def Volt_Ref_Select
 * @brief Selects the voltage reference for the ADC.
 *
 * Options (set this macro to one of them):
 * - ADC_REF_AREF   : AREF pin, internal Vref turned off.
 * - ADC_REF_AVCC   : AVCC with external capacitor at AREF pin.
 * - ADC_REF_INT256 : Internal 2.56V reference with capacitor at AREF pin.
 */
#define Volt_Ref_Select ADC_REF_AVCC

/**
 * @def ADC_Interrupt_Status
 * @brief Enable/Disable  ADC Interrupt
 *
 * Options (set this macro to one of them):
 * - Enabled   : Enable ADC Interrupt
 * - Disabled  : Disable ADC Interrupt
 * 
 * @note also enable GIE to use ADC Interrupt
 */
#define ADC_Interrupt_Status    Disabled

/**
 * @def ADC_ModeSelect
 * @brief Select ADC Mode
 *
 * Options (set this macro to one of them):
 * - SingleMode   : Using the singlemode function for a single conversion
 * - AutoTriggerMode  : Start Conversion Based on Auto Trigger Source
 */
#define ADC_ModeSelect    SingleMode

/**
 * @def ADC_TriggerSrcSelection 
 * @brief Select Auto Trigger Source
 * 
 * @note Must enable Auto Trigger Mode to select the source
 *
 * Options (set this macro to one of them):
 * - ADC_TRIG_FREE_RUN    : Free Running mode
 * - ADC_TRIG_ANALOG_COMP : Analog Comparator
 * - ADC_TRIG_EXT_INT0    : External Interrupt Request 0
 * - ADC_TRIG_TC0_COMP    : Timer/Counter0 Compare Match
 * - ADC_TRIG_TC0_OVF     : Timer/Counter0 Overflow
 * - ADC_TRIG_TC1_COMPB   : Timer/Counter1 Compare Match B
 * - ADC_TRIG_TC1_OVF     : Timer/Counter1 Overflow
 * - ADC_TRIG_TC1_CAPT    : Timer/Counter1 Capture Event
 */
#if ADC_ModeSelect == AutoTriggerMode
    #define ADC_TriggerSrcSelection ADC_TRIG_FREE_RUN
#endif

/**
 * @def ADC_PrescalerSelection
 * @brief Select Clock Division Factor
 *
 * Options (set this macro to one of them):
 * - ADC_Prescaler_2   : Division Factor is 2
 * - ADC_Prescaler_4   : Division Factor is 4
 * - ADC_Prescaler_8   : Division Factor is 8
 * - ADC_Prescaler_16  : Division Factor is 16
 * - ADC_Prescaler_32  : Division Factor is 32
 * - ADC_Prescaler_64  : Division Factor is 64
 * - ADC_Prescaler_128 : Division Factor is 128
 */
#define ADC_PrescalerSelection  ADC_Prescaler_4

#endif /*_ADC_CONFIG_H_*/