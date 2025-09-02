/**
 * @file T1_Program.c
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
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

    TCCR2_Temp &=ClearPrescallerbitsOnlyMask;
    TCCR2_Temp |=Timer2_Prescaller;

    TCCR2_Reg=TCCR2_Temp;

 
}

void mTimer2_ChangeDutyCycle(uint8_t DutyCycle );


void mTimer2_FastPWMStop(void);



#endif /* TIMER2_Driver */