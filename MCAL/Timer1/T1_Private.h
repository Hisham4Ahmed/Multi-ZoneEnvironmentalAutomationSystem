/**
 * @file T1_Private.h
 * @author Mohammed Diaa    (mohammeddiaato@gmail.com)  Developer 
 * @author Hesham Ahmed     (Hisham4Ahmed@gmail.com)    Reviewer
 * @brief This File is made for writing Private Data of Timer1
 * @version 0.3
 * @date 2025-08-30
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */

#ifndef _T1_PRIVATE_H_
#define _T1_PRIVATE_H_

/**
 * @enum  TCCR1A_Bits
 * @brief Bit positions for TCCR1A register configuration.
 * @details each bit is used for a kind of signal generating weather it is a PWM or non PWM modes 
 *          selecting right options comes from datasheet of AVR Atmega32 to know what options the MCU 
 *          provides.
 * @note    here we are working on FastPWM mode
 */
typedef enum
{
    /**
     * @var
     * @brief Compare Output Mode for Channel A, bit 1 
     */
    COM1A1_Bit = 7, 
 

    /**
     * @var
     * @brief Compare Output Mode for Channel A, bit 0 
     */
    COM1A0_Bit = 6, 


    /**
     * @var
     * @brief Compare Output Mode for Channel B, bit 1 
     */
    COM1B1_Bit = 5, 
 

    /**
     * @var
     * @brief Compare Output Mode for Channel B, bit 0 
     */
    COM1B0_Bit = 4, 


    /**
     * @var
     * @brief Waveform Generation Mode bit 1 
     */
    WGM11_Bit  = 1, 
   

    /**
     * @var
     * @brief Waveform Generation Mode bit 0
     */
    WGM10_Bit  = 0  
   

} TCCR1A_Bits;

/**
 * @enum  TCCR1B_Bits
 * @brief Bit positions for TCCR1B register configuration.
 * 
 * @details each bit is used for a kind of signal generating weather it is a PWM or non PWM modes 
 *          selecting right options comes from datasheet of AVR Atmega32 to know what options the MCU 
 *          provides.
 * @note    here we are working on FastPWM mode
 */
typedef enum
{
    /**
     * @var WGM13_Bit 
     * @brief Waveform Generation Mode bit 3 
     */
    WGM13_Bit = 4, 

    /**
     * @var WGM12_Bit 
     * @brief Waveform Generation Mode bit 2
     */
    
    WGM12_Bit = 3, 

    /**
     * @var CS12_Bit 
     * @brief Clock Select bit 2
     */
    CS12_Bit  = 2, 

    /**
     * @var CS11_Bit 
     * @brief Clock Select bit 1
     */
    CS11_Bit  = 1, 

    /**
     * @var CS10_Bit 
     * @brief Clock Select bit 0 
     */
    CS10_Bit  = 0  
} TCCR1B_Bits;

/**
 * @brief Prescaler settings for Timer1 clock source.
 * 
 * These values determine the division factor applied to the system clock
 * before feeding it to Timer1.
 */
typedef enum
{
    /**
     * @var
     * @brief Timer stopped (no clock source)
     * */

    T1_NoClockSource      = 0, 
    

    /**
     * @var
     * @brief No prescaling (direct clock) 
     * */

    T1_Prescaller_1       = 1, 
   

    /**
     * @var
     * @brief Clock divided by 8 
     * */

    T1_Prescaller_8       = 2, 


    /**
     * @var
     * @brief Clock divided by 64 
     * */

    T1_Prescaller_64      = 3, 


    /**
     * @var
     * @brief Clock divided by 256 
     * */

    T1_Prescaller_256     = 4, 


    /**
     * @var
     * @brief Clock divided by 1024 
     * */

    T1_Prescaller_1024    = 5, 


    /**
     * @var
     * @brief External clock on T1 pin, falling edge */

    Ext_Source_Falling = 6, 
   

    /**
     * @var
     * @brief External clock on T1 pin, rising edge */

    Ext_Source_Rising  = 7  


} Timer1_Prescaller_Set;

/**
 * @def     T1_FastPwm
 * @brief   FastPWM Waveform generation mode for Timer1.
 * @note    we are using fast pwm mode
 * you can find more modes if you want in the datasheet of avr atmega32 at timer1 section
 */
#define T1_FastPwm   14  


/**
 * @enum    Timer1_COM_FastPWM
 * @brief   Compare Output Modes for Fast PWM operation.
 * 
 * @details These modes define the behavior of the output compare pins (OC1A/OC1B)
 *          during Fast PWM operation.
 */
typedef enum
{
    /**
     * @var       T1_NormalOperation  
     * @brief     Normal port operation, OC1A/OC1B disconnected 
     * */
    T1_NormalOperation = 0,

    /**
     * @var       T1_NonInverting  
     * @brief     Clear OC1A/OC1B on compare match, set at BOTTOM 
     * */
    T1_NonInverting    = 2,

    /**
     * @var       T1_Inverting  
     * @brief     Set OC1A/OC1B on compare match, clear at BOTTOM 
     * */
    T1_Inverting       = 3 

} Timer1_COM_FastPWM;

#endif /*_T1_PRIVATE_H_*/