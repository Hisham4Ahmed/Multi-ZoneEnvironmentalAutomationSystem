/**
 * @file      ADC_Program.c
 * @author    Dev. Mohammed Atif (medoatifatif@gmail.com)
 * @author    Rev. Mohammed Diaa (Mohammeddiaato@gmail.com)
 * @brief     ADC driver implementation for AVR microcontrollers.
 * @details   Provides implementation of ADC initialization, conversion and control functions.
 * @version   0.2
 * @date      2025-08-15
 * @copyright Copyright (c) 2025 , Gestell Company
 */

#include "../../Common/Config.h"
#if ADC_Driver

#include "ADC_Interface.h"

/**
 * @fn mADC_Init
 * @brief Initializes ADC peripheral with configured settings
 * @details Configures:
 *          - Interrupt enable/disable based on ADC_Interrupt_Status
 *          - Voltage reference from Volt_Ref_Select
 *          - Operation mode (single/auto trigger)
 *          - Auto trigger source (if applicable)
 *          - Result adjustment (right-justified)
 *          - Clock prescaler from ADC_PrescalerSelection
 *          - Finally enables ADC
 * @return void
 */
void mADC_Init(void) {
    /* Configure interrupt setting */
    #if ADC_Interrupt_Status == Enabled 
        SetBit(ADCSRA_Reg, ADIE_Bit);
    #elif ADC_Interrupt_Status == Disabled 
        ClearBit(ADCSRA_Reg, ADIE_Bit);
    #endif

    /* Configure voltage reference */
    ADMUX_Reg &= ADMUX_Reg_REFSnBits_Mask;
    ADMUX_Reg |= Volt_Ref_Select;
      
    /* Configure operation mode */
    #if ADC_ModeSelect == SingleMode
        ClearBit(ADCSRA_Reg, ADATE_Bit);
    #elif ADC_ModeSelect == AutoTriggerMode 
        SetBit(ADCSRA_Reg, ADATE_Bit);
        /* Configure auto trigger source */
        SFIOR_Reg &= SFIOR_RegBitMask;
        SFIOR_Reg |= (ADC_TriggerSrcSelection << 5);
    #endif
        
    /* Configure result adjustment (right-justified) */
    ClearBit(ADMUX_Reg, ADLAR_Bit);
        
    /* Configure clock prescaler */
    ADCSRA_Reg &= ADCSRA_RegBitMask;
    ADCSRA_Reg |= ADC_PrescalerSelection;    
    
    /* Enable ADC */
    SetBit(ADCSRA_Reg, ADEN_Bit);
}

/**
 * @fn mADC_SingleModeConversion
 * @brief Performs single conversion on specified channel
 * @param Channel ADC channel number (0-7)
 * @return uint16_t 10-bit conversion result
 * @note Blocks until conversion completes
 * @warning ADC must be initialized before calling
 */
uint16_t mADC_SingleModeConversion(uint8_t Channel) {
    /* Select and configure channel */
    Channel &= ChannelBitMask;
    ADMUX_Reg &= ADMUX_Reg_MUXnBits_Mask; 
    ADMUX_Reg |= Channel;
    
    /* Start conversion */
    SetBit(ADCSRA_Reg, ADSC_Bit);

    /* Wait for conversion complete */
    while (GetBit(ADCSRA_Reg, ADIF_Bit) == FlagDown){}
    
    /* Clear interrupt flag if interrupts disabled */
    #if ADC_Interrupt_Status == Disabled
        ClearFlag(ADCSRA_Reg, ADIF_Bit);
    #endif

    /* Return conversion result */
    return ADCData_Reg;    
}

/**
 * @fn     mADC_ReadValue
 * @brief  Reads last converted value from data register
 * @return uint16_t Last conversion result
 * @note   Does not start new conversion
 */
uint16_t mADC_ReadValue(void) {
    return ADCData_Reg;
}

/**
 * @fn mADC_Disable
 * @brief Disables ADC peripheral
 * @details Reduces power consumption by disabling ADC
 * @note Recommended before sleep modes
 * @return void
 */
void mADC_Disable(void) {
    ClearBit(ADCSRA_Reg, ADEN_Bit);
}

/**
 * @fn mADC_Enable
 * @brief Enables ADC peripheral
 * @details Powers up ADC for operation
 * @note ADC must be initialized first
 * @return void
 */
void mADC_Enable(void) {
    SetBit(ADCSRA_Reg, ADEN_Bit);
}

/**
 * @fn __vector_16
 * @brief ADC Conversion Complete ISR
 * @details Handles ADC conversion complete interrupts
 * @note Vector 16 in interrupt table
 * @return void
 */
void __vector_16(void) {
    /* User-defined interrupt handling code here */
}

#endif /* ADC_Driver */