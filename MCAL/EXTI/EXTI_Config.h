/**
 * @file     EXTI_Config.h
 * @author   <Developer: Mohamed Diaa>
 * @author   <Reviewer:  Hozifah Ahmed>
 * @brief
 * @version   0.2
 * @date      2025-08-21
 *
 * @copyright Copyright (c) 2025 , Gestell Company
 */

#ifndef _EXTI_CONFIG_H_
#define _EXTI_CONFIG_H_



/**
 * @def SC_Choice_Low
 * @def SC_Choice_AnyChange
 * @def SC_Choice_Falling
 * @def SC_Choice_Rising
 * @brief Configuring SenseControl Logic Conditions for Each ISR
 */

#define SC_Choice_Low        0
#define SC_Choice_AnyChange  1
#define SC_Choice_Falling    2
#define SC_Choice_Rising     3
/**
 * @def SenseControl_INT0
 * @def SenseControl_INT1
 * @def SenseControl_INT2
 * @brief Configuring SenseControl value for Each ISR
 */

#define SenseControl_INT0 SC_Choice_Falling
#define SenseControl_INT1 SC_Choice_Low
#define SenseControl_INT2 SC_Choice_Low

/**
 * @def INT0_Enable
 * @def INT1_Enable
 * @def INT2_Enable
 * @brief Configuring what pins to enable of Interrupt peripherals I can Use
 */
#define INT0_Enable Enabled
#define INT1_Enable Enabled 
#define INT2_Enable Disabled

#endif