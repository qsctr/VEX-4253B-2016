void shooter_direct(void);
void shooter_slip(void);
void shooter_kicker(void);
void shooter_set(int x);

void shooter() {

    if (shooter_mode == SHOOTER_MODE_DIRECT) shooter_direct();
    if (shooter_mode == SHOOTER_MODE_SLIP)   shooter_slip();
    if (shooter_mode == SHOOTER_MODE_KICKER) shooter_kicker();

}

void shooter_direct() {

    static const int lowerLimit = 800;
    static const int upperLimit = 1100;

    if (SensorValue(ShooterPot) < upperLimit && vexRT[Btn5U])
        shooter_set(127);
    else if (SensorValue(ShooterPot) > lowerLimit && vexRT[Btn5D])
        shooter_set(-127);
    else
        shooter_set(0);

}

void shooter_slip() {

    shooter_set(vexRT[Btn5D] * 80);

}

void shooter_kicker() {

    shooter_set((vexRT[Btn5D] - vexRT[Btn5U]) * 127);

}

void shooter_set(int x) {

    motor[S1] = motor[S2] = motor[S3] = motor[S4] = x;

}

void shooter_mode_next() {

    shooter_set(0);
    shooter_mode++;
    if (shooter_mode == SHOOTER_MODE_OVER)
        shooter_mode = SHOOTER_MODE_NONE;
    bMotorReflected[S2] = bMotorReflected[S4] = shooter_mode != SHOOTER_MODE_KICKER;

}
