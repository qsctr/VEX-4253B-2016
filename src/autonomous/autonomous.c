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
    a_dump_to(DUMP_HEIGHT_LOW);
    a_base_backward();
    dump_set(DUMP_UP);
    a_base_encoders_reset();
    while (a_base_encoders_avg() < 700);
    a_base_stop();
    a_dump_to(DUMP_HEIGHT_LOW);
    a_base_forward();
    a_base_encoders_reset();
    while (a_base_encoders_avg() < 100);
    a_base_rotate_left();
    a_base_encoders_reset();
    while (a_base_encoders_avg() < 190);
    a_base_stop();
    a_dump_to_ground();
    a_base_backward();
    a_base_encoders_reset();
    while (a_base_encoders_avg() < 300);
    a_base_stop();
    a_dump_to_ground();
    a_base_forward();
    a_base_encoders_reset();
    while (a_base_encoders_avg() < 400);
    a_base_stop();
    a_dump_to(DUMP_HEIGHT_MID);

    //a_dump_to(DUMP_HEIGHT_LOW);
    //sleep(1000);
    //a_dump_to(DUMP_HEIGHT_MID);
    //sleep(1000);
    //a_dump_to(DUMP_HEIGHT_HIGH);
    //sleep(1000);
    //a_dump_to_ground();

}
