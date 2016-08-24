void dc_dump() {

    if (vexRT[Btn6U])
        dump_set(-127);
    else if (vexRT[Btn6D])
        dump_set(127);
    else if (vexRT[Btn5U])
        dump_set(-15);
    else
        dump_set(0);

}
