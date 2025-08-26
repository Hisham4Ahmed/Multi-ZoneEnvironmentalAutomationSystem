/**
 * @file        DC_Program.c
 * @author      Developer: Mohamed Diaa "mohammeddiaato@gmail.com"
 * @author      Reviewer:    
 * @brief 
 * @version   0.2
 * @date      2025-08-15
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */
#include "DC_Interface.h"
/**
 * 
 */
void hFan_Init(uint8_t ZoneNumber)
{
    if(ZoneNumber==Zone1Num)
    {
        // timer zero
    }else if(ZoneNumber==Zone2Num)
    {
        // timer one
        
    }else if(ZoneNumber==Zone3Num)
    {
        // timer one
        
    }else if(ZoneNumber==Zone4Num)
    {
        // timer Two

    }else 
    {
        // handling Error
    }

    
}
void hFan_On(uint8_t ZoneNumber)
{
// need the pwm
    if(ZoneNumber==Zone1Num)
    {
        // timer zero
    }else if(ZoneNumber==Zone2Num)
    {
        // timer one
        
    }else if(ZoneNumber==Zone3Num)
    {
        // timer one
        
    }else if(ZoneNumber==Zone4Num)
    {
        // timer Two

    }else 
    {
        // handling Error
    }

}
void hFan_Off(uint8_t ZoneNumber)
{

//need the pwm
    if(ZoneNumber==Zone1Num)
    {
        // timer zero
    }else if(ZoneNumber==Zone2Num)
    {
        // timer one
        
    }else if(ZoneNumber==Zone3Num)
    {
        // timer one
        
    }else if(ZoneNumber==Zone4Num)
    {
        // timer Two

    }else 
    {
        // handling Error
    }
}