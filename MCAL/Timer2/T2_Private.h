/**
 * @file T2_Private.h
 * @author Mohammed Diaa Developer-> Mohammeddiaato@gmail.com
 * @author Eng.Hesham Ahmed
 * @brief  This File is made for the Private elements of the Timer2 Config file 
 * @version 0.3
 * @date 2025-08-30
 *
 * @copyright Copyright (c) 2025 , Gestell Company
 *
 */

#ifndef _T2_PRIVATE_H_
#define _T2_PRIVATE_H_

/**
 * @def WGM21_Bit
 * @def WGM20_Bit
 * @brief Bit positions for Waveform Generation Mode in Timer2.
 * 
 * These bits control the timer mode such as Fast PWM, Phase Correct PWM, CTC, and Normal.
 */
#define WGM20_Bit   6 /**< Waveform Generation Mode bit 0 */
#define WGM21_Bit   3 /**< Waveform Generation Mode bit 1 */

/**
 * @enum Timer2_WaveGenModes
 * @brief Waveform generation modes for Timer2.
 * 
 * These modes define how Timer2 operates in terms of counting and signal generation.
 */
typedef enum
{
  /**
   * @var 
   * @brief Normal counting mode 
   * */
  Normal        = 0,
  /**
   * @var 
   * @brief Phase Correct PWM mode */
  
  
  PhaseCorrect  = 1,
  /**
   * @var 
   * @brief Clear Timer on Compare Match mode */
  
  
  CTC           = 2,
  /**
   * @var 
   * @brief Fast PWM mode */
  
  
  FastPwm       = 3  
} Timer2_WaveGenModes;

/**
 * @def CS20_Bit
 * @brief Clock Select bit 0 for Timer0 (prescaler configuration).
 */
#define CS20_Bit  0

/**
 * @def CS21_Bit
 * @brief Clock Select bit 1 for Timer0 (prescaler configuration).
 */
#define CS21_Bit  1

/**
 * @def CS22_Bit
 * @brief Clock Select bit 2 for Timer0 (prescaler configuration).
 */
#define CS22_Bit  2


/**
 * @enum Timer2_Prescaller_Set
 * @brief Prescaler settings for Timer2.
 * 
 * These values define the division factor for the timer clock, affecting the frequency of Timer2.
 */
typedef enum
{
  /**
   * @var
   * @brief   Timer stopped (no clock source) 
   * */
  
    NoClockSource   = 0,
    /**
     * @var
     * @brief   No prescaling (direct clock) 
     * */
    
    Prescaller_1    = 1,
    /**
     * @var
     * @brief   Clock divided by 8 
     * */
    
    Prescaller_8    = 2,
    /**
     * @var
     * @brief   Clock divided by 32 
     * */
    
    Prescaller_32   = 3,
    /**
     * @var
     * @brief   Clock divided by 64 
     * */
    
    Prescaller_64   = 4,
    /**
     * @var
     * @brief   Clock divided by 128 
     * */
    
    Prescaller_128  = 5,
    /**
     * @var
     * @brief   Clock divided by 256 
     * */
    
    Prescaller_256  = 6,
    /**
     * @var
     * @brief   Clock divided by 1024 
     * */
    
    Prescaller_1024 = 7 
} Timer2_Prescaller_Set;

/**
 * @def COM00_Bit
 * @brief Compare Output Mode bit 0 for Timer2.
 */
#define COM20_Bit 4

/**
 * @def COM21_Bit
 * @brief Compare Output Mode bit 1 for Timer2.
 */
#define COM21_Bit 5

/**
 * @enum Timer2_COM_FastPWM
 * @brief Compare Output Modes for Fast PWM in Timer2.
 * @details These modes define how the OC2 pin behaves during Fast PWM operation.
 */
typedef enum
{
  /**
   * @var
   * @brief  Normal port operation, OC2 disconnected 
   * */
   NormalOperation = 0, 
  /**
   * @var
   * @brief  Clear OC2 on compare match, set at BOTTOM 
   * */
   NonInverting    = 2, 
  /**
   * @var
   * @brief  Set OC2 on compare match, clear at BOTTOM 
   * */
   Inverting       = 3  
} Timer2_COM_FastPWM;



#endif /*_T2_PRIVATE_H_*/