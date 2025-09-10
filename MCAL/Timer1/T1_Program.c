/**
 * @file T1_Program.c
 * @author Mohammed Diaa    (mohammeddiaato@gmail.com)  Developer 
 * @author Hesham Ahmed     (Hisham4Ahmed@gmail.com)    Reviewer
 * @brief  This File is made for implementing The APIs in Interface.h
 * @version 0.3
 * @date 2025-08-30
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */
#include "../../Common/Config.h"
#if TIMER1_Driver

#include "T1_Interface.h"

void mTimer1_InitFastPWMMode(void)
{
    uint8_t Temp=0;
    //Compare Output Mode
    #if CompareOutputMode ==NonInverting
    Temp =NonInverting_BitMask;
    #elif CompareOutputMode ==Inverting
    Temp =Inverting_BitMask;
    #else 
    //Error Handle
    #endif
    
    Temp =0x


    
}

void mTimer1_ChangeDutyCycle(uint8_t DutyCycle ,uint8_t)
{
    
}
 


void mTimer1_FastPWMStop(void)
{

}

void mTimer1_TimerStop(void)
{

}


#endif /* TIMER1_Driver */
