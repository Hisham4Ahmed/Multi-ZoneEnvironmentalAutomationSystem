#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/Timer0/T0_Interface.h"
#include "MCAL/Timer1/T1_Interface.h"
#include "MCAL/Timer2/T2_Interface.h"
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
        T0_FastPWM_Mode_Init();
        mTimer1_InitFastPWMMode();
        mTimer2_InitFastPWMMode();
        hFan_On(Zone1Num);
        hFan_On(Zone2Num);
        hFan_On(Zone3Num);
        hFan_On(Zone4Num);
        _delay_ms(2000);
        while (1)
        {
        hFan_SpeedControl(Zone1Num,70);
        hFan_SpeedControl(Zone2Num,70);
        hFan_SpeedControl(Zone3Num,70);
        hFan_SpeedControl(Zone4Num,70);
        _delay_ms(2000);
        hFan_SpeedControl(Zone1Num,200);
        hFan_SpeedControl(Zone2Num,200);
        hFan_SpeedControl(Zone3Num,200);
        hFan_SpeedControl(Zone4Num,200);
        _delay_ms(2000);

        }
        
}