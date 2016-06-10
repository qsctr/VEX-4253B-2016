void base() {

    if (base_enabled) {

	    int x = vexRT[Ch4], y = vexRT[Ch3], r = vexRT[Ch1] / 2;

	    motor[FL] = - y - x - r;
	    motor[FR] = - y + x + r;
	    motor[BR] = - y - x + r;
	    motor[BL] = + y - x + r;

    }

}

void base_toggle() {

    base_enabled = !base_enabled;
	if (!base_enabled)
	    motor[FL] = motor[FR] = motor[BR] = motor[BL] = 0;

}
