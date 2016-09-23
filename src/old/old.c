// This file contains code for old prototype parts
// It is not meant to be compiled and run

// Tank tread intake
// To be executed in a loop

    motor[port6] = motor[port7] = vexRT[Btn7D] * 127;

// Scissor lift
// To be executed in a loop

    if (vexRT[Btn7U]) {
        motor[port6] = motor[port8] = 127;
    }
    if (vexRT[Btn7R]) {
        motor[port6] = motor[port8] = -127;
    }

// Switching between different prototype shooters

    #define DC_SHOOTER_MODE_NONE   0
    #define DC_SHOOTER_MODE_DIRECT 1
    #define DC_SHOOTER_MODE_SLIP   2
    #define DC_SHOOTER_MODE_KICKER 3
    #define DC_SHOOTER_MODE_OVER   4

    // To be executed on driver control initialization

    const string dc_shooter_mode_names[] = {"NONE  ", "DIRECT", "SLIP  ", "KICKER"};
    int dc_shooter_mode = DC_SHOOTER_MODE_DIRECT; // mode on startup

    // To be executed in a loop

    if (dc_shooter_mode == DC_SHOOTER_MODE_DIRECT) dc_shooter_direct();
    if (dc_shooter_mode == DC_SHOOTER_MODE_SLIP)   dc_shooter_slip();
    if (dc_shooter_mode == DC_SHOOTER_MODE_KICKER) dc_shooter_kicker();

    // To be executed when shooter mode should be changed

    shooter_set(0);
    dc_shooter_mode++;
    if (dc_shooter_mode == DC_SHOOTER_MODE_OVER)
        dc_shooter_mode = DC_SHOOTER_MODE_NONE;

    // To be executed on driver control initialization
    // and when shooter mode has changed

    displayLCDString(LCD_LINE_BOTTOM, DC_LCD_POS_SHOOTER, dc_shooter_mode_names[dc_shooter_mode]);

    // Direct drive
    // To be executed in a loop

    static const int lowerLimit = 305, upperLimit = 1821;

    if (SensorValue(ShooterPot) < upperLimit && vexRT[Btn5U])
        shooter_set(127);
    else if (SensorValue(ShooterPot) > lowerLimit && vexRT[Btn5D])
        shooter_set(-80);
    else
        shooter_set(0);

    // Slip gear
    // To be executed in a loop

    shooter_set(vexRT[Btn5D] * 80);

    // Kicker
    // To be executed in a loop

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
