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

#define CS00_Bit  0
#define CS01_Bit  1
#define CS02_Bit  2

#define WGM01_Bit 3
#define WGM00_Bit 6

#define COM00_Bit 4
#define COM01_Bit 5

#define TOIE0_Bit   0
#define OCIE0_Bit   1

#define TOV0_Bit   0
#define OCF0_Bit   1

#define Non-inverting 1
#define inverting 2

/*-----------------------------------------------------------*/
#define Timer0Disabled               0
#define Timer0Prescaller_1           1
#define Timer0Prescaller_8           2
#define Timer0Prescaller_64          3
#define Timer0Prescaller_256         4
#define Timer0Prescaller_1024        5
#define Timer0ExternalCLK_Falling	 6
#define Timer0ExternalCLK_Rising 	 7

#endif /*_T0_PRIVATE_H_*/