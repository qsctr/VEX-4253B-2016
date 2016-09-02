void base_set(int fr, int br, int bl, int fl) {

    motor[FR] = fr;
    motor[BR] = br;
    motor[BL] = bl;
    motor[FL] = fl;

}

void base_set(int power) {

    base_set(power, power, power, power);

}
