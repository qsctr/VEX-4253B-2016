void dc_dump() {

    if (vexRT[Btn6U])
        dump_set(DUMP_UP);
    else if (vexRT[Btn6D])
        dump_set(DUMP_DOWN);
    else if (vexRT[Btn5U])
        dump_set(DUMP_HOLD);
    else
        dump_set(0);

}
