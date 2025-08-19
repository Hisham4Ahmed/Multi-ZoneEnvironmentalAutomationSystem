/**
 * @file     ADC_Program.c
 * @author   Mohammed Atif
 * @author   Mohammed Diaa
 * @brief    ADC driver implementation for AVR microcontrollers (ATmega32).
 * @version  0.1
 * @date     2025-08-15
 *
 * This file provides the implementation of the ADC driver, including:
 * - Initialization of the ADC with user-defined configurations
 * - Single conversion mode function
 * - ADC disable function
 * - ADC Conversion Complete Interrupt Service Routine (ISR)
 * 
 * The functions are designed to work with configuration macros defined
 * in the corresponding header files.
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#include "ADC_Interface.h"

/**
 * @fn void mADC_Init(void)
 * @brief Initialize the ADC peripheral with user-defined configurations.
 *
 * This function sets up the ADC based on configuration macros:
 * - ADC interrupt enable/disable (ADC_INT_Enabled, ADC_INT_Disabled)
 * - Voltage reference source (Volt_Ref_Select)
 * - Operating mode (single conversion or auto trigger)
 * - Auto trigger source ( ADC_TriggerSrcSelection, only if auto trigger is enabled)
 * - Result adjustment (left/right justified)
 * - Prescaler selection (ADC_PrescalerSelection)
 * - Finally, the ADC is enabled.
 *
 * @return void
 */
void mADC_Init() {
    // ADC Interrupt 
    #if ADC_Interrupt_Status == Enabled 
    
        SetBit(ADCSRA_Reg, ADIE_Bit);
    #elif ADC_Interrupt_Status == Disabled 
        ClearBit(ADCSRA_Reg, ADIE_Bit);
    #endif

    // Select Ref source
        // REFSn bits in the ADMUX
    ADMUX_Reg &= (0xFC);
    ADMUX_Reg |= Volt_Ref_Select;
    
    // Select Mode : single/auto trigger mode
        // ADATE in ADCSRA
    #if ADC_ModeSelect == SingleMode
        ClearBit(ADCSRA_Reg, ADATE_Bit);
    #elif ADC_ModeSelect == AutoTriggerMode 
        SetBit(ADCSRA_Reg, ADATE_Bit);
        // Set Auto Trigger Source
        SFIOR_Reg &= (0x1F);
        SFIOR_Reg |= (ADC_TriggerSrcSelection << 5);
    #endif
        
    // Right/Left Adjust  
        // ADLAR bit in ADMUX.
    ClearBit(ADMUX_Reg, ADLAR_Bit);
        
    // Prescaler
        //  ADPS bits in ADCSRA
    ADCSRA_Reg &= (0xF8); // okay 
    ADCSRA_Reg |= ADC_PrescalerSelection;    
    
    // ADC Enable 
        // ADEN in ADCSRA
    SetBit(ADCSRA_Reg, ADEN_Bit);
}

/**
 * @fn uint16_t mADC_SingleModeConversion(uint8_t Channel)
 * 
 * @brief Performs a single ADC conversion on a given channel.
 *
 * This function selects the desired ADC channel, starts a single 
 * conversion, waits until the conversion is complete, and then 
 * returns the digital result.
 *
 * @param Channel ADC input channel number (0–7).
 *                Only the lower 3 bits are considered.
 *
 * @return uint16_t 
 *         The digital value of the conversion (10-bit result).
 *
 * @note The function clears the ADC interrupt flag (ADIF) manually 
 *       if ADC interrupts are disabled.
 *
 * @warning The ADC must be initialized and enabled before calling 
 *          this function.
 */
uint16_t mADC_SingleModeConversion(uint8_t Channel) {
    // Select Channel (Must be set before starting conversion)
        // MUX4:0 in ADMUX
    /**
     * @author  Mohammed Diaa
     * @bug you made it single ended only in this way and You are using magic number
     * better to make the number ==0x1F to make all mux availble Do not use magic Number you can call it bit mask for channel and 0xE0 bitmaskforADMUX
     *  */ 
    Channel &= (0x07); 
    ADMUX_Reg &= (0xE0); 
    ADMUX_Reg |= Channel;
    // Start Conversion
        // ADSC in ADCSRA
    SetBit(ADCSRA_Reg, ADSC_Bit);

    while (GetBit(ADCSRA_Reg, ADIF_Bit) == FlagDown){}
    
    // Clear flag
    #if ADC_Interrupt_Status == Disabled
        ClearFlag(ADCSRA_Reg, ADIF_Bit);
    #endif

    // Read ADCH and ADCL
    return ADCData_Reg;    
}

/**
 * @fn void mADC_Disable(void)
 *
 * @brief Disable the ADC .
 *        Clears the ADEN_Bit in ADCSRA_Reg to disable the ADC.
 * 
 * @note The ADC does not consume power when ADEN is cleared, so it is
 *       recommended to disable the ADC before entering sleep modes
 *       to save power.
 */
void mADC_Disable() {
    ClearBit(ADCSRA_Reg, ADEN_Bit);
}

/**
 * @fn void __vector_16(void)
 * @brief ADC Conversion Complete Interrupt Service Routine.
 *
 * This ISR is triggered when the ADC finishes a conversion.
 * It handles the ADC interrupt for channel readings or 
 * any user-defined ADC-related actions.
 *
 * @note This corresponds to vector 16 in the interrupt table.
 */
void __vector_16(void) {
    // Action
}