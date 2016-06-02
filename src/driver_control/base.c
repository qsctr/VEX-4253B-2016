void drive() {

    int x = vexRT[Ch4], y = vexRT[Ch3], r = vexRT[Ch1] / 2;

    motor[FL] = - y - x - r;
    motor[FR] = - y + x + r;
    motor[BR] = - y - x + r;
    motor[BL] = + y - x + r;

}
