void base_set(int fr, int br, int bl, int fl) {

    motor[BFR] = fr;
    motor[BBR] = br;
    motor[BBL] = bl;
    motor[BFL] = fl;

}

void base_set(int power) {

    base_set(power, power, power, power);

}
