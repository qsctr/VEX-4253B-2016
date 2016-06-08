#include "base.c"
#include "shooter.c"

task usercontrol() {

    lcd_init_driver();

    while (true) {
        base();
        shooter();
        lcd_driver();
    }

}
