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
 TCCR0_Reg &=248;
 TCCR0_Reg |= (Timer0Prescaller_64) ;
 }

 
 /*from Vector Table Bring the vector Number & write the ISR-> 10 */
void __vector_10(void) {
static uint32_t Counts_of_CompareMatch = 0;
Counts_of_CompareMatch++;
if (Counts_of_CompareMatch ==Num_of_Compare_Match)
{
    
    ToggleBit(PINA_Reg,0);
    // clear counts of compare match
    Counts_of_CompareMatch = 0;
}

}


 