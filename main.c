#include "HAL/DC/DC_Interface.h"
#include "Common/Macro.h"
#include "Common/ZoneConfig.h"
#include <util/delay.h>
int main()
{
        hFan_Init(Zone1Num);
        hFan_Init(Zone2Num);
        hFan_Init(Zone3Num);
        hFan_Init(Zone4Num);
        while (1)
        {
        hFan_On(Zone1Num);
        hFan_On(Zone2Num);
        hFan_On(Zone3Num);
        hFan_On(Zone4Num);
        _delay_ms(2000);
        
        hFan_Off(Zone1Num);
        hFan_Off(Zone2Num);
        hFan_Off(Zone3Num);
        hFan_Off(Zone4Num);
        // hFan_SpeedControl(Zone1Num,70);
        // hFan_SpeedControl(Zone2Num,70);
        // hFan_SpeedControl(Zone3Num,70);
        // hFan_SpeedControl(Zone4Num,70);
        // hFan_SpeedControl(Zone1Num,200);
        // hFan_SpeedControl(Zone2Num,200);
        // hFan_SpeedControl(Zone3Num,200);
        // hFan_SpeedControl(Zone4Num,200);

        }
        
}