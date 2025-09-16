/**
 * @file    MULTIZONEAPP_Program.c
 * @author  Mohammed Diaa    (mohammeddiaato@gmail.com)  Developer 
 * @author  Hesham Ahmed     (Hisham4Ahmed@gmail.com)    Reviewer   
 * @brief   This file implement the APIs used in the Multizone APP
 * @version 0.2
 * @date    2025-09-16
 *
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#include"MultiZoneApp_Interface.h"

/*Initialization
    - MultizoneApp_Init() shall:
        - Initialize all system modules in correct order: 
            - ModeControl_Init()
            - ZoneControl_Init() 
            - Communication_Init() 
            - LCDDisplay_Init()
        - Configure global interrupts if needed. done by mode control 
        - Set initial state (Mode = StartingMode).  */
 
        
void MultizoneApp_Init()
{
    ModeControl_Init();
    ZoneControl_Init();
    Communication_Init();
    LCDDisplay_Init();
}
        
/** 
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
void MultizoneApp_Run()
{
while (1)
{
    ModeControl_Task();
    ZoneControl_Task();
    Communication_Task();
    LCDDisplay_Task();
}

}