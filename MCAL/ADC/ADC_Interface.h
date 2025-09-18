/**
 * @file      ADC_Interface.h
 * @author    Dev. Mohammed Atif (medoatifatif@gmail.com)
 * @author    Rev. Mohammed Diaa (Mohammeddiaato@gmail.com)
 * @brief     Public interface for the ADC driver.
 * @details   Provides initialization and communication APIs for ADC peripheral.
 * @version   0.2
 * @date      2025-08-15
 * @copyright Copyright (c) 2025 , Gestell Company
 */

#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_

#include <stdint.h>
#include "../RegistersAddress.h"
#include "../../Common/Macro.h"
#include "ADC_Config.h"

/**
 * @defgroup ADC_Driver ADC Driver
 * @brief APIs for ADC initialization and operations
 * @{
 */

/**
 * @fn mADC_Init
 * @brief Initializes the ADC peripheral with user-defined configurations.
 * @details Configures ADC based on settings in ADC_Config.h including:
 *          - Voltage reference selection
 *          - Interrupt enable/disable
 *          - Operation mode (single/auto trigger)
 *          - Prescaler selection
 *          - Result adjustment
 * @note Must be called before any other ADC function.
 * @return void
 */
void mADC_Init(void);

/**
 * @fn mADC_Disable
 * @brief Disables the ADC peripheral.
 * @details Powers down the ADC to reduce power consumption.
 * @note Recommended to call before entering sleep modes.
 * @return void
 */
void mADC_Disable(void);

/**
 * @fn mADC_Enable
 * @brief Enables the ADC peripheral.
 * @details Powers up the ADC for operation.
 * @note ADC must be initialized before enabling.
 * @return void
 */
void mADC_Enable(void);

/**
 * @fn mADC_SingleModeConversion
 * @brief Performs a single ADC conversion on specified channel.
 * @param Channel ADC input channel number (0-7)
 * @return uint16_t Digital conversion result (10-bit value)
 * @warning ADC must be initialized before calling this function.
 * @note Function blocks until conversion is complete.
 */
uint16_t mADC_SingleModeConversion(uint8_t Channel);

/**
 * @fn mADC_ReadValue
 * @brief Reads the last converted ADC value.
 * @return uint16_t Last conversion result from data register
 * @note Does not start new conversion, returns previous result.
 */
uint16_t mADC_ReadValue(void);

/**
 * @fn __vector_16
 * @brief ADC Conversion Complete Interrupt Service Routine.
 * @note This ISR handles ADC conversion complete interrupts.
 *       Corresponds to vector 16 in interrupt table.
 * @return void
 */
void __vector_16(void) __attribute__((signal));

/** @} */ // End of ADC_Driver group

#endif /* _ADC_INTERFACE_H_ */