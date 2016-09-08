#include "a_common.c"
#include "a_base.c"
#include "a_dump.c"
#include "a_lcd.c"

void pre_auton() {

    a_base_encoders_reset();

}

task autonomous() {

    startTask(a_lcd);

    a_base_backward();
    while (a_base_encoders_avg() < 100);
    a_base_stop();
    sleep(500);
    a_dump_to(DUMP_HEIGHT_LOW);
    a_base_encoders_reset();
    a_base_backward();
    dump_set(DUMP_UP);
    while (a_base_encoders_avg() < 700);
    a_base_stop();
    sleep(1000);
    a_dump_to_ground();

    //a_dump_to(DUMP_HEIGHT_LOW);
    //sleep(1000);
    //a_dump_to(DUMP_HEIGHT_MID);
    //sleep(1000);
    //a_dump_to(DUMP_HEIGHT_HIGH);
    //sleep(1000);
    //a_dump_to_ground();

}
