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
#ifndef NATHAN_INTAKE
        dc_base();
        dc_shooter();
        dc_lcd();
#endif
#ifdef NATHAN_INTAKE
        motor[port6] = motor[port7] = vexRT[Btn7D] * 127;
#endif
    }

}
