#include "dc_common.c"
#include "dc_base.c"
#include "dc_shooter.c"
#include "dc_lcd.c"

task usercontrol() {

    dc_lcd_init();
#ifndef NATHAN_INTAKE
    dc_base_gyro_reset();
#endif

    while (true) {
#ifdef NATHAN_INTAKE
        motor[port6] = motor[port7] = vexRT[Btn7D] * 127;
#else
        dc_base();
        dc_shooter();
        dc_lcd();
       if (vexRT[Btn7U]) {
         motor[port6] = motor[port8] = 127;
       }
       if (vexRT[Btn7R]) {
         motor[port6] = motor[port8] = -127;
       }
#endif
    }

}
