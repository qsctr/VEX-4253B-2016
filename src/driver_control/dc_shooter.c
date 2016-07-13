void dc_shooter() {

    static int prev_l = 0, prev_r = 0;

    if (!prev_l && vexRT[Btn7L])
        motor[port6] = motor[port7] = -80;
    if (!prev_r && vexRT[Btn7R])
        motor[port6] = motor[port7] = 80;
    if ((prev_l && !vexRT[Btn7L]) || (prev_r && !vexRT[Btn7R]))
        motor[port6] = motor[port7] = 0;

    prev_l = vexRT[Btn7L];
    prev_r = vexRT[Btn7R];

}
