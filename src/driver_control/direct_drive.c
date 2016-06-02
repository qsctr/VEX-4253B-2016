void shooter() {

    int lowerLimit = 800;
    int upperLimit = 1100;

    if (SensorValue(Direct) < upperLimit && vexRT[Btn5U])
        set_shooter(127);
    else if (SensorValue(Direct) > lowerLimit && vexRT[Btn5D])
        set_shooter(-127);
    else
        set_shooter(0);

}
