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

static void (*mEXTI0_Global)(void)=NULL;
void mEXTI0_CallBack(void (*PF)(void))
{
    if (PF!=NULL)
    {
        mEXTI0_Global=PF;
    }
    else
    {
        
    }
    
}
static void (*mEXTI1_Global)(void)=NULL;
void mEXTI1_CallBack(void (*PF)(void))
{
    if (PF!=NULL)
    {
        mEXTI1_Global=PF;
    }
    else
    {
        
    }
    
}
static void (*mEXTI2_Global)(void)=NULL;
void mEXTI2_CallBack(void (*PF)(void))
{
    if (PF!=NULL)
    {
        mEXTI2_Global=PF;
    }
    else
    {
        
    }
    
}
/**
 * @brief       Enabling the External Interrupt INT0
 * @param       [no parameters]
 * @return      None
 */


void mEXTI0_Enable()
{
    // SIE
    SetBit(GICR_Reg, INTF0);

#if SenseControl_INT0 == 0

    ClearBit(MCUCR_Reg, ISC00_Bit);
    ClearBit(MCUCR_Reg, ISC01_Bit);
#elif SenseControl_INT0 == 1
    SetBit(MCUCR_Reg, ISC00_Bit);
    ClearBit(MCUCR_Reg, ISC01_Bit);
#elif SenseControl_INT0 == 2
    ClearBit(MCUCR_Reg, ISC00_Bit);
    SetBit(MCUCR_Reg, ISC01_Bit);
#elif SenseControl_INT0 == 3
    SetBit(MCUCR_Reg, ISC01_Bit);
    SetBit(MCUCR_Reg, ISC00_Bit);
#else
    // Handle Error
#endif
}
/*----------------------------------------------*/
/**
 * @brief       Enabling the External Interrupt INT1
 * @param       [no parameters]
 * @return      None
 */

void mEXTI1_Enable()
{
    // SIE
    SetBit(GICR_Reg, INTF1);

#if SenseControl_INT1 == 0

    ClearBit(MCUCR_Reg, ISC10_Bit);
    ClearBit(MCUCR_Reg, ISC11_Bit);
#elif SenseControl_INT1 == 1
    SetBit(MCUCR_Reg, ISC10_Bit);
    ClearBit(MCUCR_Reg, ISC11_Bit);
#elif SenseControl_INT1 == 2
    ClearBit(MCUCR_Reg, ISC10_Bit);
    SetBit(MCUCR_Reg, ISC11_Bit);
#elif SenseControl_INT1 == 3
    SetBit(MCUCR_Reg, ISC10_Bit);
    SetBit(MCUCR_Reg, ISC11_Bit);
#else
    // Handle Error
#endif
}
/*----------------------------------------------*/
/**
 * @brief       Enabling the External Interrupt INT2
 * @param       [no parameters]
 * @return      None
 */
void mEXTI2_Enable()
{
    // SIE
    SetBit(GICR_Reg, INTF2);

#if SenseControl_INT2 == 0
    ClearBit(MCUCSR_Reg, ISC2_Bit);
#elif SenseControl_INT2 == 1
    SetBit(MCUCSR_Reg, ISC2_Bit);

#else
    // Handle Error
#endif
}
void mEXTI_Enable()
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



/*---------------------------------------Waiting LDR-------------------------*/
/**
 * @brief External Interrupt( INT0) ISR
 * @param [no parameters]
 * @return Void
 */
void __vector_1(void)
{
    mEXTI0_Global();

}
/*----------------------------------------------*/
/**
 * @brief External Interrupt( INT1) ISR
 * @param [no parameters]
 * @return Void
 */
void __vector_2(void)
{
    mEXTI1_Global();

}
/*----------------------------------------------*/
/**
 * @brief External Interrupt( INT2) ISR
 * @param [no parameters]
 * @return Void
 */
void __vector_3(void)
{
    mEXTI2_Global();

}
/*----------------------------------------------*/