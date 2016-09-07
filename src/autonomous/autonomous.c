#include "a_common.c"
#include "a_base.c"
#include "a_lcd.c"
#include "a_sub.c"

void pre_auton() {

    a_base_encoders_reset();

}

task autonomous() {

    startTask(a_lcd);

    release_intake();

}
