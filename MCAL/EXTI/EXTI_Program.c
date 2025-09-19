/**
 * @file      EXTI_Program.c
 * @author    Dev. Mohammed Diaa (Mohammeddiaato@gmail.com)
 * @author    Rev. Hozifa Ahmed (hozifasedik@gmail.com)
 * @brief     Implementation of External Interrupt (EXTI) driver.
 * @details   Provides functions for enabling external interrupts and handling interrupt service routines.
 * @version   0.2
 * @date      2025-08-21
 * @copyright Copyright (c) 2025 , Gestell Company
 */

#include "../../Common/Config.h"

#if EXTI_Driver

#include "EXTI_Interface.h"
#include "../RegistersAddress.h"
#include "../../Common/Macro.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"
#include <stdint.h>

/** @addtogroup EXTI_Private
 * @{
 */

/**
 * @var mEXTI0_Global
 * @brief Callback function pointer for INT0
 * @note Must be set using mEXTI0_CallBack() before enabling interrupt
 */
static void (*mEXTI0_Global)(void) = Null;

/**
 * @var mEXTI1_Global
 * @brief Callback function pointer for INT1
 * @note Must be set using mEXTI1_CallBack() before enabling interrupt
 */
static void (*mEXTI1_Global)(void) = Null;

/**
 * @var mEXTI2_Global
 * @brief Callback function pointer for INT2
 * @note Must be set using mEXTI2_CallBack() before enabling interrupt
 */
static void (*mEXTI2_Global)(void) = Null;

/** @} */ // End of EXTI_Private group

/**
 * @fn mEXTI0_CallBack
 * @brief Sets callback function for INT0 interrupt
 * @param PF Pointer to callback function
 * @return void
 * @warning If PF is NULL, no callback is set
 */
void mEXTI0_CallBack(void (*PF)(void))
{
    if (PF != Null)
    {
        mEXTI0_Global = PF;
    }
}

/**
 * @fn mEXTI1_CallBack
 * @brief Sets callback function for INT1 interrupt
 * @param PF Pointer to callback function
 * @return void
 * @warning If PF is NULL, no callback is set
 */
void mEXTI1_CallBack(void (*PF)(void))
{
    if (PF != Null)
    {
        mEXTI1_Global = PF;
    }
}

/**
 * @fn mEXTI2_CallBack
 * @brief Sets callback function for INT2 interrupt
 * @param PF Pointer to callback function
 * @return void
 * @warning If PF is NULL, no callback is set
 */
void mEXTI2_CallBack(void (*PF)(void))
{
    if (PF != Null)
    {
        mEXTI2_Global = PF;
    }
}

/**
 * @fn mEXTI0_Enable
 * @brief Enables the External Interrupt INT0
 * @return void
 * @note Configures sense control based on SenseControl_INT0 setting
 */
void mEXTI0_Enable(void)
{
    /* Set Specific Interrupt Enable for INT0 */
    SetBit(GICR_Reg, INTF0);

    /* Configure sense control for INT0 */
    #if SenseControl_INT0 == SC_Choice_Low
        ClearBit(MCUCR_Reg, ISC00_Bit);
        ClearBit(MCUCR_Reg, ISC01_Bit);
    #elif SenseControl_INT0 == SC_Choice_AnyChange
        SetBit(MCUCR_Reg, ISC00_Bit);
        ClearBit(MCUCR_Reg, ISC01_Bit);
    #elif SenseControl_INT0 == SC_Choice_Falling
        ClearBit(MCUCR_Reg, ISC00_Bit);
        SetBit(MCUCR_Reg, ISC01_Bit);
    #elif SenseControl_INT0 == SC_Choice_Rising
        SetBit(MCUCR_Reg, ISC00_Bit);
        SetBit(MCUCR_Reg, ISC01_Bit);
    #endif
}

/**
 * @fn mEXTI1_Enable
 * @brief Enables the External Interrupt INT1
 * @return void
 * @note Configures sense control based on SenseControl_INT1 setting
 */
void mEXTI1_Enable(void)
{
    /* Set Specific Interrupt Enable for INT1 */
    SetBit(GICR_Reg, INTF1);

    /* Configure sense control for INT1 */
    #if SenseControl_INT1 == SC_Choice_Low
        ClearBit(MCUCR_Reg, ISC10_Bit);
        ClearBit(MCUCR_Reg, ISC11_Bit);
    #elif SenseControl_INT1 == SC_Choice_AnyChange
        SetBit(MCUCR_Reg, ISC10_Bit);
        ClearBit(MCUCR_Reg, ISC11_Bit);
    #elif SenseControl_INT1 == SC_Choice_Falling
        ClearBit(MCUCR_Reg, ISC10_Bit);
        SetBit(MCUCR_Reg, ISC11_Bit);
    #elif SenseControl_INT1 == SC_Choice_Rising
        SetBit(MCUCR_Reg, ISC10_Bit);
        SetBit(MCUCR_Reg, ISC11_Bit);
    #endif
}

/**
 * @fn mEXTI2_Enable
 * @brief Enables the External Interrupt INT2
 * @return void
 * @note Configures sense control based on SenseControl_INT2 setting
 * @warning INT2 does not support AnyChange mode
 */
void mEXTI2_Enable(void)
{
    /* Set Specific Interrupt Enable for INT2 */
    SetBit(GICR_Reg, INTF2);

    /* Configure sense control for INT2 */
    #if SenseControl_INT2 == SC_Choice_Low
        ClearBit(MCUCSR_Reg, ISC2_Bit);
    #elif SenseControl_INT2 == SC_Choice_Falling
        ClearBit(MCUCSR_Reg, ISC2_Bit);
    #elif SenseControl_INT2 == SC_Choice_Rising
        SetBit(MCUCSR_Reg, ISC2_Bit);
    #endif
}

/**
 * @fn mEXTI_Enable
 * @brief Enables all configured external interrupts
 * @return void
 * @note Only enables interrupts that are set to Enabled in configuration
 */
void mEXTI_Enable(void)
{
    #if INT0_Enable == Enabled
        mEXTI0_Enable();
    #endif

    #if INT1_Enable == Enabled
        mEXTI1_Enable();
    #endif

    #if INT2_Enable == Enabled
        mEXTI2_Enable();
    #endif
}

/**
 * @fn __vector_1
 * @brief External Interrupt INT0 ISR
 * @return void
 * @note This ISR calls the user-defined callback function
 * @warning Callback function must be set before interrupt occurs
 */
void __vector_1(void)
{
    if (mEXTI0_Global != Null)
    {
        mEXTI0_Global();
    }
}

/**
 * @fn __vector_2
 * @brief External Interrupt INT1 ISR
 * @return void
 * @note This ISR calls the user-defined callback function
 * @warning Callback function must be set before interrupt occurs
 */
void __vector_2(void)
{
    if (mEXTI1_Global != Null)
    {
        mEXTI1_Global();
    }
}

/**
 * @fn __vector_3
 * @brief External Interrupt INT2 ISR
 * @return void
 * @note This ISR calls the user-defined callback function
 * @warning Callback function must be set before interrupt occurs
 */
void __vector_3(void)
{
    if (mEXTI2_Global != Null)
    {
        mEXTI2_Global();
    }
}

#endif /* EXTI_Driver */