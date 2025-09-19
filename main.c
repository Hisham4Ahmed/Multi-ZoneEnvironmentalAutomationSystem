/**
 * @mainpage    Multi-ZoneEnvironmentalAutomationSystem Project 
 * @file        main.c
 * @author      Hesham Ahmed    Hisham4Ahmed@gmail.com
 * @author      Mohammed Diaa   Mohammeddiaato@gmail.com
 * @author      Naira Mohammed  naira.mohammed.76@gmail.com
 * @author      Mohammed Atif   medoatifatif@gmail.com
 * @author      Hozifa Ahmed    hozifasedik@gmail.com
 * @author      Ahmed Ashraf    ahmedashraf2022222@gmail.com
 * @brief       Create a system to automate environment control across multiple zones (e.g., two rooms) using sensors and actuators for each zone.
 * @version     0.1
 * @date        2025-09-19
 * @copyright   Copyright (c) 2025 ,Gestell Company
 * 
 */
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/HC05/HC05_Interface.h"
#include "MCAL/Uart/Uart_Interface.h"
#include "MCAL/GIE/GIE.h"
#include <util/delay.h>

int main () 
{
    MultizoneApp_Init();

    while(1)
    {
         MultizoneApp_Run();
    }
    
}