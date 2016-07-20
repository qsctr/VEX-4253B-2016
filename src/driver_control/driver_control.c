#include "dc_common.c"
#include "dc_base.c"
// #include "dc_shooter.c"
#include "dc_dump.c"
#include "dc_lcd.c"

task usercontrol() {

    dc_lcd_init();

    while (true) {
        dc_base();
        // dc_shooter();
        dc_dump();
        dc_lcd();
        sleep(20);
    }

}
