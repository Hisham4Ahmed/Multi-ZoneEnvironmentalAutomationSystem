/**
 * @file     ADC_Program.c
 * @author   Mohammed Atif
 * @author   Mohammed Diaa
 * @brief 
 * @version   0.1
 * @date      2025-08-15
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
    ADCSRA_Reg &= (0xF8);
    ADCSRA_Reg |= ADC_PrescalerSelection;    
    
    // ADC Enable 
        // ADEN in ADCSRA
    SetBit(ADCSRA_Reg, ADEN_Bit);
}

uint16_t mADC_SingleModeConversion(uint8_t Channel) {
    // Select Channel
        // MUX4:0 in ADMUX
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