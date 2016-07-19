#include "dc_common.c"
#include "dc_base.c"
#include "dc_shooter.c"
#include "dc_lcd.c"
#include "dc_lift.c"

task usercontrol() {

    dc_lcd_init();

    while (true) {
        dc_base();
        dc_shooter();
        dc_lcd();
        dc_lift();
    }

}
