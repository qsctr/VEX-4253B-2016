void shooter_direct(void);
void shooter_slip(void);
void shooter_set(int x);

void shooter() {

    if (shooter_mode == SHOOTER_MODE_DIRECT) shooter_direct();
    if (shooter_mode == SHOOTER_MODE_SLIP)   shooter_slip();

}

void shooter_direct() {

    static const int lowerLimit = 800;
    static const int upperLimit = 1100;

    if (SensorValue(DirectPot) < upperLimit && vexRT[Btn5U])
        shooter_set(127);
    else if (SensorValue(DirectPot) > lowerLimit && vexRT[Btn5D])
        shooter_set(-127);
    else
        shooter_set(0);

}

void shooter_slip() {

    shooter_set(vexRT[Btn5D] * 127);

}

void shooter_set(int x) {

    motor[S1] = motor[S2] = motor[S3] = motor[S4] = x;

}

void shooter_stop() {

    shooter_set(0);

}
