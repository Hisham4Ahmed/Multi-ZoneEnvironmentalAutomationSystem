/**
 * @file     LCD_Config.h
 * @author   Developer : Ahmed Ashraf
 * @author   Reviewer  : Mohamed Diaa
 * @brief    This Driver is to set and operate LCD Screen 2*16
 * @version   0.1
 * @date      2025-08-24
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


 #include "LCD_Interface.h"

#include <util/delay.h>

void hLCD_Init () 
{
    /* Set LCD Pins as Output */
    DIO_Direction_Pin(LCD_E_Group , LCD_E_Pin , DIO_Output);
    DIO_Direction_Pin(LCD_D4_Group , LCD_D4_Pin , DIO_Output);
    DIO_Direction_Pin(LCD_D5_Group , LCD_D5_Pin , DIO_Output);
    DIO_Direction_Pin(LCD_D6_Group , LCD_D6_Pin , DIO_Output);
    DIO_Direction_Pin(LCD_D7_Group , LCD_D7_Pin , DIO_Output);
    DIO_Direction_Pin(LCD_RS_Group , LCD_RS_Pin , DIO_Output);
    /* Wait for more than 30 ms after VCC rises to 4.5V */
    _delay_ms(35);
    
    /* Function Set: 4-bit mode */
    hLCD_SetInstruction(_8bit_Mode); // Initialize to 8-bit mode first
    _delay_ms(1); // Wait for more than 39 us
    hLCD_SetInstruction(_4bit_Mode); // Switch to 4-bit mode
     _delay_ms(1); // Wait for more than 39 us
    hLCD_SetInstruction(_2Line_Mode); // Function set: 4-bit, 2 lines, 5x8 dots
    
    /* Display ON/OFF Control: Display ON, Cursor OFF, Blink OFF */
    hLCD_SetInstruction(LCD_DISPLAY_ON);
    
    /* Clear Display */
    hLCD_SetInstruction(LCD_CLEAR_DISPLAY);
    
    /* Entry Mode Set: Increment cursor, no display shift */
    hLCD_SetInstruction(LCD_ENTRY_MODE);
    _delay_ms(2); // Wait for more than 1.53 ms
}

void hLCD_WriteByte(uint8_t Byte)
{
    // RS = 1 for data
    DIO_Write_Pin(LCD_RS_Group, LCD_RS_Pin, DIO_High);
DIO_Write_Pin(LCD_E_Group, LCD_E_Pin, DIO_High);
    _delay_us(1);
    // Send high nibble
    uint8_t Temp_Byte=Byte ;
    Temp_Byte&=Higher_Nibble_Mask;
    LCD_PORT&=Lower_Nibble_Mask;
    LCD_PORT|=Temp_Byte;
    // Pulse Enable
    
    DIO_Write_Pin(LCD_E_Group, LCD_E_Pin, DIO_Low);
    _delay_us(50);

    // Send low nibble
     DIO_Write_Pin(LCD_E_Group, LCD_E_Pin, DIO_High);
    _delay_us(1);

    Temp_Byte=Byte<<4;
    Temp_Byte&=Higher_Nibble_Mask;
    LCD_PORT&=Lower_Nibble_Mask;
    LCD_PORT|=Temp_Byte;

    // Pulse Enable again
   
    DIO_Write_Pin(LCD_E_Group, LCD_E_Pin, DIO_Low);
    _delay_us(50);

    _delay_ms(2); // Some commands need >1.53ms
}

void hLCD_SetInstruction(uint8_t Command)
{
    // RS = 0 for command
    DIO_Write_Pin(LCD_RS_Group, LCD_RS_Pin, DIO_Low);
DIO_Write_Pin(LCD_E_Group, LCD_E_Pin, DIO_High);
    _delay_us(1);
    // Send high nibble
    uint8_t Temp=Command ;
    Temp&=Higher_Nibble_Mask;
    LCD_PORT&=Lower_Nibble_Mask;
    LCD_PORT|=Temp;
    // Pulse Enable
    
    DIO_Write_Pin(LCD_E_Group, LCD_E_Pin, DIO_Low);
    _delay_us(50);

    // Send low nibble
     DIO_Write_Pin(LCD_E_Group, LCD_E_Pin, DIO_High);
    _delay_us(1);

    Temp=Command<<4;
    Temp&=Higher_Nibble_Mask;
    LCD_PORT&=Lower_Nibble_Mask;
    LCD_PORT|=Temp;

    // Pulse Enable again
   
    DIO_Write_Pin(LCD_E_Group, LCD_E_Pin, DIO_Low);
    _delay_us(50);

    _delay_ms(2); // Some commands need >1.53ms
}


void hLCD_WriteString(uint8_t *String)
{
    while (*String!= NullChar)
    {
        hLCD_WriteByte(*String++);
    }
}



void hLCD_WriteNumber(uint32_t number)
{
    uint8_t digits[10];   // Buffer to store digits (max for uint32_t is 10 digits)
    uint8_t index = 0;

    // Special case: if number is 0, just print '0'
    if (number == 0)
    {
        hLCD_WriteByte('0');
        return;
    }

    // Extract digits in reverse order
    while (number > 0 && index < 10)
    {
        uint8_t digit = number % 10;     // Get the last digit
        digits[index] = digit + '0';     // Convert to ASCII character
        index++;                         // Move to next position
        number /= 10;                    // Remove the last digit
    }

    // Print digits in the correct order
    while (index > 0)
    {
        index--;                         // Step back to last stored digit
        hLCD_WriteByte(digits[index]);   // Print digit
    }
}


void hLCD_MoveCursor(uint8_t Line, uint8_t Pos)
{
    uint8_t Address;
    if (Line == FirstLine)
    {
        Address = FirstLineAddress + Pos;
    }
    else if (Line == SecondLine)
    {
        Address = SecondLineAddress + Pos;
    }
    else
    {
        return; // Invalid line number
    }
    hLCD_SetInstruction(SetDDRAMCommand + Address);
    _delay_ms(2); // Wait for command to process
}

void hLCD_ClearFirstLine()
{
hLCD_SetInstruction(LCD_RETURN_HOME);   
    hLCD_WriteString("                "); // Write 16 spaces to clear the line
   
hLCD_SetInstruction(LCD_RETURN_HOME);

}

void hLCD_ClearSecondLine()
{
    hLCD_MoveCursor(SecondLine, 0);

        hLCD_WriteString("                "); // Write 16 spaces to clear the line


    hLCD_MoveCursor(SecondLine, 0); // Move cursor back to start of second line
    

}

/*---------------------------------------------------------*/
