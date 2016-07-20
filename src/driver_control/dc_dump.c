void dc_dump() {

    if (vexRT[Btn7U])
        dump_set(-127);
    else if (vexRT[Btn7D])
        dump_set(127);
    else
        dump_set(0);

}
