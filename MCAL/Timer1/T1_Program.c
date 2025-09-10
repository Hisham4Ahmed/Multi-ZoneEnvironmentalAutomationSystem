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
    //Compare Output Mode For OC1A and OC1B
    #if CompareOutputMode ==NonInverting
    Temp =NonInverting_BitMask;
    #elif CompareOutputMode ==Inverting
    Temp =Inverting_BitMask;
    #else 
    //Error Handle
    #endif
   /*
    Setting wave Gen to have FastPWM
        WGM13 WGM12  WGM11 WGM10 
          1     1       1   0   == 14 
   */ 
    SetBit(Temp,WGM11_Bit);
    ClearBit(Temp,WGM10_Bit);
    
    TCCR1A_Reg=Temp;

    //Setting TCCR1B_reg

    Temp=0;
    SetBit(Temp,WGM12_Bit);
    SetBit(Temp,WGM13_Bit);

    Temp&=Timer1_NoClkMask;
    Temp|=Timer1_Prescaller;
    TCCR1B_Reg=Temp;





    
}

void mTimer1_ChangeDutyCycle(uint8_t DutyCycle ,uint8_t Channel)
{
    
}
 


void mTimer1_FastPWMStop(uint8_t Channel)
{

}

void mTimer1_TimerStop(void)
{

}


#endif /* TIMER1_Driver */
