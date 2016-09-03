/*

Example autonomous LCD screen

|   7.20 VOLTS   |
|   AUTONOMOUS   |

*/

task a_lcd() {

    lcd_clear();
    displayLCDCenteredString(LCD_LINE_BOTTOM, "AUTONOMOUS");
    bLCDBacklight = true;

    while (1) {
	    lcd_voltage();
	    wait1Msec(1000);
    }

}
