/**
 * @file     ZoneControl_Interface.h
 * @author   Developer: Mohammed Atif   "medoatifatif@gmail.com"
 * @author   Reviewer:  Hesham Ahmed    (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version   0.1
 * @date      2025-08-15
 *
 * @copyright Copyright (c) 2025 , Gestell Company 
 */

#ifndef _ZONECONTROL_INTERFACE_H_
#define _ZONECONTROL_INTERFACE_H_

#include "../ModeControl/ModeControl_Interface.h"
#include "../../Common/ZoneConfig.h"
#include "../../HAL/LDR/LDR_Interface.h"
#include "../../HAL/LM35/LM35_Interface.h"

void ZoneControl_Init(void);
void ZoneControl_Task(void);

#endif /* _ZONECONTROL_INTERFACE_H_ */