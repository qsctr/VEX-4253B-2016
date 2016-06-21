#include "a_common.c"
#include "a_lcd.c"

void pre_auton() {

    // bStopTasksBetweenModes = true;

}

task autonomous() {

    a_lcd_init();

    while (true) {
        a_lcd();
    }

}
