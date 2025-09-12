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
#include "../../Common/Config.h"

#if TIMER0_Driver

#include "T0_Interface.h"



void T0_FastPWM_Mode_Init()
{
	// remember that fast pwm must be initialized with complete config at the same time so better is to make a temporarily variable
	uint8_t TCCR0_Temp = 0;

	// to enable fast pwm we need to set WGM00 & WGM01 TO 1
	SetBit(TCCR0_Temp, WGM00_Bit);
	SetBit(TCCR0_Temp, WGM01_Bit);

	if (FastPWM_OutputType == Non_inverting)
	{
		// COM00 -> 0 & COM01 -> 1
		ClearBit(TCCR0_Temp, COM00_Bit);
		SetBit(TCCR0_Temp, COM01_Bit);
	}
	else if (FastPWM_OutputType == inverting)
	{
		// COM00 -> 1 & COM01 -> 1
		SetBit(TCCR0_Temp, COM00_Bit);
		SetBit(TCCR0_Temp, COM01_Bit);
	}

	mTimer0_ChangeDutyCycle(Timer0_InitDutyCycle, FastPWM_OutputType);
	// Prescaller
	// Set PreScaller to Enable the Timer0
	TCCR0_Temp &= 248;
	TCCR0_Temp |= TimerPrescaller0;

	TCCR0_Reg = TCCR0_Temp;
}

void mTimer0_ChangeDutyCycle(uint8_t DutyCycle, uint8_t ActionType)
{
	uint8_t CompareValue_PWM = 0;

	if (ActionType == Non_inverting)
	{
		// Compare Low on OC0 & Top High on OC0-> nin-inverting
		//  Compare Value = (2^n * DutyCycle)/100
		CompareValue_PWM = (uint8_t)((255.0 * (double)DutyCycle) / 100.0);
	}
	else if (ActionType == inverting)
	{
		// Compare High on OC0 & Top Low On OC0 > inverting
		// Compare Value = 2^n*(1-DutyCycle/100)
		CompareValue_PWM = (uint8_t)(255.0 * (1.0 - (double)DutyCycle / 100.0));
	}
	OCR0_Reg = CompareValue_PWM;
}


#endif /* TIMER0_Driver */

/*--------------------------*/