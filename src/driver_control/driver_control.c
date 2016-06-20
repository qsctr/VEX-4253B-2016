#include "dc_common.c"
#include "dc_base.c"
#include "dc_shooter.c"
#include "dc_lcd.c"

task usercontrol() {

    dc_lcd_init();
    //dc_base_gyro_reset();

    while (true) {
        //dc_base();
        //dc_shooter();
        //dc_lcd();

        // for nathan
        motor[port6] = motor[port7] = vexRT[Btn7D] * 127;
    }

}
