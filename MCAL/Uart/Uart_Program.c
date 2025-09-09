/**
 * @file     Uart_Program.c
 * @author   Developer: Naira Mohammed
 * @author   Reviewer: Ahmed Ashraf   
 * @brief    UART driver implementation for ATmega32.
 * @version   0.3
 * @date      (Created) 2025-08-19
 * @date      (Updated) 2025-09-09
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */
#include "../../Common/Config.h"
#if UART_Driver
#include "Uart_Interface.h"

/**
* @note this is a Global pointer to function to carry 
*       the PointerFunc called by ISR
*/
static void (*RxGlobal)(uint16_t Data)= Null;

void mUART_RxCallBack(void(*PointerFunc)(uint16_t Data))
{
	if (PointerFunc!=Null)
	{
		RxGlobal=PointerFunc;
	}
	else 
	{
		// Do Nothing
	}
	
}

 void mUART_Init()
 {
    uint8_t UCSRC_Temp=0;
    ClearBit(UCSRC_Temp,UMSEL_Bit);
    ClearBit(UCSRC_Temp,UCPOL_Bit);

    #if DataBits==Data5Bit
       ClearBit(UCSRC_Temp, UCSZ0_Bit);
       ClearBit(UCSRC_Temp, UCSZ1_Bit);
       ClearBit(UCSRB_Reg, UCSZ2_Bit);
    #elif DataBits==Data6Bit
       SetBit(UCSRC_Temp, UCSZ0_Bit);
       ClearBit(UCSRC_Temp, UCSZ1_Bit);
       ClearBit(UCSRB_Reg, UCSZ2_Bit);
    #elif DataBits==Data7Bit
       ClearBit(UCSRC_Temp, UCSZ0_Bit);
       SetBit(UCSRC_Temp, UCSZ1_Bit);
       ClearBit(UCSRB_Reg, UCSZ2_Bit);
    #elif DataBits==Data8Bit
       SetBit(UCSRC_Temp, UCSZ0_Bit);
       SetBit(UCSRC_Temp, UCSZ1_Bit);
       ClearBit(UCSRB_Reg, UCSZ2_Bit);
    #elif DataBits==Data9Bit
       SetBit(UCSRC_Temp, UCSZ0_Bit);
       SetBit(UCSRC_Temp, UCSZ1_Bit);
       SetBit(UCSRB_Reg, UCSZ2_Bit);
    #endif

    #if ParityMode==ParityDisable
       ClearBit(UCSRC_Temp,UPM0_Bit);
       ClearBit(UCSRC_Temp,UPM1_Bit);
    #elif ParityMode==ParityEven
       ClearBit(UCSRC_Temp,UPM0_Bit);
       SetBit(UCSRC_Temp,UPM1_Bit);
    #elif ParityMode==ParityOdd
       SetBit(UCSRC_Temp,UPM0_Bit);
       SetBit(UCSRC_Temp,UPM1_Bit);
    #endif

    #if StopBits==Stop1Bit
       ClearBit(UCSRC_Temp,USBS_Bit);
    #elif StopBits==Stop2Bit
       SetBit(UCSRC_Temp,USBS_Bit);
    #endif

    #if UARTSpeed==NormalSpeed
            ClearBit(UCSRA_Reg,U2X_Bit);
    #elif UARTSpeed==DoubleSpeed
            SetBit(UCSRA_Reg,U2X_Bit);
    #endif

    if(UBRR_Value<=255)
        {
            UBRRL_Reg=UBRR_Value;
        }
        else if (UBRR_Value>255)
        {
            UBRRL_Reg = UBRR_Value; 
            UBRRH_Reg = (UBRR_Value>>8); 
        }

    if (TranceiverMode==Rx_Enable)
    {
      ClearBit(UCSRB_Reg,TXEN_Bit);
      SetBit(UCSRB_Reg,RXEN_Bit);     
    }
    else if (TranceiverMode==Tx_Enable)
    {
      SetBit(UCSRB_Reg,TXEN_Bit);
      ClearBit(UCSRB_Reg,RXEN_Bit);     
    }
    else if (TranceiverMode==Rx_Tx_Enable)
    {
      SetBit(UCSRB_Reg,TXEN_Bit);
      SetBit(UCSRB_Reg,RXEN_Bit);     
    }
    
    ClearBit(UCSRB_Reg,RXCIE_Bit);
    ClearBit(UCSRB_Reg,TXCIE_Bit);
    ClearBit(UCSRB_Reg,UDRIE_Bit);

    SetBit(UCSRC_Temp, URSEL_Bit);
    UCSRC_Reg = UCSRC_Temp;
 };

void mUART_Transmit (uint16_t TxData)
{
   while(GetBit(UCSRA_Reg, UDRE_Bit)==0);
      #if DataBits==Data9Bit
      uint8_t NinthBit = GetBit(TxData, 8);
         if (NinthBit==0)
         {
            ClearBit(UCSRB_Reg, TXB8_Bit);
         }
         else if (NinthBit==1)
         {
            SetBit(UCSRB_Reg, TXB8_Bit);
         }
         UDR_Reg=(uint8_t)TxData;
      #else 
      UDR_Reg=/*(uint8_t)*/TxData;
      #endif

   while(GetBit(UCSRA_Reg,TXC_Bit)==0);
   SetBit(UCSRA_Reg,TXC_Bit);
} 

 uint16_t mUART_Receive_and_RxInterruptMode()
 {
   #if RxHandling==RxPolling
      while(GetBit(UCSRA_Reg, RXC_Bit)==0);
      uint16_t RxData=0;
      #if DataBits==Data9Bit
         uint8_t NinthBit = GetBit(UCSRB_Reg, RXB8_Bit);
         RxData = ((uint16_t)NinthBit << 8) | UDR_Reg;
      #else
         RxData = (uint8_t)UDR_Reg;
      #endif

      return RxData;
   #elif RxHandling==RxInterrupt
	SetBit(UCSRB_Reg, RXCIE_Bit);

   #endif
 }

void __vector_13(void)
{
   uint16_t RxData = 0;

   #if DataBits==Data9Bit
      uint8_t NinthBit = GetBit(UCSRB_Reg, RXB8_Bit);
      RxData = ((uint16_t)NinthBit << 8) | UDR_Reg;
   #else
      RxData = UDR_Reg;
   #endif

    RxGlobal(RxData);
}

#endif /* UART_Driver */