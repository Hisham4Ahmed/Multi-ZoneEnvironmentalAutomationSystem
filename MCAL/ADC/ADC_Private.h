/**
 * @file     ADC_Private.h
 * @author   Mohammed Atif
 * @author   Mohammed Diaa
 * @brief 
 * @version   0.1
 * @date      2025-08-15
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#ifndef  _ADC_PRIVATE_H_
#define  _ADC_PRIVATE_H_

#define ADC_INT_Enabled     1
#define ADC_INT_Disabled    0

#define AutoTriggerMode     1
#define SingleMode          0


/**
 * @enum ADC_Reference_t
 * @brief Voltage reference selections for the ADC.
 */
typedef enum {
    /**
     * @brief AREF pin, internal Vref turned off.
     * External voltage reference must be applied to the AREF pin.
     */
    ADC_REF_AREF   = 0,
    /**
     * @brief AVCC with external capacitor at AREF pin.
     */
    ADC_REF_AVCC   = 1,
    /**
     * @brief Internal 2.56V reference with external capacitor at AREF pin.
     */
    ADC_REF_INT256 = 3
} ADC_Reference_t;

/**
 * @enum ADC_PrescalerOptions_t
 * @brief Clock Division Factors
 */
typedef enum { 
    ADC_Prescaler_2 = 1,
    ADC_Prescaler_4,
    ADC_Prescaler_8,
    ADC_Prescaler_16,
    ADC_Prescaler_32,
    ADC_Prescaler_64,
    ADC_Prescaler_128
} ADC_PrescalerOptions_t;

/**
 * @enum ADC_AutoTriggerSource_t
 * @brief Clock Division Factors
 */
typedef enum { 
    ADC_TRIG_FREE_RUN,
    ADC_TRIG_ANALOG_COMP,
    ADC_TRIG_EXT_INT0,
    ADC_TRIG_TC0_COMP,
    ADC_TRIG_TC0_OVF,
    ADC_TRIG_TC1_COMPB,
    ADC_TRIG_TC1_OVF,
    ADC_TRIG_TC1_CAPT
} ADC_AutoTriggerSource_t;

/**
 * @brief ADMUX Register bit definitions.
 *
 * These macros define the bit positions within the ADMUX register:
 * - 0–4 Bits : Analog Channel and Gain Selection Bits.
 * - 5 Bit    : ADC Left Adjust Result.
 * - 6:7 Bits : Reference Selection bits.
 */
#define MUX0_Bit    0
#define MUX1_Bit    1
#define MUX2_Bit    2
#define MUX3_Bit    3
#define MUX4_Bit    4
#define ADLAR_Bit   5
#define REFS0_Bit   6
#define REFS1_Bit   7

/**
 * @brief ADCSRA Register bit definitions.
 *
 * These macros define the bit positions within the ADMUX register:
 * - 7 Bit    : ADC Enable.
 * - 6 Bit    : ADC Start Conversion.
 * - 5 Bit    : ADC ADC Auto Trigger Enable.
 * - 4 Bit    : ADC Interrupt Flag.
 * - 3 Bit    : ADC Interrupt Enable.
 * - 0:2 Bits : ADC Prescaler Select Bits.
 */
#define ADPS0_Bit   0
#define ADPS1_Bit   1
#define ADPS2_Bit   2
#define ADIE_Bit    3
#define ADIF_Bit    4
#define ADATE_Bit   5
#define ADSC_Bit    6
#define ADEN_Bit    7

/**
 * @brief SFIOR Register bit definitions.
 *
 * These macros define the bit positions within the ADMUX register:
 * - 7:5 Bits : ADC Auto Trigger Source
 */
#define ADTS0_Bit   5
#define ADTS1_Bit   6
#define ADTS2_Bit   7

#endif  /*_ADC_PRIVATE_H_*/