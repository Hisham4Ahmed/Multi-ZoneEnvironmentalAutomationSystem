/**
 * @file     EXTI_Private.h
 * @author   <Developer: Mohamed Diaa>
 * @author   <Reviewer:  Hozifah Ahmed>
 * @brief
 * @version   0.2
 * @date      2025-08-21
 * @copyright Copyright (c) 2025 , Gestell Company 
 */
 
#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_
/**
 * @def  ISC00  
 * @def  ISC01  
 * @def  ISC10  
 * @def  ISC11
 * @def  ISC2 
 * @brief Defining Bits in MCUCR and MCUCSR registers To use in choosing (ISC) Interrupt Sense Control Logic For INT0, INT1 and INT2
 */
//INT0
#define ISC00_Bit    0
#define ISC01_Bit    1
//INT1
#define ISC10_Bit    2
#define ISC11_Bit    3

//INT2
#define ISC2_Bit     6

/**
 * @def  INT0  
 * @def  INT1  
 * @def  INT2 
 * @brief Defining Bits in GIFR register To use in choosing (PIE) Peripheral Interrupt Enable For INT0 , INT1 and INT2 (Done by  program)
 */
#define INT1   7
#define INT0   6
#define INT2   5
/**
 * @def  INTF0  
 * @def  INTF1  
 * @def  INTF2  
 * @brief Defining Bits in GICR register To use in choosing (SIE) Specific Interrupt Enable For INT0 , INT1 and INT2
 */
#define INTF1   7
#define INTF0   6
#define INTF2   5

#endif /*_EXTI_PRIVATE_H_*/