void dc_shooter_direct(void);
void dc_shooter_slip(void);
void dc_shooter_kicker(void);

void dc_shooter() {

    if (dc_shooter_mode == DC_SHOOTER_MODE_DIRECT) dc_shooter_direct();
    if (dc_shooter_mode == DC_SHOOTER_MODE_SLIP)   dc_shooter_slip();
    if (dc_shooter_mode == DC_SHOOTER_MODE_KICKER) dc_shooter_kicker();

}

void dc_shooter_direct() {

    static const int lowerLimit = 305, upperLimit = 1821;

    if (SensorValue(ShooterPot) < upperLimit && vexRT[Btn5U])
        shooter_set(127);
    else if (SensorValue(ShooterPot) > lowerLimit && vexRT[Btn5D])
        shooter_set(-80);
    else
        shooter_set(0);

}

void dc_shooter_slip() {

    shooter_set(vexRT[Btn5D] * 80);

}

void dc_shooter_kicker() {

    static int prev = vexRT[Btn7U];
    static int step = 0;

    if (step == 0 && vexRT[Btn7U] > prev) {
        shooter_set(127);
	    step++;
    }
    if (step == 1 && SensorValue(ShooterPot) < 1200) {
        shooter_set(0); // this is necessary, don't delete this
        delay(500);
        shooter_set(-50);
        step++;
    }
    if (step == 2 && SensorValue(ShooterPot) > 1300) {
        shooter_set(0);
        step = 0;
    }

    prev = vexRT[Btn7U];

}

void dc_shooter_mode_next() {

    shooter_set(0);
    dc_shooter_mode++;
    if (dc_shooter_mode == DC_SHOOTER_MODE_OVER)
        dc_shooter_mode = DC_SHOOTER_MODE_NONE;

}
