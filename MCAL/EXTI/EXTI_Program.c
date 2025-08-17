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
/*----------------------------------------------*/
/**
 * @brief       Enabling the EXTI peripheral Configured in config.h
 * @param       [no parameters]
 * @return      None
 */
void mEXTI_EnableALLWanted()
{
#if INT0_Enable == 1
    mEXTI0_Enable();
#endif
#if INT1_Enable == 1
    mEXTI1_Enable();
#endif
#if INT2_Enable == 1
    mEXTI2_Enable();
#endif
}
/*----------------------------------------------*/
/**
 * @brief       Disable All the External Interrupts
 * @param       [no parameters]
 * @return      None
 */
void mEXTI_DisableALL()
{
    // SIE disable
    ClearBit(GICR_Reg, INTF0);
    ClearBit(GICR_Reg, INTF1);
    ClearBit(GICR_Reg, INTF2);
    
}
/*----------------------------------------------*/

/**
 * @brief       Disable the External Interrupt INT0
 * @param       [no parameters]
 * @return      None
 */
void mEXTI0_Disable()
{
        ClearBit(GICR_Reg, INTF0);
    
    
}
/*----------------------------------------------*/

/**
 * @brief       Disable the External Interrupt INT1
 * @param [no parameters]
 * @return      None
 */
void mEXTI1_Disable()
{
    
        ClearBit(GICR_Reg, INTF1);
}
/*----------------------------------------------*/
/**
 * @brief       Disable the External Interrupt INT2
 * @param [no parameters]
 * @return      None
 */
void mEXTI2_Disable()
{
    
        ClearBit(GICR_Reg, INTF2);
}
/*----------------------------------------------*/


/*---------------------------------------Waiting LDR-------------------------*/
/**
 * @brief External Interrupt( INT0) ISR
 * @param [no parameters]
 * @return Void
 */
void __vector_1(void)
{
    //action when LDR is finished
/**
 * @brief External Interrupt( INT0) ISR
 * @param [no parameters]
 * @return Void
 */
}
/*----------------------------------------------*/
/**
 * @brief External Interrupt( INT1) ISR
 * @param [no parameters]
 * @return Void
 */
void __vector_2(void)
{
        //action when LDR is finished

}
/*----------------------------------------------*/
/**
 * @brief External Interrupt( INT2) ISR
 * @param [no parameters]
 * @return Void
 */
void __vector_3(void)
{
        //action when LDR is finished

}
/*----------------------------------------------*/