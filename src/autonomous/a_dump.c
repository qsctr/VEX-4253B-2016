void a_dump_to(int height) {

    if (a_dump_pots_avg() == height)
        return;

    if (a_dump_pots_avg() > height) {
        dump_set(DUMP_UP);
        while (a_dump_pots_avg() > height);
    } else {
        dump_set(DUMP_DOWN);
        while (a_dump_pots_avg() < height);
    }
    dump_set(DUMP_HOLD);

}

void a_dump_to_ground(void) {

    a_dump_to(DUMP_HEIGHT_GROUND);
    dump_set(0);

}

int a_dump_pots_avg(void) {

    return (SensorValue(DumpPotL) + SensorValue(DumpPotR)) / 2;

}
