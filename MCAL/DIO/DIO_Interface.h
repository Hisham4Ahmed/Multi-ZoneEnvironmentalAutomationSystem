/**
 * @file     DIO_Interface.h
 * @author   <Hozifa Ahmed>
 * @author   <Reviewer>
 * @brief 
 * @version   0.2
 * @date      2025-08-20
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_
#include <stdint.h>

#define GroupA   1
#define GroupB   2
#define GroupC   3
#define GroupD   4

#define Pin0       0
#define Pin1       1
#define Pin2       2
#define Pin3       3
#define Pin4       4
#define Pin5       5
#define Pin6       6
#define Pin7       7


#define DIO_Input  0
#define DIO_Output 1

#define DIO_Low    0
#define DIO_High   1


void DIO_Direction_Pin(uint8_t GroupName , uint8_t PinNumber , uint8_t DirectionState);
void DIO_Write_Pin(uint8_t GroupName ,  uint8_t PinNumber , uint8_t OutputType);
uint8_t DIO_Read_Pin(uint8_t  GroupName, uint8_t PinNumber);



void DIO_Direction_Group(uint8_t GroupName , uint8_t DirecationValue);
void DIO_Write_Group(uint8_t GroupName ,  uint8_t OutputValue);
uint8_t DIO_Read_Group(uint8_t  GroupName);







#endif /*_DIO_INTERFACE_H_*/
