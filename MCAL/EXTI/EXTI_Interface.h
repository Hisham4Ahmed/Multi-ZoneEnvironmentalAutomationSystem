/**
 * @file      EXTI_Interface.h
 * @author    Dev. Mohammed Diaa (Mohammeddiaato@gmail.com)
 * @author    Rev. Hozifa Ahmed (hozifasedik@gmail.com)
 * @brief     Public interface for External Interrupt (EXTI) driver.
 * @details   Provides APIs for enabling external interrupts and interrupt service routines.
 * @version   0.2
 * @date      2025-08-17
 * @copyright Copyright (c) 2025 , Gestell Company
 */

#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_

/**
 * @defgroup EXTI_Driver EXTI Driver
 * @brief APIs for External Interrupt configuration and handling
 * @{
 */

/**
 * @fn mEXTI0_Enable
 * @brief Enables the External Interrupt INT0
 * @return void
 * @note Configures sense control based on SenseControl_INT0 setting
 */
void mEXTI0_Enable(void);

/**
 * @fn mEXTI1_Enable
 * @brief Enables the External Interrupt INT1
 * @return void
 * @note Configures sense control based on SenseControl_INT1 setting
 */
void mEXTI1_Enable(void);

/**
 * @fn mEXTI2_Enable
 * @brief Enables the External Interrupt INT2
 * @return void
 * @note Configures sense control based on SenseControl_INT2 setting
 */
void mEXTI2_Enable(void);

/**
 * @fn mEXTI0_CallBack
 * @brief Sets callback function for INT0 interrupt
 * @param PF Pointer to callback function
 * @return void
 * @warning Callback function must not be NULL
 */
void mEXTI0_CallBack(void (*PF)(void));

/**
 * @fn mEXTI1_CallBack
 * @brief Sets callback function for INT1 interrupt
 * @param PF Pointer to callback function
 * @return void
 * @warning Callback function must not be NULL
 */
void mEXTI1_CallBack(void (*PF)(void));

/**
 * @fn mEXTI2_CallBack
 * @brief Sets callback function for INT2 interrupt
 * @param PF Pointer to callback function
 * @return void
 * @warning Callback function must not be NULL
 */
void mEXTI2_CallBack(void (*PF)(void));

/**
 * @fn mEXTI_Enable
 * @brief Enables all configured external interrupts
 * @return void
 * @note Only enables interrupts that are set to Enabled in configuration
 */
void mEXTI_Enable(void);

/**
 * @fn __vector_1
 * @brief External Interrupt INT0 ISR
 * @return void
 * @note This ISR calls the user-defined callback function
 */
void __vector_1(void) __attribute__((signal));

/**
 * @fn __vector_2
 * @brief External Interrupt INT1 ISR
 * @return void
 * @note This ISR calls the user-defined callback function
 */
void __vector_2(void) __attribute__((signal));

/**
 * @fn __vector_3
 * @brief External Interrupt INT2 ISR
 * @return void
 * @note This ISR calls the user-defined callback function
 */
void __vector_3(void) __attribute__((signal));

/** @} */ // End of EXTI_Driver group

#endif /* _EXTI_INTERFACE_H_ */