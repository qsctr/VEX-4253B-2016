void dc_lift() {

    if (vexRT[Btn7U])
        lift_set(-127);
    else if (vexRT[Btn7D])
        lift_set(127);
    else
        lift_set(0);

}
