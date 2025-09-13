/**
 * @file     HC05_Private.h
 * @author   Developer: Naira Mohammed (naira.mohammed.76@gmail.com)
 * @author   Reviewer: Ahmed Ashraf 
 * @brief    private definitions for HC05 Bluetooth module.
 * @version   0.2
 * @date      2025-09-03
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

 
#ifndef _HC05_PRIVATE_H_
#define _HC05_PRIVATE_H_

/**
 * @enum BufferState: this enum defines the 3 states of the ring buffer.
 * @var Empty
 * @brief indicates the buffer is empty, no data to be read.
 * 
 * 
 * @var Full
 * @brief indicates the buffer is full, no space to write new data.
 * 
 * 
 * @var PartiallyFull
 * @brief indicates the buffer has some data, space to write new data.
 * 
 * 
 */
enum BufferState {
    Empty,
    Full,
    PartiallyFull
};

#endif /*_HC05_PRIVATE_H_*/