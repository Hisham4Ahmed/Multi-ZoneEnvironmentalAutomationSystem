/**
 * @file     Uart_Program.c
 * @author   Naira Mohammed
 * @author   Ahmed Ashraf
 * @brief 
 * @version   0.2
 * @date      2025-08-19
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */
#include "../../Common/Config.h"
#if UART_Driver

#include "Uart_Interface.h"
#include "../../Common/Macro.h"
#include "../RegistersAddress.h"

/**
* @note this is a Global pointer to function to carry 
*       the PointerFunc called by ISR
*/
static void (*RxGlobal)(uint16_t Data)= Null;

/**
 * @brief A callback function to be executed when UART receives data.
 *
 * @note This function sets callback function that will be called 
 *       when the UART receive complete interrupt occurs. It also enables the 
 *       corresponding interrupt.
 *
 * @param PointerFunc A pointer to the callback function. 
 *        must not be NULL, otherwise no action will be taken.
 */
void USART_RxCallBack(void(*PointerFunc)(uint16_t Data))
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

/**
 * @fn this function will initialize USART
 *     1) Mode select
 *     2) Frame format
 *     3) Speed
 *     4) Baud Rate
 *     5) Tranceiver mode
 *     6) Interrupt disable
 *    it will be in polling mode   
 */
 void USART_Init()
 {
    /**
     * @note 1)Mode select -> Asynchronization
     *         * clear UMSEL_Bit in UCSRC_Reg
     *         * clear clock polarity bit (UCPOL_Bit) in UCSRC
     */
    uint8_t UCSRC_Temp=0;
    ClearBit(UCSRC_Temp,UMSEL_Bit);
    ClearBit(UCSRC_Temp,UCPOL_Bit);
    /**
     * @note 2)Frame format
     *         * char size 
     *         * Parity mode
     *         * Stop Bits 
     */

     /**
      * Char size
      * 5-bit size ->
      *   UCSZ0_Bit in UCSRC = 0
      *   UCSZ1_Bit in UCSRC = 0
      *   UCSZ2_Bit in UCSRB = 0
      * 6-bit size ->
      *   UCSZ0_Bit in UCSRC = 1
      *   UCSZ1_Bit in UCSRC = 0
      *   UCSZ2_Bit in UCSRB = 0
      * 7-bit size ->
      *   UCSZ0_Bit in UCSRC = 0
      *   UCSZ1_Bit in UCSRC = 1
      *   UCSZ2_Bit in UCSRB = 0
      * 8-bit size ->
      *   UCSZ0_Bit   in   UCSRC = 1
      *   UCSZ1_Bit   in   UCSRC = 1
      *   UCSZ2_Bit   in   UCSRB = 0
      * 9bit size ->
      *   UCSZ0_Bit   in   UCSRC = 1
      *   UCSZ1_Bit   in   UCSRC = 1
      *   UCSZ2_Bit   in   UCSRB = 1
      */
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
     /**
       * Parity Mode
       * Disabled ->
       *   UPM0_Bit in UCSRC = 0
       *   UPM1_Bit in UCSRC = 0
       *
       * Even Parity ->
       *   UPM0_Bit in UCSRC = 0
       *   UPM1_Bit in UCSRC = 1
       *
       * Odd Parity ->
       *   UPM0_Bit in UCSRC = 1
       *   UPM1_Bit in UCSRC = 1
       */
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
     /**
       * Stop Bits
       * 1 Stop Bit ->
       *   USBS_Bit in UCSRC = 0
       * 2 Stop Bits ->
       *   USBS_Bit in UCSRC = 1
       */
    #if StopBits==Stop1Bit
       ClearBit(UCSRC_Temp,USBS_Bit);
    #elif StopBits==Stop2Bit
       SetBit(UCSRC_Temp,USBS_Bit);
    #endif
    /**
     * 3) speed select 
     *    *Normal mode: 
     *         Clear U2X bit in UCSRA register to 0
     *    *Double Speed: 
     *         Set U2X bit in UCSRA register to 1
     */
    #if USARTSpeed==NormalSpeed
            ClearBit(UCSRA_Reg,U2X_Bit);
    #elif USARTSpeed==DoubleSpeed
            SetBit(UCSRA_Reg,U2X_Bit);
    #endif
    /**
     * 4) setting baud rate into UBRR register
     * UBRR register has a size of 16 bits
     *    if UBRR value has a size lower than or equal to 1111 1111 (255), it will be stored in UBRRL 
     *    if the value is greater, the first 8 bits in UBRRL wil be completed 
     *       then the second [9:16]bits will be stored in UBRRH
     */
    if(UBRR_Value<=255)
        {
            UBRRL_Reg=UBRR_Value;
        }
        else if (UBRR_Value>255)
        {
            UBRRL_Reg = UBRR_Value; 
            UBRRH_Reg = (UBRR_Value>>8); 
        }
    /**
     * 5) Tranceiver mode 
     *    *Tx enable: 
     *         Set TXEN bit in UCSRB register to 1
     *         Clear RXEN bit in UCSRB register to 0
     *    *Rx enable: 
     *         Clear TXEN bit in UCSRB register to 0
     *         Set RXEN bit in UCSRB register to 1
     *    *Tx or Rx enable: 
     *         Set TXEN bit in UCSRB register to 1
     *         Set RXEN bit in UCSRB register to 1
     */
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
    /**
     * 6) Disable Interrupt
           * Disable For RX complete interrupt (RXCIE) - > 0 in UCSRB
           * Disable For Tx complete interrupt (TXCIE) - > 0 in UCSRB
           * Disable For UDR empty interrupt (UDRIE) - > 0 in UCSRB
     */
    ClearBit(UCSRB_Reg,RXCIE_Bit);
    ClearBit(UCSRB_Reg,TXCIE_Bit);
    ClearBit(UCSRB_Reg,UDRIE_Bit);
    /**
     * @note should set URSEL bit in UCSRC to choose to write in UCSRC 
     *       instead of UBRRH
     */
    SetBit(UCSRC_Temp, URSEL_Bit);
    UCSRC_Reg = UCSRC_Temp;
 };

/**
 * @fn This function transmits data using USART communication protocol.
 *
 * @param TxData  Data to be transmitted (5, 6, 6, 7, 8 or 9 bits depending on configuration).
 *
 * @note Pseudo Code:
 *       1) Wait until UDR register is empty (UDRE) in (UCSRA) register.
 *       2) Check Char Size (5, 6, 7, 8 or 9 bits).
 *       3) Write data to UDR register.
 *       4) Wait until TX complete flag (TCX bit) is set in (UCSRA) register.
 *       5) Clear TX complete flag (TXC bit) by setting it to 1.
 */



void USART_Transmit (uint16_t TxData)
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

/**
 * @fn This function receives data using USART communication protocol.
 *
 * @note Pseudo Code:
 *       1) check Rx Handling mode (polling  or interrupt)
 *         if polling: 
 *                    1) wait until data is received (RXC flag in UCSRA)
 *                    2) read data from UDR register
 *         if interrupt
 *                    1) ISR will be executed by call back function
 */

 uint16_t USART_Receive()
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

 /**
  * @note the following is the ISR for RX complete interrupt, with a vector number of 13.
  *         * Automatically executed when a new frame is received
 *          * Reads UDR and Stores the received data through the callback function.  
 * -        * Clears the RX Complete Interrupt Enable bit (RXCIE) after execution.  
 */

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
    ClearBit(UCSRB_Reg, RXCIE_Bit);
}

#endif /* UART_Driver */