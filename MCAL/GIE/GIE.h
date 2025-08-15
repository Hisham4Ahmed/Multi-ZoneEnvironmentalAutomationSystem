/**
 * @file     GIE.h
 * @author   Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @author   <Reviewer>
 * @brief 
 * @version   0.1
 * @date      2025-08-15
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#ifndef _GIE_H_
#define _GIE_H_

#include "../../Common/Macro.h"
#include "../RegistersAddress.h"


/**
 * @def   I_Bit 
 * @brief This Macro is Responsible for
 */
#define I_Bit   7 

/**
 * @def   mGIE_Enable 
 * @brief This Macro is Responsible for
 */
#define mGIE_Enable()          SetBit(SREG_Reg,I_Bit)

/**
 * @def   mGIE_Disable 
 * @brief This Macro is Responsible for 
 */
#define mGIE_Disable()         ClearBit(SREG_Reg,I_Bit)

#endif /*_GIE_H_*/