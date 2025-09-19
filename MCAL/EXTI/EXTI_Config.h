/**
 * @file      EXTI_Config.h
 * @author    Dev. Mohammed Diaa (Mohammeddiaato@gmail.com)
 * @author    Rev. Hozifa Ahmed (hozifasedik@gmail.com)
 * @brief     Configuration settings for External Interrupts (EXTI).
 * @details   Contains user-configurable settings for EXTI sense control and interrupt enable/disable.
 * @version   0.2
 * @date      2025-08-21
 * @copyright Copyright (c) 2025 , Gestell Company
 */

#ifndef _EXTI_CONFIG_H_
#define _EXTI_CONFIG_H_

/**
 * @defgroup EXTI_Config EXTI Configuration
 * @brief User-configurable settings for External Interrupts
 * @{
 */

/**
 * @def SC_Choice_Low
 * @brief Low level sense control
 */
#define SC_Choice_Low        0

/**
 * @def SC_Choice_AnyChange
 * @brief Any logical change sense control
 */
#define SC_Choice_AnyChange  1

/**
 * @def SC_Choice_Falling
 * @brief Falling edge sense control
 */
#define SC_Choice_Falling    2

/**
 * @def SC_Choice_Rising
 * @brief Rising edge sense control
 */
#define SC_Choice_Rising     3

/**
 * @def SenseControl_INT0
 * @brief Sense control selection for INT0
 * @details Options:
 *          - SC_Choice_Low: Low level
 *          - SC_Choice_AnyChange: Any change
 *          - SC_Choice_Falling: Falling edge
 *          - SC_Choice_Rising: Rising edge
 */
#define SenseControl_INT0 SC_Choice_Falling

/**
 * @def SenseControl_INT1
 * @brief Sense control selection for INT1
 * @details Options:
 *          - SC_Choice_Low: Low level
 *          - SC_Choice_AnyChange: Any change
 *          - SC_Choice_Falling: Falling edge
 *          - SC_Choice_Rising: Rising edge
 */
#define SenseControl_INT1 SC_Choice_Low

/**
 * @def SenseControl_INT2
 * @brief Sense control selection for INT2
 * @details Options:
 *          - SC_Choice_Low: Low level
 *          - SC_Choice_Falling: Falling edge
 *          - SC_Choice_Rising: Rising edge
 * @note INT2 does not support AnyChange mode
 */
#define SenseControl_INT2 SC_Choice_Low

/**
 * @def INT0_Enable
 * @brief Enable/disable INT0 interrupt
 * @details Options:
 *          - Enabled: Enable INT0
 *          - Disabled: Disable INT0
 */
#define INT0_Enable Enabled

/**
 * @def INT1_Enable
 * @brief Enable/disable INT1 interrupt
 * @details Options:
 *          - Enabled: Enable INT1
 *          - Disabled: Disable INT1
 */
#define INT1_Enable Enabled

/**
 * @def INT2_Enable
 * @brief Enable/disable INT2 interrupt
 * @details Options:
 *          - Enabled: Enable INT2
 *          - Disabled: Disable INT2
 */
#define INT2_Enable Disabled

/** @} */ // End of EXTI_Config group

#endif /* _EXTI_CONFIG_H_ */