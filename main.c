#include "HAL/LCD/LCD_Interface.h"
#include "HAL/HC05/HC05_Interface.h"
#include "HAL/LED/LED_Interface.h"
#include "MCAL/Uart/Uart_Interface.h"
#include "MCAL/GIE/GIE.h"
#include <util/delay.h>
#include <string.h>
#include <stdio.h>

#define MAX_STRING 32

int main(void)
{
    mGIE_Enable();
    hLCD_Init();
    hHC05_Init();
    DIO_Direction_Group(GroupC, 0xFF);   // all PortC pins as output
    DIO_Write_Group(GroupC, 0x00);

  

    // === Boot Menu ===
    hLCD_SetInstruction(LCD_CLEAR_DISPLAY);
    hLCD_WriteString("HC05 Ready...");
    _delay_ms(1000);

    hLCD_SetInstruction(LCD_CLEAR_DISPLAY);
    hLCD_WriteString("Cmds:");
    hLCD_MoveCursor(1,0);
    hLCD_WriteString("LED1 LED2 ALL");
     uint8_t Rec_data ;
    while (1)
    {
        /*
        if(Last_string!=RxBuffer)
       {
        _delay_ms(200);
        hHC05_ReceiveString(RxBuffer, MAX_STRING);
         // Clear LCD and show received string
        hLCD_SetInstruction(LCD_CLEAR_DISPLAY);
        hLCD_WriteString("Recv:");
        hLCD_WriteString((char*)RxBuffer);
        _delay_ms(2000);
        // === Command parser ===
        if (strstr((char*)RxBuffer, "LED1") != NULL) {
            DIO_Toggle_Pin(GroupC, Pin0);
            hLCD_SetInstruction(LCD_CLEAR_DISPLAY);
            hLCD_WriteString("Toggled LED1");
        }
        else if (strstr((char*)RxBuffer, "LED2") != NULL) {
            DIO_Toggle_Pin(GroupC, Pin2);
            hLCD_SetInstruction(LCD_CLEAR_DISPLAY);
            hLCD_WriteString("Toggled LED2");
        }
        else if (strstr((char*)RxBuffer, "ALLON") != NULL) {
            DIO_Write_Pin(GroupC, Pin0, DIO_High);
            DIO_Write_Pin(GroupC, Pin2, DIO_High);
            hLCD_SetInstruction(LCD_CLEAR_DISPLAY);
            hLCD_WriteString("All LEDs ON");
        }
        else if (strstr((char*)RxBuffer, "ALLOFF") != NULL) {
            DIO_Write_Pin(GroupC, Pin0, DIO_Low);
            DIO_Write_Pin(GroupC, Pin2, DIO_Low);
            hLCD_SetInstruction(LCD_CLEAR_DISPLAY);
            hLCD_WriteString("All LEDs OFF");
        }
        else {
            hLCD_SetInstruction(LCD_CLEAR_DISPLAY);
           
        }

        _delay_ms(1000);

        // Re-display the menu after each command
        for(uint8_t i=0; Last_string[i]!=NullChar;i++)
        {
        Last_string[i]=RxBuffer[i];
        }
        hLCD_SetInstruction(LCD_CLEAR_DISPLAY);
        hLCD_WriteString("Cmds:");
        hLCD_MoveCursor(1,0);
        hLCD_WriteString("LED1 LED2 ALL");
        */
       hHC05_ReceiveChar(&Rec_data);
       switch (Rec_data)
       {
            case '1': 
            DIO_Toggle_Pin(GroupC,Pin0);
            hLCD_WriteString("Led 1 is Working Properly");
            break;

            case'2': 
            DIO_Toggle_Pin(GroupC,Pin2);
            hLCD_WriteString("Led 2 is Working Properly");
            break;
            case 'a':
                DIO_Toggle_Pin(GroupC,Pin0);            
                DIO_Toggle_Pin(GroupC,Pin2);

                _delay_ms(1000);
                 DIO_Toggle_Pin(GroupC,Pin0);            
                 DIO_Toggle_Pin(GroupC,Pin2);
                 hLCD_WriteString("All Leds Are Working Properly");
                 break;

                 default:
                  break;

       }
       _delay_ms(2000);
       hLCD_SetInstruction(LCD_CLEAR_DISPLAY);
    }

}

