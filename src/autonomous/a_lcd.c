task a_lcd() {

    lcd_clear();
    displayLCDString(LCD_LINE_BOTTOM, 10, "AUTO");
    bLCDBacklight = true;

    while (1) {
	    lcd_voltage();
	    wait1Msec(1000);
    }

}
