#include "a_lcd.c"

void a_base(void);

void pre_auton() {

    bStopTasksBetweenModes = true;

}

task autonomous() {

    a_lcd_init();

    a_base();

    while (true) {
        a_lcd();
    }

}

void a_base() {
    motor[FL] = motor[FR] = motor[BL] = motor[BR] = 127;
    delay(1000);
    motor[FL] = motor[FR] = motor[BL] = motor[BR] = 0;
}
