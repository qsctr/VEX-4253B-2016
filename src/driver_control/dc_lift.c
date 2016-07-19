void dc_lift() {

	static int prev_l = 0, prev_r = 0;

    if (!prev_l && vexRT[Btn7L])
        lift_set(-80);
    if (!prev_r && vexRT[Btn7R])
        lift_set(80);
    if ((prev_l && !vexRT[Btn7L]) || (prev_r && !vexRT[Btn7R]))
       	lift_set(0);

    prev_l = vexRT[Btn7L];
    prev_r = vexRT[Btn7R];

}
