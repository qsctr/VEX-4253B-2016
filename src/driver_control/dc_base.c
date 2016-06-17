void dc_base() {

    if (dc_base_enabled) {

	    int x = vexRT[Ch4], y = vexRT[Ch3], r = vexRT[Ch1] / 2;

	    motor[FL] = + y + x + r;
	    motor[FR] = + y - x - r;
	    motor[BR] = + y + x - r;
	    motor[BL] = + y - x + r;

    }

}

void dc_base_toggle() {

    dc_base_enabled = !dc_base_enabled;
	if (!dc_base_enabled)
	    motor[FL] = motor[FR] = motor[BR] = motor[BL] = 0;

}
