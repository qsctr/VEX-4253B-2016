void dc_shooter() {

    static int prev_u = 0, prev_d = 0;

    if (!prev_u && vexRT[Btn8U])
        shooter_set(-127);
    if (!prev_d && vexRT[Btn8D])
        shooter_set(127);
    if ((prev_u && !vexRT[Btn8U]) || (prev_d && !vexRT[Btn8D]))
       	shooter_set(0);

    prev_u = vexRT[Btn8U];
    prev_d = vexRT[Btn8D];


}
