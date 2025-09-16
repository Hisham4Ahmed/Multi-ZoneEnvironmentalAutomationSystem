/**
 * @file    MULTIZONEAPP_Interface.h
 * @author  Mohammed Diaa    (mohammeddiaato@gmail.com)  Developer 
 * @author  Hesham Ahmed     (Hisham4Ahmed@gmail.com)    Reviewer   
 * @brief   This file introduce the APIs used in the Multizone APP
 * @version 0.1
 * @date    2025-09-16
 *
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _MULTIZONEAPP_INTERFACE_H_
#define _MULTIZONEAPP_INTERFACE_H_
/*Initialization
    - MultizoneApp_Init() shall:
        - Initialize all system modules in correct order: 
            - ModeControl_Init()
            - ZoneControl_Init() 
            - Communication_Init() 
            - LCDDisplay_Init()
        - Configure global interrupts if needed.
        - Set initial state (Mode = StartingMode). 
Superloop Execution
    - MultizoneApp_Run() shall contain the infinite loop.
    - In each loop iteration:
        - Call ModeControl_Task().
        - Call Communication_Task(). 
        - Call ZoneControl_Task().
        - Call LCDDisplay_Task().
    - Execution Order Rule:
        - ModeControl_Task() first → ensures current mode is updated.
        - Communication_Task() second → syncs data with mobile app.
        - ZoneControl_Task() third → applies Auto/Manual logic. 
        - LCDDisplay_Task() last → updates display for user feedback.
Responsibilities
    - Full App Task is the orchestrator (scheduler).
    - It does not implement business logic → that belongs to submodules.
    - It ensures tasks are called in the correct sequence for consistency. 
Error Handling
    - If a submodule fails to initialize, MultizoneApp_Init() shall handle it (safe state or retry).
    - If communication errors occur, system shall continue with last known state.*/




#endif /* _MULTIZONEAPP_INTERFACE_H_ */