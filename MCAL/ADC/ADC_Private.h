/**
 * @file      ADC_Private.h
 * @author    Dev. Mohammed Atif (medoatifatif@gmail.com)
 * @author    Rev. Mohammed Diaa (Mohammeddiaato@gmail.com)
 * @brief     Internal definitions and register mappings for ADC driver.
 * @details   Contains private enums, macros and bit definitions for ADC registers.
 * @version   0.2
 * @date      2025-08-15
 * @copyright Copyright (c) 2025 , Gestell Company
 */

#ifndef _ADC_PRIVATE_H_
#define _ADC_PRIVATE_H_

/**
 * @defgroup ADC_Private ADC Private Definitions
 * @brief Internal definitions for ADC driver implementation
 * @{
 */

/** Operation mode definitions */
#define AutoTriggerMode     1 /**< Auto trigger mode */
#define SingleMode          0 /**< Single conversion mode */

/**
 * @enum ADC_Reference_t
 * @brief Voltage reference selection options
 */
typedef enum {
    /**
     * @var ADC_REF_AREF
     * @brief AREF pin, internal Vref turned off
     */
    ADC_REF_AREF   = 0,
    
    /**
     * @var ADC_REF_AVCC
     * @brief AVCC with external capacitor at AREF pin
     */
    ADC_REF_AVCC   = 1,
    
    /**
     * @var ADC_REF_INT256
     * @brief Internal 2.56V reference with external capacitor at AREF pin
     */
    ADC_REF_INT256 = 3
} ADC_Reference_t;

/**
 * @enum ADC_PrescalerOptions_t
 * @brief Clock prescaler options
 */
typedef enum { 
    ADC_Prescaler_2 = 1, /**< Division factor 2 */
    ADC_Prescaler_4,     /**< Division factor 4 */
    ADC_Prescaler_8,     /**< Division factor 8 */
    ADC_Prescaler_16,    /**< Division factor 16 */
    ADC_Prescaler_32,    /**< Division factor 32 */
    ADC_Prescaler_64,    /**< Division factor 64 */
    ADC_Prescaler_128    /**< Division factor 128 */
} ADC_PrescalerOptions_t;

/**
 * @enum ADC_AutoTriggerSource_t
 * @brief Auto trigger source options
 */
typedef enum { 
    ADC_TRIG_FREE_RUN,    /**< Free running mode */
    ADC_TRIG_ANALOG_COMP, /**< Analog comparator */
    ADC_TRIG_EXT_INT0,    /**< External interrupt 0 */
    ADC_TRIG_TC0_COMP,    /**< Timer0 compare match */
    ADC_TRIG_TC0_OVF,     /**< Timer0 overflow */
    ADC_TRIG_TC1_COMPB,   /**< Timer1 compare match B */
    ADC_TRIG_TC1_OVF,     /**< Timer1 overflow */
    ADC_TRIG_TC1_CAPT     /**< Timer1 capture event */
} ADC_AutoTriggerSource_t;

/** @defgroup ADC_Register_Bits ADC Register Bit Definitions
 * @brief Bit positions and masks for ADC registers
 * @{
 */

/**
 * @def MUX0_Bit
 * @brief Analog channel selection bit 0
 */
#define MUX0_Bit    0

/**
 * @def MUX1_Bit
 * @brief Analog channel selection bit 1
 */
#define MUX1_Bit    1

/**
 * @def MUX2_Bit
 * @brief Analog channel selection bit 2
 */
#define MUX2_Bit    2

/**
 * @def MUX3_Bit
 * @brief Analog channel selection bit 3
 */
#define MUX3_Bit    3

/**
 * @def MUX4_Bit
 * @brief Analog channel selection bit 4
 */
#define MUX4_Bit    4

/**
 * @def ADLAR_Bit
 * @brief Left adjust result bit
 */
#define ADLAR_Bit   5

/**
 * @def REFS0_Bit
 * @brief Reference selection bit 0
 */
#define REFS0_Bit   6

/**
 * @def REFS1_Bit
 * @brief Reference selection bit 1
 */
#define REFS1_Bit   7

/**
 * @def ADPS0_Bit
 * @brief Prescaler select bit 0
 */
#define ADPS0_Bit   0

/**
 * @def ADPS1_Bit
 * @brief Prescaler select bit 1
 */
#define ADPS1_Bit   1

/**
 * @def ADPS2_Bit
 * @brief Prescaler select bit 2
 */
#define ADPS2_Bit   2

/**
 * @def ADIE_Bit
 * @brief Interrupt enable bit
 */
#define ADIE_Bit    3

/**
 * @def ADIF_Bit
 * @brief Interrupt flag bit
 */
#define ADIF_Bit    4

/**
 * @def ADATE_Bit
 * @brief Auto trigger enable bit
 */
#define ADATE_Bit   5

/**
 * @def ADSC_Bit
 * @brief Start conversion bit
 */
#define ADSC_Bit    6

/**
 * @def ADEN_Bit
 * @brief ADC enable bit
 */
#define ADEN_Bit    7

/**
 * @def ADTS0_Bit
 * @brief Auto trigger source bit 0
 */
#define ADTS0_Bit   5

/**
 * @def ADTS1_Bit
 * @brief Auto trigger source bit 1
 */
#define ADTS1_Bit   6

/**
 * @def ADTS2_Bit
 * @brief Auto trigger source bit 2
 */
#define ADTS2_Bit   7

/**
 * @def ADMUX_Reg_REFSnBits_Mask
 * @brief Mask for reference selection bits
 */
#define ADMUX_Reg_REFSnBits_Mask 0xFC

/**
 * @def ADMUX_Reg_MUXnBits_Mask
 * @brief Mask for channel selection bits
 */
#define ADMUX_Reg_MUXnBits_Mask 0xE0

/**
 * @def SFIOR_RegBitMask
 * @brief Mask for SFIOR register
 */
#define SFIOR_RegBitMask 0x1F

/**
 * @def ADCSRA_RegBitMask
 * @brief Mask for prescaler bits
 */
#define ADCSRA_RegBitMask 0xF8

/**
 * @def ChannelBitMask
 * @brief Mask for channel number
 */
#define ChannelBitMask 0x07

/** @} */ // End of ADC_Register_Bits group
/** @} */ // End of ADC_Private group

#endif /* _ADC_PRIVATE_H_ */