void pre_auton() {

    bStopTasksBetweenModes = true;

}

task autonomous() {

    lcd_init_auto();

    while (true) {
        lcd_auto();
    }

}
