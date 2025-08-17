/**
 * @file     EXTI_Config.h
 * @author   <Developer: Mohamed Diaa>
 * @author   <Reviewer>
 * @brief
 * @version   0.1
 * @date      2025-08-15
 *
 * @copyright Copyright (c) 2025 , Gestell Company
 */

#ifndef _EXTI_CONFIG_H_
#define _EXTI_CONFIG_H_



/**
 * @def SenseControl_Low
 * @def SenseControl_AnyChange
 * @def SenseControl_Falling
 * @def SenseControl_Rising
 * @brief Configuring SenseControl Logic Conditions for Each ISR
 */

#define SenseControl_Low        0
#define SenseControl_AnyChange  1
#define SenseControl_Falling    2
#define SenseControl_Rising     3
/**
 * @def SenseControl_INT0
 * @def SenseControl_INT1
 * @def SenseControl_INT2
 * @brief Configuring SenseControl value for Each ISR
 */

#define SenseControl_INT0 SenseControl_Low
#define SenseControl_INT1 SenseControl_Low
#define SenseControl_INT2 SenseControl_Low

/**
 * @def INT0_Enable
 * @def INT1_Enable
 * @def INT2_Enable
 * @brief Configuring what pins to enable of Interrupt peripherals I can Use
 */
#define INT0_Enable Enable
#define INT1_Enable Enable 
#define INT2_Enable Disable

#endif