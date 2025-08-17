/**
 * @file     EXTI_Program.c
 * @author   <Developer>
 * @author   <Reviewer>
 * @brief 
 * @version   0.1
 * @date      2025-08-15
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */
#include "EXTI_Interface.h"
#include "../RegistersAddress.h"
#include "../../Common/Macro.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"
#include <stdint.h>

/**
 * 
 */

void mEXTI0_Enable()
{
    /**
     * SIE
     * PIE Done in the program
     * GICR
     */

} 

void mEXTI1_Enable()
{

} 

void mEXTI2_Enable()
{

} 

void mEXTI_EnableALLWanted() 
{
    #if INT0_Enable==1
        mEXTI0_Enable();
    #endif
    #if INT1_Enable==1
        mEXTI1_Enable();
    #endif
    #if INT2_Enable==1
        mEXTI2_Enable();
    #endif

}
void __vector_1(void) 
{

}
void __vector_2(void) 
{

}
void __vector_3(void) 
{

}
void mEXTI_DisableALL()
{

}
void mEXTI0_Disable()
{

} 
void mEXTI1_Disable()
{

} 
void mEXTI2_Disable()
{

} 
