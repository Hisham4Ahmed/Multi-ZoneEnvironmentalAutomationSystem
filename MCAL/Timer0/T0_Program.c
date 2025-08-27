/**
 * @file     T0_Program.c
 * @author   Ahmed Ashraf
 * @author   Mohamed Atif
 * @brief 
 * @version   0.1
 * @date      2025-08-15
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

 #include "T0_Interface.h"


 void T0_CTC_Mode_Init()
 {
    /* Set the timer mode to CTC-> WGM01=1 and WGM00=0 */
    SetBit(TCCR0_Reg,WGM01_Bit);
    ClearBit(TCCR0_Reg,WGM00_Bit);
    
    OCR0_Reg = CompareValue;
    // we need to enable interrupt for compare match -> OCIE0=1
    SetBit(TIMSK_Reg,OCIE0_Bit);
 // we need to select the pre-scalar -> TCCR0_Reg &=0b11111000 don't affect the other bits , Timer0 | prescalar value
 // to choose the prescaller change the (TimerPrescaller) from the interface to whatever prescaller you want 
 TCCR0_Reg &=248;
 TCCR0_Reg |= (TimerPrescaller0) ;
 }

 
 /*from Vector Table Bring the vector Number & write the ISR-> 10 */
void __vector_10(void)
 {
static uint32_t Counts_of_CompareMatch = 0;
Counts_of_CompareMatch++;
if (Counts_of_CompareMatch ==Num_of_Compare_Match)
{
    
if (TIMER0_PF!=NULL)
{
	TIMER0_PF();
}

    Counts_of_CompareMatch = 0;
}

}
void T0_FastPWM_Mode_Init()
{
    //remember that fast pwm must be initialized with complete config at the same time so better is to make a temporarily variable
    uint8_t TCCR0_Temp = 0;

// to enable fast pwm we need to set WGM00 & WGM01 TO 1
SetBit(TCCR0_Temp,WGM00_Bit);
SetBit(TCCR0_Temp,WGM01_Bit);

if (FastPWM_OutputType == Non_inverting)
{
// COM00 -> 0 & COM01 -> 1
ClearBit(TCCR0_Temp,COM00_Bit);
SetBit(TCCR0_Temp,COM01_Bit);
}
else if (FastPWM_OutputType == inverting)
{
// COM00 -> 1 & COM01 -> 1
SetBit(TCCR0_Temp,COM00_Bit);
SetBit(TCCR0_Temp,COM01_Bit);
}

 mTimer0_ChangeDutyCycle(Timer0_InitDutyCycle,FastPWM_OutputType);
// Prescaller
		// Set PreScaller to Enable the Timer0
		TCCR0_Temp &= 248;
		TCCR0_Temp |= TimerPrescaller0;

		TCCR0_Reg = TCCR0_Temp;

}


void mTimer0_ChangeDutyCycle(uint8_t DutyCycle,uint8_t ActionType )
{
	uint8_t CompareValue_PWM = 0 ;

	if(ActionType==Non_inverting)
	{
		// Compare Low on OC0 & Top High on OC0-> nin-inverting
	//  Compare Value = (2^n * DutyCycle)/100
		CompareValue_PWM = (256 * DutyCycle) / 100;
	}
	else if (ActionType==inverting)
	{
		// Compare High on OC0 & Top Low On OC0 > inverting
		// Compare Value = 2^n*(1-DutyCycle/100)
		CompareValue_PWM= 256 * (1-DutyCycle/100.0);
	}
	OCR0_Reg = CompareValue_PWM;

}

static void (*TIMER0_PF)(void)=NULL;

void T0_Call_Back_fn(void(*PF)(void))
{
	if(PF!=NULL)
	{
		TIMER0_PF=PF;
	}

else 
{
// do nothing
}
}

 