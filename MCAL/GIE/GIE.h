/**
 * @file     GIE.h
 * @author   Dev. Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @author   Rev. <Reviewer Name>
 * @brief    Global Interrupt Enable (GIE) driver
 * @details  Provides macros for enabling and disabling global interrupts.
 * @version   0.1
 * @date      2025-08-15
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#ifndef _GIE_H_
#define _GIE_H_
#include "../../Common/Config.h"

#if GIE_Driver 


#include "../../Common/Macro.h"
#include "../RegistersAddress.h"



/**
 * @defgroup GIE_Driver Global Interrupt Enable Driver
 * @brief Macros for global interrupt control
 * @{
 */


/**
 * @def I_Bit
 * @brief Global Interrupt Enable bit position in SREG register
 * @details This bit controls the global interrupt enable/disable state
 */
#define I_Bit   7 

/**
 * @def mGIE_Enable
 * @brief Enables global interrupts
 * @details Sets the I-bit in SREG register to enable all interrupts
 * @note Interrupts must be individually enabled in peripheral registers
 */
#define mGIE_Enable()          SetBit(SREG_Reg,I_Bit)

/**
 * @def mGIE_Disable
 * @brief Disables global interrupts
 * @details Clears the I-bit in SREG register to disable all interrupts
 * @note Useful for critical sections where interrupts must be disabled
 */
#define mGIE_Disable()         ClearBit(SREG_Reg,I_Bit)

/** @} */ // End of GIE_Driver group


#endif /* GIE_Driver */


#endif /*_GIE_H_*/