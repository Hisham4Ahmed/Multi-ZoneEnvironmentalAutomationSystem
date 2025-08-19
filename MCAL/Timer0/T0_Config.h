/**
 * @file     T0_Config.h
 * @author   <Developer>
 * @author   <Reviewer>
 * @brief 
 * @version   0.1
 * @date      2025-08-15
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _T0_CONFIG_H_
#define _T0_CONFIG_H_

/* T0_Prescaller */
/*@def  
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
#define FastPWM_OutputType   Non_inverting
#define Timer0_InitDutyCycle  80
/*
*@param1 outputtype: determines whether the output type is (inverting or non inverting)
*@options : Non_inverting , inverting
*/
/*T0_CTC_Mode*/
#define CompareValue 250

#define Num_of_Compare_Match 1000
#define Prescalar_value 64
/*
*@brief These Macros are used to calculate the time that the timer works
*@clk time = 1/F_CPU =0.125*(10^-6)
*@devide your time on a number between 50~250 which gets you an integer
*@set the comparevalue to the divided by value (the value between 50~250)
*@set Num_of_Compare_Match to the division Result
*/

#endif /*_T0_CONFIG_H_*/