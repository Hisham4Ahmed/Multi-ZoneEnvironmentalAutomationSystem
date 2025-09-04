/**
 * @file T1_Program.c
 * @author Mohammed Diaa Developer-> Mohammeddiaato@gmail.com
 * @author Hozifah Ahmed Reviwer  ->
 * @brief  This File is made for the implementation of the Functions in interface  
 * @version 0.1
 * @date 2025-08-30
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */


#include "../../Common/Config.h"
#if TIMER2_Driver

#include "T2_Interface.h"
#include "../../Common/Macro.h"
#include "../RegistersAddress.h"
#include <stdint.h>

void mTimer2_InitFastPWMMode()
{
	uint8_t TCCR2_Temp  = 0 ;
    //fast mode  1  1
      SetBit(TCCR2_Temp,WGM20_Bit);
      SetBit(TCCR2_Temp,WGM21_Bit);
      #if CompareOutputMode ==NonInverting
            ClearBit(TCCR2_Temp,COM20_Bit);
            SetBit(TCCR2_Temp,COM21_Bit);
            
    #elif CompareOutputMode ==Inverting
            SetBit(TCCR2_Temp,COM20_Bit);
            SetBit(TCCR2_Temp,COM21_Bit);

    #endif

    mTimer2_ChangeDutyCycle(initialDutyCycle);

    TCCR2_Temp &=Timer2_NoClkMask;
    TCCR2_Temp |=Timer2_Prescaller;

    TCCR2_Reg=TCCR2_Temp;

 
}

void mTimer2_ChangeDutyCycle(uint8_t DutyCycle )
{
    uint8_t CompareValue = 0 ;

    #if CompareOutputMode ==NonInverting
	
		CompareValue = (256 * DutyCycle) / 100; 
            
    #elif CompareOutputMode ==Inverting
            CompareValue= 256 * (1-DutyCycle/100);

    #endif
	
	OCR0_Reg = CompareValue;

}


void mTimer2_FastPWMStop(void)
{
        TCCR2_Reg&=Timer2_PWMStop;

}
void mTimer2_TimerStop(void)
{


    TCCR2_Reg &=Timer2_NoClkMask;
            


}



#endif /* TIMER2_Driver */