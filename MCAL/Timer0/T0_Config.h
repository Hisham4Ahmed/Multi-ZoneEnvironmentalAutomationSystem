/**
 * @file     T0_Config.h
 * @author   Ahmed Ashraf
 * @author   Mohamed Atif
 * @brief 
 * @version   0.1
 * @date      2025-08-15
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _T0_CONFIG_H_
#define _T0_CONFIG_H_

/* T0_Prescaller */
/** 
*@def  
 *@brief prescaller defining and options are the following :
 1-Timer0Disabled               
 2-Timer0Prescaller_1           
 3-Timer0Prescaller_8           
 4-Timer0Prescaller_64           
 5-Timer0Prescaller_256         
 6-Timer0Prescaller_1024         
 6-Timer0ExternalCLK_Falling	
 7-Timer0ExternalCLK_Rising     

 */
#define TimerPrescaller0             Timer0Prescaller_64
/*----------------------------------------------------*/

/*T0_FastPWM_Mode*/

/**
 * @def FastPWM_OutputType
 * @brief determines the output type and the options are
            1-inverting
            2-Non_inverting
 */
#define FastPWM_OutputType   Non_inverting
/**
 * @def Timer0_InitDutyCycle
 * @brief presents the percentage of the value of the signal transmitted in Fast PWM
 */
#define Timer0_InitDutyCycle  80


/*T0_CTC_Mode*/

/** 
*@brief These Macros are used to calculate the time that the timer works
*@details :
clk time = 1/F_CPU =0.125*(10^-6)
devide your time on a number between 50~250 which gets you an integer
set the comparevalue to the divided by value (the value between 50~250)
set Num_of_Compare_Match to the division Result
*/

/**
 * @def CompareValue 
 * @brief number of clocks must be spent before the flag is set
 */
#define CompareValue 250
/**
 * @def Num_of_Compare_Match
 * @brief Number of times the timer flag must be set 
 */
#define Num_of_Compare_Match 1000



#endif /*_T0_CONFIG_H_*/