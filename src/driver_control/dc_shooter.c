void dc_shooter_direct(void);
void dc_shooter_slip(void);
void dc_shooter_kicker(void);

void dc_shooter() {

    if (dc_shooter_mode == DC_SHOOTER_MODE_DIRECT) dc_shooter_direct();
    if (dc_shooter_mode == DC_SHOOTER_MODE_SLIP)   dc_shooter_slip();
    if (dc_shooter_mode == DC_SHOOTER_MODE_KICKER) dc_shooter_kicker();

}

void dc_shooter_direct() {

    static const int lowerLimit = 553, upperLimit = 1563;

    if (SensorValue(ShooterPot) < upperLimit && vexRT[Btn5U])
        shooter_set(127);
    else if (SensorValue(ShooterPot) > lowerLimit && vexRT[Btn5D])
        shooter_set(-127);
    else
        shooter_set(0);

}

void dc_shooter_slip() {

    shooter_set(vexRT[Btn5D] * 80);

}

void dc_shooter_kicker() {

    // shooter_set((vexRT[Btn5D] - vexRT[Btn5U]) * 127);

    static int prev = vexRT[Btn7U];
    static int step = 0;

    switch (step) {
        case 0: if (vexRT[Btn7U] > prev) {
	        shooter_set(-50);
	        step++;
	        clearTimer(TIMER_SHOOTER);
	    }
        case 1: if (/* SensorValue(ShooterPot) > 2300 */ time1[TIMER_SHOOTER] > 500) {
            shooter_set(50);
            step++;
        }
        case 2: if (/* SensorValue(ShooterPot) < 700 */ time1[TIMER_SHOOTER] > 1000) {
            shooter_set(0);
            step = 0;
        }
    }

    prev = vexRT[Btn7U];

}

void dc_shooter_mode_next() {

    shooter_set(0);
    dc_shooter_mode++;
    if (dc_shooter_mode == DC_SHOOTER_MODE_OVER)
        dc_shooter_mode = DC_SHOOTER_MODE_NONE;
    bMotorReflected[S2] = bMotorReflected[S4] = dc_shooter_mode != DC_SHOOTER_MODE_KICKER;

}
