/**
 * @file     ZoneControl_Interface.h
 * @author   Developer: Mohammed Atif   "medoatifatif@gmail.com"
 * @author   Reviewer:  Hesham Ahmed    (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version   0.1
 * @date      2025-09-14
 *
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _ZONECONTROL_INTERFACE_H_
#define _ZONECONTROL_INTERFACE_H_

// ZoneControl is the only module allowed to control actuators (Relay, LED, Fan). so no includes

void ZoneControl_Init(void);
void ZoneControl_Task(void);

#endif /* _ZONECONTROL_INTERFACE_H_ */