/**
 * @file     T0_Private.h
 * @author   Ahmed Ashraf
 * @author   Mohamed Atif
 * @brief 
 * @version   0.1
 * @date      2025-08-17
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


 
#ifndef _T0_PRIVATE_H_
#define _T0_PRIVATE_H_


/**
 * @defgroup Timer0_Bits Timer0 Bit Positions
 * @brief Bit positions for Timer0 control and interrupt registers.
 * @{
 */

/**
 * @def CS00_Bit
 * @brief Clock Select bit 0 for Timer0 (prescaler configuration).
 */
#define CS00_Bit  0

/**
 * @def CS01_Bit
 * @brief Clock Select bit 1 for Timer0 (prescaler configuration).
 */
#define CS01_Bit  1

/**
 * @def CS02_Bit
 * @brief Clock Select bit 2 for Timer0 (prescaler configuration).
 */
#define CS02_Bit  2

/**
 * @def WGM01_Bit
 * @brief Waveform Generation Mode bit 1 for Timer0.
 */
#define WGM01_Bit 3

/**
 * @def WGM00_Bit
 * @brief Waveform Generation Mode bit 0 for Timer0.
 */
#define WGM00_Bit 6

/**
 * @def COM00_Bit
 * @brief Compare Output Mode bit 0 for Timer0.
 */
#define COM00_Bit 4

/**
 * @def COM01_Bit
 * @brief Compare Output Mode bit 1 for Timer0.
 */
#define COM01_Bit 5

/**
 * @def TOIE0_Bit
 * @brief Timer0 Overflow Interrupt Enable bit.
 */
#define TOIE0_Bit 0

/**
 * @def OCIE0_Bit
 * @brief Output Compare Match Interrupt Enable bit for Timer0.
 */
#define OCIE0_Bit 1

/**
 * @def TOV0_Bit
 * @brief Timer0 Overflow Flag bit.
 */
#define TOV0_Bit 0

/**
 * @def OCF0_Bit
 * @brief Output Compare Flag bit for Timer0.
 */
#define OCF0_Bit 1

/** @} */ // End of Timer0_Bits group


/**
 * @defgroup Timer0_Prescaler Timer0 Prescaler Settings
 * @brief Prescaler values for Timer0 clock source selection.
 * @{
 */

/**
 * @def Timer0Disabled
 * @brief Disables Timer0 clock source.
 */
#define Timer0Disabled 0

/**
 * @def Timer0Prescaller_1
 * @brief Timer0 clock source: No prescaling (F_CPU).
 */
#define Timer0Prescaller_1 1

/**
 * @def Timer0Prescaller_8
 * @brief Timer0 clock source: F_CPU / 8.
 */
#define Timer0Prescaller_8 2

/**
 * @def Timer0Prescaller_64
 * @brief Timer0 clock source: F_CPU / 64.
 */
#define Timer0Prescaller_64 3

/**
 * @def Timer0Prescaller_256
 * @brief Timer0 clock source: F_CPU / 256.
 */
#define Timer0Prescaller_256 4

/**
 * @def Timer0Prescaller_1024
 * @brief Timer0 clock source: F_CPU / 1024.
 */
#define Timer0Prescaller_1024 5

/**
 * @def Timer0ExternalCLK_Falling
 * @brief Timer0 external clock source on falling edge.
 */
#define Timer0ExternalCLK_Falling 6

/**
 * @def Timer0ExternalCLK_Rising
 * @brief Timer0 external clock source on rising edge.
 */
#define Timer0ExternalCLK_Rising 7

/** @} */ // End of Timer0_Prescaler group


/**
 * @defgroup Timer0_PWM_Modes Timer0 PWM Output Modes
 * @brief Output polarity options for Fast PWM mode.
 * @{
 */

/**
 * @def Non_inverting
 * @brief Sets Timer0 output to non-inverting mode.
 *
 * @details Output clears on compare match, sets at BOTTOM.
 */
#define Non_inverting 1

/**
 * @def inverting
 * @brief Sets Timer0 output to inverting mode.
 *
 * @details Output sets on compare match, clears at BOTTOM.
 */
#define inverting 2

/** @} */ // End of Timer0_PWM_Modes group

#endif /*_T0_PRIVATE_H_*/