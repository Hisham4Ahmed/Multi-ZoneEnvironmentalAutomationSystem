/**
 * @file     Macro.h
 * @author   Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @author   <Reviewer>
 * @brief    
 * @version   0.1
 * @date      2025-08-15
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */


#ifndef _MACRO_H_
#define _MACRO_H_

/* Function Like Macro */
/**
 * @def   SetBit 
 * @brief This Macro is Responsible for 
 */
#define SetBit(Reg,Bit)                ((Reg)|=(1<<(Bit)))

/**
 * @def   ClearBit
 * @brief This Macro is Responsible for 
 */
#define ClearBit(Reg,Bit)              ((Reg)&=~(1<<(Bit)))

/**
 * @def   ToggleBit
 * @brief This Macro is Responsible for 
 */
#define ToggleBit(Reg,Bit)            ((Reg)^=(1<<(Bit)))

/**
 * @def   GetBit
 * @brief This Macro is Responsible for 
 */
#define GetBit(Reg,Bit)                (((Reg)>>(Bit))&0x01)

/**
 * @def    ClearFlag
 * @brief  This Macro is Responsible for 
 */
#define ClearFlag(Reg,FlagBit)         SetBit(Reg,FlagBit)

/**
 * @def    ClearFlag
 * @brief  This Macro is Responsible for 
 */
#define  ReadFlag(Reg,FlagBit)         GetBit(Reg,FlagBit)  

/*****************************************************************************************************************************************************/
/*Object Like Macro*/

/**
 * @def     Null 
 * @brief   This Macro is Responsible for
 */
#define Null        (void*)0

/**
 * @def     Null 
 * @brief   This Macro is Responsible for
 */
#define NullChar    '\0'


/**
 * @def     Input
 * @brief   This Macro is Responsible for
 * @def     Output
 * @brief   This Macro is Responsible for
 */
#define Input    0 
#define Output   1


/**
 * @def     Low
 * @brief   This Macro is Responsible for
 * @def     High
 * @brief   This Macro is Responsible for
 */
#define Low      0 
#define High     1

/**
 * @def     FlagDown
 * @brief   This Macro is Responsible for
 * @def     FlagUp
 * @brief   This Macro is Responsible for
 */
#define FlagDown   0 
#define FlagUp     1


#endif /* _MACRO_H_ */